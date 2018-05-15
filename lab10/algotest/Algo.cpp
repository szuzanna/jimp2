//
// Created by Zuzanna on 13.05.2018.
//

#include "Algo.h"
#include <algorithm>

namespace algo {

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy_n(v.begin(), n_elements, std::back_inserter(*out));
    }

    bool Contains(const std::vector<int> &v, int element) {
        return any_of(v.begin(), v.end(), [element](int i) { return element == i; });
    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        fill(v->begin(), v->end(), initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> tmp;
        tmp.reserve(length);
        fill_n(std::back_inserter(tmp), length, initial_value);
        return tmp;
    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> tmp;
        transform(v.begin(), v.end(), std::back_inserter(tmp), [](double v) { return std::to_string(v); });
        return tmp;
    }

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> tmp;
        transform(m.begin(), m.end(), inserter(tmp,tmp.end()), []( std::pair<std::string,int> m) { return m.first; });
        return tmp;
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        auto tmp =  v.find(key);
        return (tmp != v.end());
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> tmp;
        transform(m.begin(), m.end(), std::back_inserter(tmp), []( std::pair<std::string,int> m) { return m.second; });
        return tmp;
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        return any_of(v.begin(),v.end(), [value](std::pair<std::string, int> v){return v.second == value; });
    }
}