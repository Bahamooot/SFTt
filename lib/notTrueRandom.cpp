//
// Created by Bahamut on 12/7/22.
//
#include "notTrueRandom.h"

int notTrueRandom::getRandom(int start, int end) {
    std::uniform_int_distribution<std::mt19937::result_type> dist7(start, end);
    return dist7(rng);
}

int notTrueRandom::getRandZeroHundred() {
    return dist6(rng);
}