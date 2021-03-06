
#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"

class Ellipse : public Figure {
    public:
        const Vec3 center;
        const Vec3 axis;
        const Vec3 color;
        const int material;

        Ellipse(const Vec3& center,const Vec3& axis,const Vec3& color,const int material):
            center(center),axis(axis),color(color),material(material){}
    
    bool intersect(const Ray& ray,Hit& hit) const override{
        double a = (ray.direction/axis).length2();
        double b = 2 * dot(ray.direction/axis,ray.origin-center);
        double c = (ray.origin - center).length2() - 1.0;
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
        hit.hitNormal = normalize((hit.hitPos-center)/(axis * axis));
        hit.hitColor = color;
        hit.hitMaterial = material;
        return true;

    }
};

#endif