
#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "ray.h"
#include "hit.h"
#include "figure.h"

class Sphere : public Figure {
    public:
        Vec3 center;
        double radius;
        const Vec3 color;
        const int material;

    Sphere(const Vec3& center, double radius, Vec3 color,const int material):
        center(center),radius(radius),color(color),material(material){}
    
    bool intersect(const Ray& ray,Hit& hit) const override{
        double a = ray.direction.length2();
        double b = 2 * dot(ray.direction,ray.origin-center);
        double c = (ray.origin - center).length2() - radius * radius;
        double D = b*b -4*a*c;

        double t1 = (-b-std::sqrt(D))/(2*a);
        double t2 = (-b+std::sqrt(D))/(2*a);

        double t;

        if(t1 >= 0){
            t = t1;
        }else if(t2 >= 0){
            t = t2;
        }else{
            return false;
        }

        hit.t = t;
        hit.hitPos = ray.origin + t*ray.direction;
        hit.hitNormal = normalize(hit.hitPos - center);
        hit.hitColor = color;
        hit.hitMaterial = material;
        return true;

    }
};

#endif