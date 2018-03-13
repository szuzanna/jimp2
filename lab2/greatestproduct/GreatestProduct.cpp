//
// Created by Zuzanna on 08.03.2018.
//

#include "GreatestProduct.h"

int GreatestProduct(const std::vector<int> &numbers, int k){
    std::vector<int> vector2;
    std::vector<int> sorted;
    sorted = numbers;
    std::sort(sorted.begin(),sorted.end());

    int minimal = 0;
    int result = 1;

    for(int v : sorted){
        if(v >= minimal){
            vector2.push_back(v);
            if(vector2.size()>k){
                minimal = v;
                vector2.erase(vector2.begin());
            }
        }
    }
    for(int i : vector2){
        result *= i;
    }
    return result;
}
