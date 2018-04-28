//
// Created by Zuzanna on 16.04.2018.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H


namespace figury {
    class Kolo {
    public:
        Kolo(double x = 0, double y = 0, double r = 0);

        double pole(void) const;

    private:
        double x_;
        double y_;
        double r_;
    };
}


#endif //JIMP_EXERCISES_KOLO_H
