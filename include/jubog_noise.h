//
// Created by Bahamut on 12/7/22.
//

#ifndef SFTT_JUBOG_NOISE_H
#define SFTT_JUBOG_NOISE_H


#include "interface/noise.h"

class jubog_noise : public noise {
    std::vector<int> generate(int size_x, int size_y) override;
    std::vector<int> rightDiagonal(int size_x, int size_y);
    std::vector<int> leftDiagonal(int size_x, int size_y);
};


#endif //SFTT_JUBOG_NOISE_H
