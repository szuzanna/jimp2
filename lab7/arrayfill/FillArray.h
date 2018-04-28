//
// Created by Zuzanna on 17.04.2018.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <random>

using namespace std;

namespace arrays {
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };
    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int start);

        IncrementalFill(int start, int step);

        virtual int Value(int index) const override;

    private:
        int start_;
        int step_;

    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}

        virtual int Value(int index) const override;

    private:
        int value_;
    };

    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int a = 1, int b = 0);

        virtual int Value(int index) const override;

    private:
        int a_, b_;
    };

    class RandomFill : public ArrayFill{
    public:
        RandomFill(unique_ptr<default_random_engine> engine, unique_ptr<uniform_int_distribution<int>> size);
        virtual int Value(int index) const override;

    private:
        unique_ptr<default_random_engine> generator_;
        unique_ptr<uniform_int_distribution<int>> size_;
    };
}


#endif //JIMP_EXERCISES_ARRAYFILL_H
