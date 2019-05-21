
#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

class Camera{
    public:
        Vec3 camPos;
        Vec3 camForward;
        Vec3 camRight;
        Vec3 camUp;
    Camera(const Vec3& camPos, const Vec3& camForward):
        camPos(camPos),camForward(camForward){
            camRight = -1*normalize(cross(camForward, Vec3(0, 1, 0)));
            camUp = normalize(cross(camForward, camRight));
        }
    Ray getRay(double u, double v) const {
        Vec3 pinhole = camPos + camForward;
        Vec3 sensorPos = camPos + u*camRight + v*camUp;
        return Ray(sensorPos,normalize(pinhole - sensorPos));
    }
};

#endif