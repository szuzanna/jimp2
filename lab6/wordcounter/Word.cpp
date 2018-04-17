//
// Created by Zuzanna on 16.04.2018.
//

#include <string>
#include "Word.h"

namespace datastructures {
    Word::Word() {
        word_ = "";
    }

    Word::Word(std::string text) {
        word_ = text;

    }

    Word::Word(const char *text) {
        word_ = text;
    }

    bool Word::operator==(const Word &other) const {
        return (this->word_ == other.word_);
    }

    bool Word::operator<(const Word &other) const {
        return (this->word_ < other.word_);
    }

    bool Word::operator>(const Word &other) const {
        return (this->word_ > other.word_);
    }

    std::string Word::getWord_() const {
        return word_;
    }

}