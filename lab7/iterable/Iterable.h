//
// Created by Zuzanna on 28.04.2018.
//


#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <memory>

namespace utility {
    class IterableIterator {
    public:
        virtual std::pair<int, std::string> Dereference() const =0;

        virtual IterableIterator &Next()=0;

        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const =0;

        virtual ~IterableIterator() = default;

    public:
        std::vector<int>::const_iterator left_begin_;
        std::vector<std::string>::const_iterator right_begin_;
        std::vector<int>::const_iterator left_end_;
        std::vector<std::string>::const_iterator right_end_;
    };


    class ZipperIterator : public IterableIterator {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);


        std::pair<int, std::string> Dereference() const override;

        IterableIterator &Next() override;

        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;

        ~ZipperIterator() override = default;
    };


    class IterableIteratorWrapper {
    public:
        explicit IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);

        bool operator!=(const IterableIteratorWrapper &other);

        std::pair<int, std::string> operator*() const ;

        IterableIteratorWrapper &operator++();

    private:
        std::unique_ptr<IterableIterator> iterator_;
    };

    class Iterable {
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() const =0;

        virtual std::unique_ptr<IterableIterator> ConstEnd() const =0;

        IterableIteratorWrapper cbegin() const;

        IterableIteratorWrapper cend() const;

        IterableIteratorWrapper begin() const;

        IterableIteratorWrapper end() const;


    };


    class Zipper : public Iterable {
    public:
        explicit Zipper(std::vector<int> v1, std::vector<std::string> v2);

        std::unique_ptr<IterableIterator> ConstBegin() const override;

        std::unique_ptr<IterableIterator> ConstEnd() const override;

    private:
        std::vector<int>int_vector_;
        std::vector<std::string> string_vector_;
    };
}
#endif //JIMP_EXERCISES_ITERABLE_H
