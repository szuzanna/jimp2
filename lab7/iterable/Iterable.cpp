//
// Created by Zuzanna on 28.04.2018.
//



#include <vector>
#include "Iterable.h"

namespace utility {
///////////////////////////IterableIteratorWrapper
    IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator) {
        iterator_ = move(iterator);
    }

    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
        return (iterator_->NotEquals(other.iterator_));
    }

    std::pair<int, std::string> IterableIteratorWrapper::operator*() const {
        //return std::pair<int, std::string>(this->iterator_->Dereference());
        return iterator_->Dereference();
    }

    IterableIteratorWrapper &IterableIteratorWrapper::operator++() {
        iterator_->Next();
        return *this;
    }

/////////////////////////////Iterable
    IterableIteratorWrapper Iterable::cbegin() const {
        return IterableIteratorWrapper(ConstBegin());
    }

    IterableIteratorWrapper Iterable::cend() const {
        return IterableIteratorWrapper(ConstEnd());
    }

    IterableIteratorWrapper Iterable::begin() const {
        return cbegin();

    }

    IterableIteratorWrapper Iterable::end() const {
        return cend();
    }

/////////////////////////ZipperItrator
    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                   std::vector<std::string>::const_iterator right_begin,
                                   std::vector<int>::const_iterator left_end,
                                   std::vector<std::string>::const_iterator right_end) {
        left_begin_ = left_begin;
        right_begin_ = right_begin;
        left_end_ = left_end;
        right_end_ = right_end;

    }


    std::pair<int, std::string> ZipperIterator::Dereference() const {
        return std::pair<int, std::string>(*left_begin_, *right_begin_);
    }

    IterableIterator &ZipperIterator::Next() {
        if (left_begin_ != left_end_ && right_begin_ != right_end_) {
            ++left_begin_;
            ++right_begin_;
        }
        return *this;
    }

    bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
        //return (this->Dereference() != other->Dereference());
        return left_begin_ != other->left_begin_ && right_begin_ != other->right_begin_;
    }


    /////////////Zipper
    Zipper::Zipper(std::vector<int> v1, std::vector<std::string> v2) {
        if (v1.size() > v2.size()) {
            for (auto i = v2.size(); i < v1.size(); ++i) {
                v2.emplace_back(v2.back());
            }
        } else {
            for (auto i = v1.size(); i < v2.size(); ++i) {
                v1.emplace_back(v1.back());
            }
        }
        int_vector_ = move(v1);
        string_vector_ = move(v2);

    }


    std::unique_ptr<IterableIterator> Zipper::ConstBegin() const {
        ZipperIterator tmp(int_vector_.begin(), string_vector_.begin(), int_vector_.end(),
                           string_vector_.end());
        std::unique_ptr<IterableIterator> result = std::make_unique<ZipperIterator>(tmp);
        return result;
    }

    std::unique_ptr<IterableIterator> Zipper::ConstEnd() const {
        ZipperIterator tmp(int_vector_.begin(), string_vector_.begin(), int_vector_.end(),
                           string_vector_.end());
        std::unique_ptr<IterableIterator> result = std::make_unique<ZipperIterator>(tmp);
        return result;
    }


}
