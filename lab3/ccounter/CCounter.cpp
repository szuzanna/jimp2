//
// Created by Zuzanna on 15.03.2018.
//

#include "CCounter.h"
namespace ccounter {

    std::unique_ptr<Counter> Init(){
        std::unique_ptr<Counter> pointer = std::make_unique<Counter>();
        return pointer;
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter){
        auto toIncrement = (*counter)->countObj.find(key);

        if (toIncrement != (*counter)->countObj.end()){
            (*toIncrement).second ++;
        }
        else {
            (*counter)->countObj.insert(std::pair<std::string, int>(key, 1));
        }

    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key){
        auto toIncrement = counter->countObj.find(key);

        if (toIncrement == counter->countObj.end()){
            return 0;
        }
        else {
           return (*toIncrement).second;
        }
    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter){

    }
}