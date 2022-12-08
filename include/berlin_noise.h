//
// Created by Bahamut on 12/8/22.
//

#ifndef SFTT_BERLIN_NOISE_H
#define SFTT_BERLIN_NOISE_H


#include "interface/noise.h"

class berlin_noise : public noise{
private:
    std::vector<int> p;
    double fade(double t);
    double lerp(double t, double a, double b);
    double grad(int hash, double x, double y, double z);
public:
    std::vector<int> generate(int size_x, int size_y) override;
    berlin_noise();
    berlin_noise(unsigned int seed);
    double noise(double x, double y, double z);
};


#endif //SFTT_BERLIN_NOISE_H
