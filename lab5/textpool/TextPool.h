//
// Created by Zuzanna on 12.04.2018.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H


#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>

namespace pool {
    class TextPool {
    public:

        //2. konstruktor przenoszący
        TextPool(TextPool &&text);

        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&text);

        //5. Destruktor
        ~TextPool();

        //konstruktor domyślny
        TextPool();

        //kostruktor z listą inicjalizacyjną
        TextPool(const std::initializer_list<const char*> &text);

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    private:
        std::set<std::experimental::string_view> pool_;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
