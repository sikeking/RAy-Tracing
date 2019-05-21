
#ifndef ACCEL_H
#define ACCEL_H

#include <vector>

#include "figure.h"

class Accel{
    public:
        std::vector<std::shared_ptr<Figure> > figures;
        Accel(){}

        void add(std::shared_ptr<Figure> p){
            figures.push_back(p);
        }

        bool intersect(const Ray& ray, Hit& hit) const{
            bool isHit = false;

            hit.t = 10000000;

            Hit hit_each;
            for(auto p : figures){
                if(p->intersect(ray,hit_each)){
                    isHit = true;
                    if(hit_each.t < hit.t){
                        hit = hit_each;
                    }
                }
            }
            return isHit;
        }
};

#endif