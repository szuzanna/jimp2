//
// Created by Zuzanna on 05.04.2018.
//

#include "SimpleTemplateEngine.h"

namespace nets {

    View::View(std::string text) {
        template_ = std::move(text);
    }

    View::View() {
        template_ = "";
    }

    View::~View() = default;;

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::string to_swap = template_;

        unsigned long start_changes;
        bool double_braces = false;
        std::string tmp;

        for (unsigned long i = 0; i < to_swap.length(); i++) {
            if (to_swap[i] == '{' && to_swap[i + 1] == '{' && to_swap[i + 2] != '{') {
                start_changes = i;
                i += 2;

                while (to_swap[i] != '}' || to_swap[i + 1] != '}') {
                    tmp += to_swap[i];
                    if (to_swap[i] == '}' && to_swap[i + 1] != '}') {
                        double_braces = true;
                        tmp = "";
                        break;
                    }
                    i++;
                }

                if (double_braces) {
                    double_braces = false;
                    continue;
                }

                to_swap.erase(start_changes, i - start_changes + 2);

                for (const auto &n : model) {
                    if (n.first == tmp) {
                        to_swap.insert(start_changes, n.second);
                    }
                }
                i = start_changes;
                tmp = "";
            }
        }
        return to_swap;
    }
}