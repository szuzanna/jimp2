//
// Created by Zuzanna on 16.04.2018.
//
#include "Kula.h"
#include "Kolo.h"
#include <iostream>

using namespace std;
using namespace figury;

int main(){
    Kula k(0,0,0,10);
    Kolo &kolo = k;
    cout << k.pole();
}