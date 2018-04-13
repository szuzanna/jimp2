//
// Created by Zuzanna on 06.04.2018.
//

#include "XXX.h"

using ::std::swap;

//konstruktor
XXX::XXX() : name_{new char[1024]} {
}

//destruktor
XXX::~XXX() {
    delete[] name_;
}

//kopiowania
XXX::XXX(const XXX &xxx) {
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_, xxx.name_);
    //Teraz nowy obiekt pokazuje na nowy fragment pamięci,
    //ale ze skopiowaną informacją
}

//operator przypisania:
XXX &XXX::operator=(const XXX &xxx) {
    //jeśli ktoś wpadł na pomysł x = x;
    if (this == &xxx) {
        return *this;
    }
    delete[] name_;

    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_, xxx.name_);
}

//konstruktor przenoszący:
XXX::XXX(XXX &&xxx) : name_{nullptr} {
    swap(name_, xxx.name_);

}

//operator przenoszący:
XXX &XXX::operator=(XXX &&xxx) {
    if (this == &xxx) {
        return xxx;
    }
    delete[] name_;

    name_ = nullptr;
    swap(name_, xxx.name_);
    return *this;
}

