
#ifndef FIGURE_H
#define FIGURE_H

#include "ray.h"
#include "hit.h"

class Figure{
    public:
        virtual bool intersect(const Ray& ray, Hit& hit) const = 0;
};


#endif