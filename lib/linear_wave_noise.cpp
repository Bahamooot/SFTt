//
// Created by Bahamut on 12/7/22.
//

#include "linear_wave_noise.h"

std::vector<int> linear_wave_noise::generate(int size_x, int size_y) {
    std::vector<int> array;
    notTrueRandom rando;
    int wave = 128;
    int step = 0;
    for (int i = 0; i < size_x*size_y; i++) {
        int random = rando.getRandom(0, 100);

        if (random <= 50 ) {
            step += 10;
            if (step > 40) step = 0;
        } else {
            step -= 10;
            if (step < -40) step = 0;
        }
        array.push_back(wave+step);
    }
    return array;
}
