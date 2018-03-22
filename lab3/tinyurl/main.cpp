//
// Created by Zuzanna on 16.03.2018.
//
#include <iostream>
#include "TinyUrl.h"
using namespace tinyurl;
int main(){
    auto example = Init();
    auto isWorking = Encode("www.wp.pl",&example);
    std::cout<<example->lastHash.data();
   // std::cout<< Decode(example,isWorking);

    auto isWorking2 = Encode("www.abdc.pl",&example);
    std::cout<<example->lastHash.data();
    //std::cout<< Decode(example,isWorking2);

}

