//
// Created by Zuzanna on 24.04.2018.
//

#include <regex>
#include "Pesel.h"

using namespace std;
namespace academia {

    Pesel::Pesel(std::string &str) {
        pesel_ = str;
    }

    void Pesel::Validate(std::string &str) {
        const char *pesel_table = str.c_str();
        int control_sum = 0;
        control_sum =
                9 * pesel_table[0] + 7 * pesel_table[1] + 3 * pesel_table[2] + 1 * pesel_table[3] + 9 * pesel_table[4] +
                7 * pesel_table[5] + 3 * pesel_table[6] + 1 * pesel_table[7] + 9 * pesel_table[8] + 7 * pesel_table[9];
        if (control_sum != pesel_table[10]) {
            throw InvalidPeselChecksum(str);
        }
        if (str.size() != 11) {
            throw InvalidPeselLength(str);
        }
        for (int i = 0; i < str.size(); ++i) {
            if ((int) pesel_table[i] > (int) '9' || (int) pesel_table[i] < (int) '0') {

                throw InvalidPeselCharacter(str);
            }
        }
    }

}
