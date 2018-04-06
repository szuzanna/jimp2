//
// Created by Zuzanna on 05.04.2018.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <unordered_map>
#include <string>

namespace nets {

    class View {

    public:
        View(std::string);

        View();

        ~View();

        std::string Render(const std::unordered_map<std::string, std::string> &model) const;


        std::string template_;

    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
