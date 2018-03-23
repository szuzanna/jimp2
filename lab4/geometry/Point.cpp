//
// Created by Zuzanna on 23.03.2018.
//

#include <cmath>
#include <ostream>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

namespace geometry {
    Point::Point() : x_(0), y_(0) {
        std::cout << "Konstruktor bezparametrowy" << endl;
    }

    Point::Point(double x, double y) {
        std::cout << "Konstruktor parametrowy" << endl;
        x_ = x;
        y_ = y;
    }

    Point::~Point() {
        std::cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
        std::cout << endl;
    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    void Point::ToString(ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    double Point::GetX() const{
        return x_ ;
    }

    double Point::GetY() const {
        return y_;
    }

    void Point::SetX(double x){
        x_ = x ;
    }

    void Point::SetY(double y){
        y_ = y;
    }
}