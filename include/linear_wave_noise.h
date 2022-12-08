//
// Created by Bahamut on 12/7/22.
//

#ifndef SFTT_LINEAR_WAVE_NOISE_H
#define SFTT_LINEAR_WAVE_NOISE_H


#include "interface/noise.h"

class linear_wave_noise : public noise{
    std::vector<int> generate(int size_x, int size_y) override;
};


#endif //SFTT_LINEAR_WAVE_NOISE_H
