//
// Created by Zuzanna on 02.03.2018.
//
#include <string>
#include <iostream>
#include "Palindrome.h"

bool IsPalindrome(std::string str){
    int i = 0;
    const char *characters = str.c_str();
    size_t size = str.size();

    if(size == 0 || size == 1){
        return true;
    }

    while(i < (size + 1)/2){
        if(characters[i] != characters[size -(1 + i)]){
            return false;
        }
        i += 1;
    }

    return true;
}
