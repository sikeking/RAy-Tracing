
#ifndef IMAGE_H
#define IMAGE_H

#include "vec3.h"
#include <memory>
#include <iostream>
#include <fstream>

class Image{
    public:
        int width;
        int height;
        std::unique_ptr<Vec3[]> data;

    Image(int width, int height):width(width),height(height){
        data = std::make_unique<Vec3[]>(width*height);
    }

    Vec3 getPixel(int i, int j) const {
        return data[width*i + j];
    }
    void setPixel(int i, int j, const Vec3& color) const { 
        data[width*i + j] = color;
    }
    void ppm_output() const {
        std::ofstream file("output.ppm");
        
        file << "P3" << std::endl;
        file << width << " " << height << std::endl;
        file << "255" << std::endl;
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                Vec3 color = 255*this->getPixel(j, i);
                int r = (int)color.x;
                int g = (int)color.y;
                int b = (int)color.z;
                file << r << " " << g << " " << b << std::endl;
            }
        }
    }
};

#endif