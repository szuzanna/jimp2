//
// Created by Zuzanna on 23.03.2018.
//

#include "Square.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

namespace geometry {
    Square::Square() {
        cout << "Konstruktor bezparametrowy" << endl;
    }

    Square::Square(Point A, Point B, Point D, Point C) {
        cout << "Konstruktor parametrowy" << endl;
        if (A.Distance(C) != B.Distance(D) || A.Distance(B)!=D.Distance(A)) {
            A_.SetX(0);
            A_.SetY(0);
            B_.SetX(0);
            B_.SetY(0);
            C_.SetX(0);
            C_.SetY(0);
            D_.SetX(0);
            D_.SetY(0);
        } else {
            A_ = A;
            B_ = B;
            C_ = C;
            D_ = D;
        }
    }

    double Square::Circumference() const {
        return A_.Distance(B_) * 4;
    }

    double Square::Area() const {
        return pow(A_.Distance(B_), 2);
    }
}