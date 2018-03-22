//
// Created by Zuzanna on 16.03.2018.
//

#include "TinyUrl.h"
#include <iostream>

namespace tinyurl {
    std::unique_ptr<TinyUrlCodec> Init() {
        std::unique_ptr<TinyUrlCodec> pointer = std::make_unique<TinyUrlCodec>();
        return pointer;
    }

    void NextHash(std::array<char, 6> *state) {
        bool changed = true;
        int i = 5;
        std::array<int, 6> exeptions{57, 65, 90, 97, 122, 48};
        while (i >= 0 && changed) {
            if ((*state)[i] != 122) {
                changed = false;
            }
            if ((*state)[i] == 57 || (*state)[i] == 90 || (*state)[i] == 122) {
                for (int j = 0; j < 6; j += 2) {
                    if ((*state)[i] == exeptions[j]) {
                        (*state)[i] = exeptions[j + 1];
                    }
                }
            } else {
                (*state)[i] += 1;
            }
            --i;
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        std::string encoded = (*codec)->lastHash.data();
        (*codec)->pairs[encoded] = url;
        std::cout << encoded << std::endl;
        return encoded;

    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        auto iter = codec->pairs.find(hash);
        if (iter == codec->pairs.end())
            return nullptr;
        else
            return iter->second;
    }
}