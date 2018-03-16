//
// Created by Zuzanna on 16.03.2018.
//

#include <iostream>
#include "XorCypherBreaker.h"

std::string getKey(std::string key) {
    key[2]++;
    if (key[2] == 'z' + 1) {
        key[1]++;
        key[2] = 'a';
        if (key[1] == 'z' + 1) {
            key[0]++;
            key[1] = 'a';
        }
    }
    return key;
}

std::string XorCypherBreaker(std::vector<char> &encrypted, int key_length, std::vector<std::string> &dictionary) {
    std::vector<std::string> keys;
    int key_pointer = 0;
    int encrypted_pointer = 0;

    std::string key = "abc";
    while (encrypted_pointer != encrypted.size()) {
        int result = encrypted[encrypted_pointer] ^key[key_pointer];

        if ((result >= 32 && result <= 90) || (result >= 97 && result <= 122)) {
            key_pointer++;
            encrypted_pointer++;
            if (key_pointer == key_length) {
                key_pointer = 0;
            }
        } else {
            key_pointer = 0;
            encrypted_pointer = 0;
            key = getKey(key);
            continue;

        }
    }
    return key;
}