//
// Created by Zuzanna on 17.04.2018.
//

#include <cstddef>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <bits/unique_ptr.h>
#include <memory>
#include "FillArray.h"

namespace arrays {
    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const {
        return start_ + step_ * index;
    }

    IncrementalFill::IncrementalFill(int start, int step) {
        start_ = start;
        step_ = step;
    }

    IncrementalFill::IncrementalFill(int start) {
        start_ = start;
        step_ = 1;
    }

    SquaredFill::SquaredFill(int a, int b) {
        a_ = a;
        b_ = b;
    }

    int SquaredFill::Value(int index) const {
        return (a_ * index * index + b_);
    }

    int RandomFill::Value(int index) const {
        return ((*size_)(*generator_));
    }

    RandomFill::RandomFill(unique_ptr<default_random_engine> generator, unique_ptr<uniform_int_distribution<int>> size) {
        generator_ = move(generator);
        size_ = move(size);
    }
}
