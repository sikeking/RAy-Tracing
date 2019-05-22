
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Figure{
    public:
        const Vec3 Point1;
        const Vec3 Point2;
        const Vec3 Point3;
        Vec3 Normal;
        const Vec3 color;
        const int material;

    Triangle(const Vec3& Point1,const Vec3& Point2,const Vec3& Point3, const Vec3& color, const int material):
        Point1(Point1),Point2(Point2),Point3(Point3),color(color),material(material){
            Normal = cross(Point2 - Point1,Point3 - Point1);
        }
    bool intersect(const Ray& ray, Hit& hit) const override {
        Vec3 e1 = Point2 - Point1;
        Vec3 e2 = Point3 - Point1;
        if (dot(cross(ray.direction, e2),e1) != 0){
            if(dot(cross(ray.direction, e2),ray.origin - Point1) >= 0 && dot(cross(ray.origin - Point1, e1),ray.direction) >= 0 &&
                dot(cross(ray.direction, e2),ray.origin - Point1) + dot(cross(ray.origin - Point1, e1),ray.direction) <= dot(cross(ray.direction, e2), e1)){
                    hit.t = dot(cross(ray.origin - Point1, e1), e2) / dot(cross(ray.direction, e2), e1);
                    hit.hitPos = ray.origin + hit.t*ray.direction;
                    hit.hitNormal = normalize(Normal);
                    hit.hitColor = color;
                    hit.hitMaterial = material;
                    return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    
};


#endif