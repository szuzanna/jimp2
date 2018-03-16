//
// Created by Zuzanna on 16.03.2018.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H


#include <string>
#include <vector>

std::string getKey(std::string key);

std::string XorCypherBreaker(std::vector<char> &encrypted, int key_length, std::vector<std::string> &dictionary);


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
