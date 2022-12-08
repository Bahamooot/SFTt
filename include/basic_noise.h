//
// Created by Bahamut on 12/7/22.
//

#ifndef SFTT_BASIC_NOISE_H
#define SFTT_BASIC_NOISE_H


#include "interface/noise.h"

class basic_noise : public noise {
public:
    std::vector<int> generate(int size_x, int size_y) override;
};


#endif //SFTT_BASIC_NOISE_H
