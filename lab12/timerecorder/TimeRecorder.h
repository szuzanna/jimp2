//
// Created by Zuzanna on 29.05.2018.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <map>

namespace profiling {
    template<typename T>
    auto TimeRecorder(T t) {
        typedef std::chrono::high_resolution_clock clock;
        typedef std::chrono::duration<double, std::milli> duration;
        static clock::time_point begin = clock::now();
        auto result = (t)();
        duration elapsed = clock::now() - begin;
        return std::pair<decltype(result), double>(result, elapsed.count());
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
