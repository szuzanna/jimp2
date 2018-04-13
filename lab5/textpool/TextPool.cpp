//
// Created by Zuzanna on 12.04.2018.
//

#include "TextPool.h"

using namespace pool;

TextPool::TextPool(TextPool &&text) {
    pool_.clear();
    std::swap(pool_, text.pool_);
}

TextPool &TextPool::operator=(TextPool &&text) {
    if (this == &text) {
        return text;
    }

    pool_.clear();
    std::swap(pool_, text.pool_);
    return text;
}

TextPool::~TextPool() {
}

TextPool::TextPool() {
    pool_.clear();
}

TextPool::TextPool(const std::initializer_list<const char *> &text) {

    bool is_new_item = true;
    for (auto n : text) {
        for (auto m : pool_)
            if (!m.compare(n)) {
                is_new_item = false;
                break;
            }
        if (is_new_item) {
            pool_.insert(n);
        }
        is_new_item = true;
    }
}

std::experimental::string_view TextPool::Intern(const std::string &str) {
    for (auto n : pool_) {
        if (!n.compare(str)) {
            return n;
        }
    }
    auto newly_added = pool_.insert(str);
    return std::experimental::string_view(*(newly_added.first));
}

size_t TextPool::StoredStringCount() const {
    return pool_.size();
}

