//
// Created by Zuzanna on 08.03.2018.
//

#include "Polybius.h"
#include <map>

std::map<char, std::string> checkerboard = {{'a',"11"}, {'b',"12"}, {'c',"13"}, {'d',"14"}, {'e',"15"},
                                   {'f',"21"}, {'g',"22"}, {'h',"23"}, {'i',"24"}, {'j',"24"}, {'k',"25"},
                                   {'l',"31"}, {'m',"32"}, {'n',"33"}, {'o',"34"}, {'p',"35"},
                                   {'q',"41"}, {'r',"42"}, {'s',"43"}, {'t',"44"}, {'u',"45"},
                                   {'v',"51"}, {'w',"52"}, {'x',"53"}, {'y',"54"}, {'z',"55"}};

std::string PolybiusCrypt(std::string message){
    std::string cryptogram;

    for( int i = 0; i < message.length(); ++i){
        for(const auto &alphabet : checkerboard){
            if(tolower(message[i]) == alphabet.first){
                cryptogram += alphabet.second;
            }
        }
    }
    return cryptogram;
}


std::string PolybiusDecrypt(std::string crypted){
    std::string decryptogram;

    for( int i = 0; i<crypted.length(); i += 2){
        for(const auto &alphabet : checkerboard){
            if(crypted.substr(i, 2) == alphabet.second){
                decryptogram += alphabet.first;
                break;
            }
        }
    }
    return decryptogram;
}