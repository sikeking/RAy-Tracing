
#ifndef PLANE_H
#define PLANE_H

class Plane : public Figure{
    public:
        const Vec3 Base_Point;
        const Vec3 Normal_direction;
        const Vec3 color;
        const int material;

    Plane(const Vec3 Base_Point,const Vec3 Normal_direction,const Vec3 color, const int material):
        Base_Point(Base_Point),Normal_direction(Normal_direction),color(color),material(material){}

    bool intersect(const Ray& ray, Hit& hit) const override {
        if(dot(Normal_direction, ray.direction) == 0) return false;
        double t = dot(Normal_direction, Base_Point - ray.origin) / dot(Normal_direction, ray.direction);
        if(t < 0){
            return false;
        }else{
        hit.t = t;
        hit.hitPos = ray.origin + t*ray.direction;
        hit.hitNormal = normalize(Normal_direction);
        hit.hitColor = color;
        hit.hitMaterial = material;
        return true;
        }
    }
};


#endif
