//
// Created by Zuzanna on 05.04.2018.
//

#include <sstream>
#include "SimpleJson.h"

namespace nets {
    JsonValue::JsonValue(const double &value) {
        double_value = value;
        option = is_floating;
    }

    JsonValue::JsonValue(const int &value) {
        int_value = value;
        option = is_integer;
    }

    JsonValue::JsonValue(const std::string &str) {
        text = str;
        option = is_text;
    }


    JsonValue::JsonValue(const std::vector<JsonValue> &vec) {
        table = vec;
        option = is_object;
    }

    JsonValue::JsonValue(const bool &boolean) {
        bool_value = boolean;
        option = is_boolean;
    }

    JsonValue::JsonValue(const std::map<std::string, JsonValue> &map) {
        object.insert(map.begin(), map.end());
        option = is_table;
    }

    std::string JsonValue::ToString() const {
        std::stringstream out;
        switch (option) {
            case is_text :
                out << "\"";
                for (char i : text) {
                    if (i == '\"' || i == '\\' || i == '"') {
                        out << "\\" << i;
                    } else out << i;
                }
                out << "\"";
                return out.str();

            case is_integer :
                return std::to_string(int_value);

            case is_floating:
                out << std::fixed << std::setprecision(2) << double_value;
                return out.str();

            case is_object:
                out << "[";
                for (int i = 0; i < table.size(); i++) {
                    out << table[i].ToString();
                    if (i < table.size() - 1)out << ", ";
                    else out << "]";
                }
                return out.str();

            case is_boolean:
                if (bool_value) out << "true";
                else out << "false";
                return out.str();

            case is_table:
                out << "{";
                bool coma = false;
                for (auto iter : object) {
                    if (coma) out << ", ";
                    coma = true;
                    out << "\"";
                    for (char i : iter.first) {
                        if (i == '\"' || i == '\\' || i == '"') {
                            out << "\\" << i;
                        } else out << i;
                    }
                    out << "\"";
                    out << ": " + iter.second.ToString();
                }
                out << "}";
                return out.str();
        }
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        auto it = object.find(name);
        if (it != object.end())
            return std::experimental::make_optional(it->second);
        else return {};
    }
}