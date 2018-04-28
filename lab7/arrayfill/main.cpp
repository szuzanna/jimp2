//
// Created by Zuzanna on 17.04.2018.
//
#include <vector>
#include <FillArray.h>
using namespace arrays;

int main(){
    std::vector<int> vs;
    FillArray(1024, UniformFill {77}, &vs);
}
