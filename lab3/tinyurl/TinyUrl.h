//
// Created by Zuzanna on 16.03.2018.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H


#include <utility>
#include <string>
#include <memory>
#include <array>
#include <map>

namespace tinyurl {
    struct TinyUrlCodec {
        std::map<std::string, std::string> pairs;
        std::array<char , 6> lastHash;
    };

    std::unique_ptr<TinyUrlCodec> Init();

    void NextHash(std::array<char, 6> *state);

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H
