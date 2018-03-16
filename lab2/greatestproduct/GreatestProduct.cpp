//
// Created by Zuzanna on 08.03.2018.
//

#include "GreatestProduct.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

int GreatestProduct(const std::vector<int> &numbers, int k){
    std::vector<int> positive_vec;
    std::vector<int> negative_vec;


    int result = 1;

    for(int v : numbers){
        if(v >= 0){
            positive_vec.push_back(v);
        }
        else{
            negative_vec.push_back(v);
        }
    }

    sort(negative_vec.begin(),negative_vec.end());
    sort(positive_vec.begin(),positive_vec.end());

    int minimal = 0;
    int limit = negative_vec.size();
    int maximal = positive_vec.size();

    if(limit == 0){
        for (int i =0; i<k ; ++i){
            result *= positive_vec[maximal-i-1];
        }
    }
    else if(maximal == 0){
        std::cout<<"bylem tutaj"<<std::endl;
        if(k%2 == 0){
            for (int i =0; i<k ; ++i){
                result *= negative_vec[minimal +i];
            }
        }
        else{
            for (int i =0; i<k ; ++i){
                result *= negative_vec[limit -1 -i];
            }
            }
    }
    else{
        for(int j = 0; j +1 < k; j += 2){
            int first, second;
            if (minimal +1< limit ) {
                first = negative_vec[minimal] * negative_vec[minimal+1];
            }
            else{
                first = 0;
            }
            std::cout<<first<<std::endl;
            if (maximal > 1) {
                second = positive_vec[maximal - 1] * positive_vec[maximal - 2];
            }
            else{
                second = 0;
            }
            std::cout<<second<<std::endl;
            (first > second)?(minimal+=2):(maximal-=2);
            result *= (first > second)?first:second;
        }
        if(k%2 == 1 && maximal != 0){
            result *= positive_vec[maximal -1];
        }
        else if(k%2 == 1){
            result *= negative_vec[minimal+1];
        }
    }
    return result;
}
