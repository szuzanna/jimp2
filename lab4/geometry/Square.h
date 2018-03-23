//
// Created by Zuzanna on 23.03.2018.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H


#include <ostream>
#include "Point.h"

using geometry::Point;

namespace geometry{

    class Square{

    public:

        Square();

        Square(Point A, Point B, Point D, Point C);

        double Circumference() const;

        double Area() const;

    private:
        Point A_, B_, C_, D_;
    };

}


#endif //JIMP_EXERCISES_SQUARE_H
