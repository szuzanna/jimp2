//
// Created by Zuzanna on 03.03.2018.
//

#include "ReverseString.h"

std::string Reverse(std::string str){
    const char *character = str.c_str();

    if(character[0] !='\0'){
        size_t size = str.size();
        return Reverse(str.substr(1, size - 1)).append(1,character[0]);
    }
    else{
        return"";
    }


}