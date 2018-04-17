//
// Created by Zuzanna on 16.04.2018.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "Word.h"
#include "Counts.h"
#include <vector>

namespace datastructures {
    class WordCounter {
    public:
        WordCounter();

        WordCounter(std::initializer_list<Word> elements);

        ~WordCounter();

        static WordCounter FromInputStream(std::istream *istream);


        void Insert(const Word &insert);

        std::set<Word> Words() const;

        int TotalWords() const;

        int DistinctWords() const;

        bool isInDictionary(const Word &text);

        void Sort();

        Counts operator[](const char *text) const;

        friend std::ostream &operator<<(std::ostream &output, const WordCounter &wc);


    private:
        std::vector<std::pair<Word, Counts>> index_;
    };
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
