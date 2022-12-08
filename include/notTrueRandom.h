//
// Created by Bahamut on 11/30/22.
//

#ifndef SFTT_RANDOM_H
#define SFTT_RANDOM_H

#endif //SFTT_RANDOM_H
#include <random>

class notTrueRandom {
private:
    inline static std::mt19937 rng{ std::random_device{}() };
    inline static std::uniform_int_distribution<std::mt19937::result_type> dist6{0, 100};
public:

    int getRandom(int start, int end);
    static int getRandZeroHundred();
};

