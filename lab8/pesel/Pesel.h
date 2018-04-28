//
// Created by Zuzanna on 24.04.2018.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>

namespace academia {
    class Pesel {
    public:
        Pesel(std::string &str);

        void Validate(std::string &str);


    private:
        std::string pesel_;
    };

    class AcademiaDataValidationError : public std::invalid_argument {
    public:
        AcademiaDataValidationError(const std::string &str) : std::invalid_argument(str){};
    };

    class InvalidPeselLength : public AcademiaDataValidationError {
    public:
        InvalidPeselLength(const std::string &str) : AcademiaDataValidationError("PESEL nie posiada 11 cyfr") {};
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:

        InvalidPeselChecksum(const std::string &str) : AcademiaDataValidationError("Suma kontrolna PESEL-u jest niezgodna"){};
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError {
    public:

        InvalidPeselCharacter(const std::string &str) : AcademiaDataValidationError("PESEL zawiera niedozwolone znaki"){};
    };


}


#endif //JIMP_EXERCISES_PESEL_H
