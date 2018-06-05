//
// Created by Zuzanna on 04.06.2018.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>

namespace academia {
    class TeacherId {
    public:
        TeacherId(const int &id) : id_(id) {}

        TeacherId(const TeacherId &teacher) : id_(teacher.id_) {}

        operator int() const { return id_; };

        bool operator!=(const TeacherId &teacher) const {
            return teacher.id_ != id_;
        };
    private:
        int id_;
    };

    class Teacher {
    public:
        Teacher(const TeacherId &id, const std::string &name, const std::string &department) :
                id_(id), name_(name), department_(department) {}

        bool operator==(const Teacher &teacher) const {
            return (id_ == teacher.id_
                    && name_ == teacher.name_
                    && department_ == teacher.department_);
        }

        bool operator!=(const Teacher &teacher) const { return !(*this == teacher); }

        const int Id() const { return id_; }

        const std::string Name() const { return name_; }

        const std::string Department() const { return department_; }

    private:
        TeacherId id_;
        std::string name_, department_;
    };

    class TeacherHash {
    public:
        size_t operator()(const Teacher &teacher) const {
            size_t name = 0, department = 0;
            for (auto &character : teacher.Name()) name += character;
            for (auto &character :teacher.Department()) department += character;
            return name ^ department ^ teacher.Id();
        }
    };

}


#endif //JIMP_EXERCISES_TEACHERHASH_H
