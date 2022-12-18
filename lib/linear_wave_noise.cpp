//
// Created by Bahamut on 12/7/22.
//

#include "linear_wave_noise.h"

std::vector<int> linear_wave_noise::generate(int size_x, int size_y) {
    std::vector<int> array;
    notTrueRandom rando;
    int wave = 128;
    int step = 0;
    // get random value between 0 and 100, if under 50 go down by 10, 20, 30, 40 for each repeat number
    // for up do the same but going up
    // if there are numbers below 0 or above 50 more than 4 times reset the incremental values to 0;
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
