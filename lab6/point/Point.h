//
// Created by Zuzanna on 13.04.2018.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <iostream>
#include <exception>
#include <cmath>

class Point {
public:
    Point(double x=0, double y=0) ;
    ~Point();

    void SetX(double x);
    void SetY(double y);
    double getX() const;
    double getY() const;

    //opcjonalna definicja pozwalająca na uzyskanie
    //dostępu do prywatnych pól z wewnątrz definicji
    //funkcji zadeklarowanej poniżej
    friend std::istream& operator>>(std::istream &, Point&);
    friend std::ostream& operator<<(std::ostream &, const Point &);


private:
    double x_, y_;
};

//właściwa deklaracja, przeciążająca
//operator >> dla strumienia wejściowego
//i klasy punkt
std::istream &operator>>(std::istream &, Point &point);

std::ostream &operator<<(std::ostream &, const Point &point);

#endif //JIMP_EXERCISES_POINT_H
