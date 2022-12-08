//
// Created by Bahamut on 12/7/22.
//

#ifndef SFTT_RANDOM_NOISE_H
#define SFTT_RANDOM_NOISE_H


#include "interface/noise.h"

class random_noise : public noise{
    std::vector<int> generate(int size_x, int size_y) override;
};


#endif //SFTT_RANDOM_NOISE_H
