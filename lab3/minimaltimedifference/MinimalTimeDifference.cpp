//
// Created by Zuzanna on 15.03.2018.
//
#include <regex>
#include "MinimalTimeDifference.h"

namespace minimaltimedifference {
    using std::string;
    using std::regex;
    using std::smatch;
    using std::stoi;
    using std::vector;

    unsigned int ToMinutes(const string &time_HH_MM) {
        unsigned int minutes;

        regex pattern{R"((\d{1,2})+:+(\d{2}))"};
        smatch matches;
        regex_match(time_HH_MM, matches, pattern);
        minutes = stoi(matches[1]) * 60 + stoi(matches[2]);

        return minutes;
    }

    unsigned int MinimalTimeDifference(vector<string> times) {
        vector<int> minutes = {};
        unsigned int min = 24*60;

        for (int i = 0; i < times.size(); ++i) {
            minutes.push_back(ToMinutes(times[i]));
        }

        sort(minutes.begin(), minutes.end());

        for (int j = 0; j < minutes.size() - 1; ++j) {
            if (minutes[j + 1] - minutes[j] < min) {
                min = minutes[j + 1] - minutes[j];
            }
        }

        if (minutes[0] + 24*60 - minutes[minutes.size() - 1] < min) {
            min = minutes[0] + 1440 - minutes[minutes.size() - 1];
        }

        return min;
    }
}