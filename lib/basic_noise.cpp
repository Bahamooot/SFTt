//
// Created by Bahamut on 12/7/22.
//

#include "basic_noise.h"

std::vector<int> basic_noise::generate(int size_x, int size_y) {
    int size = size_x*size_y;
    std::vector<int> array;
    for (int i = 0; i < size; i++) {
        srand(i);
        int random = rand() % 256;
        array.push_back(random);
    }
    return array;
}
