
#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class Vec3{
    public:
        double x;
        double y;
        double z;
        //成分を定義
    Vec3(){
        x = y = z = 0;
    }
    Vec3(double x, double y, double z):x(x),y(y),z(z){
    }
    double length() const {
        return std::sqrt(x*x + y*y + z*z);
    }
    double length2() const{
        return x*x + y*y + z*z;
    }
    void print() const {
        printf("(%f, %f, %f)\n", x, y, z);
    }

};

Vec3 operator+(const Vec3& v,const Vec3& u){
    return Vec3(v.x + u.x, v.y + u.y, v.z + u.z);
}
Vec3 operator-(const Vec3& v,const Vec3& u){
    return Vec3(v.x - u.x, v.y - u.y, v.z - u.z);
}
Vec3 operator*(double k, const Vec3& v){
    return Vec3(k * v.x, k * v.y, k * v.z);
}
Vec3 operator*(const Vec3& v,double k){
    return Vec3(v.x * k,v.y * k,v.z * k);
}
Vec3 operator*(const Vec3& v,const Vec3& u){
    return Vec3(v.x * u.x,v.y * u.y,v.z * u.z);
}
Vec3 operator/(double k, const Vec3& v) {
    return Vec3(k / v.x, k / v.y, k / v.z);
}
Vec3 operator/(const Vec3& v, double k) {
    return Vec3(v.x / k, v.y / k, v.z / k);
}
Vec3 operator/(const Vec3& v, const Vec3& u) {
    return Vec3(v.x / u.x, v.y / u.y, v.z / u.z);
}

std::ostream& operator<<(std::ostream& stream, const Vec3& v) {
    stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}

double dot(const Vec3& v,const Vec3& u){
    return v.x * u.x + v.y * u.y + v.z * u.z;
}
Vec3 cross(const Vec3& v,const Vec3& u){
    return Vec3(v.y*u.z - v.z*u.y, v.z*u.x - v.x * u.z, v.x*u.y - v.y*u.x);
}
Vec3 normalize(const Vec3& v){
    return v / v.length();
}

#endif