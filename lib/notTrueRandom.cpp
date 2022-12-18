//
// Created by Bahamut on 12/7/22.
//
#include "notTrueRandom.h"
// gets true random numbers
// i'm sorry dawid, i learned the error of my ways, if i could rename this i would name it trueRandom.cpp
int notTrueRandom::getRandom(int start, int end) {
    std::uniform_int_distribution<std::mt19937::result_type> dist7(start, end);
    return dist7(rng);
}

int notTrueRandom::getRandZeroHundred() {
    return dist6(rng);
}