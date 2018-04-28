//
// Created by Zuzanna on 16.04.2018.
//

#include "Kolo.h"

namespace figury {

    Kolo::Kolo(double x, double y, double r) {
        x_ = x;
        y_ = y;
        r_ = r;
    }

    double Kolo::pole(void) const {
        return (3.14*r_*r_);;
    }
}