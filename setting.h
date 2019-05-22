
#ifndef SETTING_H
#define SETTING_H

#include <random>
#include <cmath>

#include "vec3.h"
#include "ray.h"
#include "hit.h"
#include "accel.h"

std::random_device dev_rnd;
std::mt19937 mt(dev_rnd());
std::uniform_real_distribution<> dist(0, 1);
double rnd() {
    return dist(mt);
}
Accel accel;
Vec3 lightDir = normalize(Vec3(-1,1,-1));

void orthonormalBasis(const Vec3& n, Vec3& x, Vec3& z) {
  if(n.x > 0.9) x = Vec3(0, 1, 0);
  else x = Vec3(1, 0, 0);
  x = x - dot(x, n)*n;
  x = normalize(x);
  z = normalize(cross(n, x));
}

Vec3 randomHemisphere(const Vec3& n) {
  double u = rnd();
  double v = rnd();
  
  double y = u;
  double x = std::sqrt(1 - u*u)*std::cos(2*M_PI*v);
  double z = std::sqrt(1 - u*u)*std::sin(2*M_PI*v);
  
  Vec3 xv, zv;
  orthonormalBasis(n, xv, zv);
  
  return x*xv + y*n + z*zv;
}

Vec3 getColor(const Ray& ray, int depth = 0) {
    //100回以上の反射は追跡しない
    if(depth > 100) return Vec3(0, 0, 0);

    Hit hit;
    if(accel.intersect(ray, hit)) {
        //if(depth > 100) return hit.hitColor;
        //Diffuse
        if(hit.hitMaterial == 0) {
            //Shadow Rayを生成
            //Ray shadowRay(hit.hitPos + 0.001*hit.hitNormal, lightDir);
            //Hit hit_shadow;
            Ray nextRay(hit.hitPos + 0.001*hit.hitNormal, randomHemisphere(hit.hitNormal));
            double cos_term = std::max(dot(nextRay.direction, hit.hitNormal), 0.0);
            return 2*M_PI * hit.hitColor/M_PI * cos_term * getColor(nextRay, depth + 1);
            //return hit.hitColor;
            //Shadow Rayが当たったら影をつける
            /*
            if(accel.intersect(shadowRay, hit_shadow)) {
                return Vec3(0, 0, 0);
            }
            else {
                double I = std::max(dot(lightDir, hit.hitNormal), 0.0);
                return I * hit.hitColor;
            }
            */
        }
        //Mirror
        else if(hit.hitMaterial == 1) {
            //反射レイを生成
            Ray reflectRay(hit.hitPos + 0.001*hit.hitNormal, reflect(ray.direction, hit.hitNormal));
            //反射レイを使って自分自身を呼び出す
            return getColor(reflectRay, depth + 1);
        }
    else {
        return Vec3(0, 0, 0);
    }
    }
    //空の色
    else {
        return Vec3(0.9, 0.9, 0.9);
    }
}




#endif