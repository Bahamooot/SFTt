//
// Created by Bahamut on 12/7/22.
//

#include "random_noise.h"

std::vector<int> random_noise::generate(int size_x, int size_y) {
    std::vector<int> array;
    notTrueRandom rando;
    // random values
    for (int i = 0; i < size_x*size_y; i++) {
        int random = rando.getRandom(0, 256);
        array.push_back(random);
    }
    return array;
}
