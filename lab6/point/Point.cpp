//
// Created by Zuzanna on 13.04.2018.
//

#include "Point.h"
#include <iomanip>
#include <iostream>

using ::std::istream;
using ::std::ws;

void Point::SetY(double y) {
    y_ = y;
}

void Point::SetX(double x) {
    x_ = x;
}

double Point::getX() const {
    return x_;
}

double Point::getY() const {
    return y_;
}

//Helper functions:
void CheckNextChar(char c, istream *is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw std::runtime_error("invalid character");
    }
    is->ignore();
}

void IgnoreWhitespace(istream *is) {
    (*is) >> ws;
}

double ReadNumber(istream *is) {
    double d;
    (*is) >> d;
    return d;
}
// Właściwa definicja, obydwa argumenty funkcji nie
//są zadeklarowane jako const, bo obydwa są modyfikowane
//wewnątrz funkcji (STL nie używa naszej konwencji z przekazywaniem
//przez wskaźnik)
istream &operator>>(istream &input, Point &p) {
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}

std::ostream &operator<<(std::ostream &input, const Point &point) {
    input << "x:" << point.x_ << ", y:" << point.y_;
}

Point::~Point() {
    std::cout << "Deleted successfully" << std::endl;
}

Point::Point(double x, double y) {
    x_ = x;
    y_ = y;
}
