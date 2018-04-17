//
// Created by Zuzanna on 16.04.2018.
//

#include "Counts.h"

namespace datastructures {

    Counts::Counts(int quantity) {
        quantity_ = quantity;
    }

    int Counts::getQuantity_() const {
        return quantity_;
    }

    Counts::Counts() {
        quantity_ = 0;
    }


    Counts::operator int() const {
        return quantity_;
    }

    bool Counts::operator==(const Counts &other) {
        return (this->quantity_ == other.quantity_);
    }

    bool Counts::operator<(const Counts &other) {
        return (this->quantity_ < other.quantity_);
    }

    bool Counts::operator>(const Counts &other) {
        return (this->quantity_ > other.quantity_);
    }

    Counts &Counts::operator++(int) {
        this->quantity_++;
        return *this;
    }
}
