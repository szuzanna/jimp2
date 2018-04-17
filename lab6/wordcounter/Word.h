//
// Created by Zuzanna on 16.04.2018.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

namespace datastructures {

    class Word {
    public:
        Word();

        Word(const char *text);

        Word(std::string text);

        bool operator==(const Word &other_object) const;

        bool operator<(const Word &other) const;

        bool operator>(const Word &other) const;

        std::string getWord_() const;

    private:
        std::string word_;
    };
}


#endif //JIMP_EXERCISES_WORD_H
