//
// Created by Bahamut on 11/30/22.
//

#ifndef SFTT_RANDOM_H
#define SFTT_RANDOM_H

#endif //SFTT_RANDOM_H
#include <random>

class notTrueRandom {
public:
    int getRandom(int start, int end);

    static unsigned int threadRandom();

    int * getRandomList(int size);
};

int notTrueRandom::getRandom(int start, int end) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(start,end);

    return dist6(rng);
}

unsigned int notTrueRandom::threadRandom() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 100);

    return dist6(rng);
}

int * notTrueRandom::getRandomList(int size) {
    int randoma[size];
    for (int i = 0; i < size; i+=5) {
        auto thread1 = std::async(std::launch::async, threadRandom);
        auto thread2 = std::async(std::launch::async, threadRandom);
        auto thread3 = std::async(std::launch::async, threadRandom);
        auto thread4 = std::async(std::launch::async, threadRandom);
        auto thread5 = std::async(std::launch::async, threadRandom);
        randoma[i] = thread1.get();
        randoma[i+1] = thread2.get();
        randoma[i+2] = thread3.get();
        randoma[i+3] = thread4.get();
        randoma[i+4] = thread5.get();
    }
    return randoma;
}