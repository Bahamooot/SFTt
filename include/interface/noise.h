//
// Created by Bahamut on 11/30/22.
//

#ifndef SFTT_PERLIN_NOISE_H
#define SFTT_PERLIN_NOISE_H

#include <vector>
#include "notTrueRandom.h"

class noise {
public:
    virtual std::vector<int> generate(int size_x, int size_y) = 0;
};




#endif //SFTT_PERLIN_NOISE_H



