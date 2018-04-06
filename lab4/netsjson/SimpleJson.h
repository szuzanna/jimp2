//
// Created by Zuzanna on 05.04.2018.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H


#include <experimental/optional>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>

namespace nets {
    class JsonValue {
    public:
        JsonValue(const double &);

        JsonValue(const int &);

        JsonValue(const std::string &);

        JsonValue(const bool &);

        JsonValue(const std::vector<JsonValue> &);

        JsonValue(const std::map<std::string, JsonValue> &);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

        enum data_type {
            is_text, is_integer, is_floating, is_boolean, is_table, is_object
        };
        data_type option;
        std::string text;
        int int_value;
        double double_value;
        bool bool_value;
        std::vector<JsonValue> table;
        std::map<std::string, JsonValue> object;

    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
