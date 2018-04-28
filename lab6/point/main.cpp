//
// Created by Zuzanna on 13.04.2018.
//
#include <Point.h>
#include <sstream>

using std::cin;
using std::endl;
using std::cout;

int main(){
    Point p2;
    Point p1(3,9);
    std::stringstream ss;
    p2.SetX(3);
    p2.SetY(3);
    cin>>p2;
    ss << "(2,4)";
    ss>>p1;
    cout<<p2<<endl;
    cout<<p1<<endl;
}
