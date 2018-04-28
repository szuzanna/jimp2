//
// Created by Zuzanna on 16.04.2018.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H

#include "Kolo.h"

namespace figury{
    class Kula: public Kolo{
    public:
        Kula(double x, double y, double z, double r): Kolo{x,y,r}, z_{z} {};
        double pole();

    private:
        double z_;
    };
}

#endif //JIMP_EXERCISES_KULA_H
