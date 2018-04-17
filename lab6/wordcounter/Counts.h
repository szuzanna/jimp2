//
// Created by Zuzanna on 16.04.2018.
//

#ifndef JIMP_EXERCISES_COUNTER_H
#define JIMP_EXERCISES_COUNTER_H

namespace datastructures {
    class Counts {
    public:
        Counts();

        Counts(int quantity);

        int getQuantity_() const;

        operator int() const;

        Counts &operator++(int);

        bool operator==(const Counts &other);

        bool operator<(const Counts &other);

        bool operator>(const Counts &other);

    private:
        int quantity_;
    };
}


#endif //JIMP_EXERCISES_COUNTER_H
