//
// Created by Zuzanna on 16.04.2018.
//

#include <initializer_list>
#include <set>
#include <iostream>
#include <algorithm>
#include "WordCounter.h"

namespace datastructures {

    WordCounter::WordCounter() {
        index_.clear();
    }

    WordCounter::~WordCounter() {
        index_.clear();
    }

    WordCounter::WordCounter(std::initializer_list<Word> elements) {
        std::pair<Word, Counts> toAdd;
        for (auto n : elements) {
            if (this->isInDictionary(n)) { ;
            } else {
                toAdd.first = n;
                toAdd.second = Counts{1};
                index_.emplace_back(toAdd);
            }
        }
        this->Sort();
    }

    void WordCounter::Insert(const Word &insert) {
        std::pair<Word, Counts> tmp;
        if (this->isInDictionary(insert)) { ;
        } else {
            tmp.first = insert;
            tmp.second = Counts{1};
            index_.emplace_back(tmp);
        }
        this->Sort();
    }


    bool WordCounter::isInDictionary(const Word &text) {

        for (int i = 0; i < index_.size(); i++) {
            if (index_[i].first == text) {
                index_[i].second++;
                return true;
            }
        }
        return false;
    }

    void WordCounter::Sort() {
        struct {
            bool operator()(std::pair<Word, Counts> first, std::pair<Word, Counts> second) {
                return (first.second > second.second);
            }
        } Compare;
        std::sort(index_.begin(), index_.end(), Compare);
    }


    int WordCounter::TotalWords() const {
        int answer = 0;
        for (auto n : index_) {
            answer += n.second.getQuantity_();
        }
        return answer;
    }

    int WordCounter::DistinctWords() const {
        return (int) index_.size();
    }

    Counts WordCounter::operator[](const char *text) const {
        for (auto n : index_) {
            if (n.first == (text)) {
                return n.second;
            }
        }
        return Counts{0};
    }

    std::ostream &operator<<(std::ostream &output, const WordCounter &wc) {
        for (auto n : wc.index_) {
            output << "Word: ";
            output << n.first.getWord_();
            output << " Appearances: ";
            output << n.second.getQuantity_();
            output << std::endl;
        }
        return output;
    }

    WordCounter WordCounter::FromInputStream(std::istream *input) {
        WordCounter answer{};
        std::string toAdd;
        int c;
        bool needToAdd = false;
        while (*input) {
            c = input->get();
            if ((65 <= c && c <= 90) || (97 <= c && c <= 122)) {
                needToAdd = true;
                toAdd += (char) c;
            } else if (needToAdd) {
                answer.Insert(Word{toAdd});
                toAdd = "";
                needToAdd = false;
            }
        }
        return answer;
    }


    std::set<Word> WordCounter::Words() const {
        std::set<Word> answer;
        for (auto n : index_) {
            answer.emplace(n.first);
        }
        return answer;
    }
}