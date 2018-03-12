//
// Created by Zuzanna on 04.03.2018.
//

#include "DoubleBasePalindromes.h"


uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t sum = 0;
    if(max_vaule_exculsive <= 0){
        return 0;
    }
    else{
        for(int i = 1; i <= max_vaule_exculsive; ++i){
            std::string decimal =  std::to_string(i);
            if(isPalindrome(decimal) && isPalindrome(DecToBin(i))){
                sum += i;
            }
        }
        return sum;
    }
}

std::string DecToBin(int number){
    std::string binary;
    while(number){
        number%2 == 0 ? binary += "0":binary += "1";
        number /= 2;
    }
    return binary;
}

bool isPalindrome(std::string str){
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
