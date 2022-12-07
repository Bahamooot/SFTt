//
// Created by Bahamut on 11/30/22.
//

#ifndef SFTT_PERLIN_NOISE_H
#define SFTT_PERLIN_NOISE_H

#include <vector>
#include "SDL.h"
#include <thread>
#include <future>
#include "notTrueRandom.h"
class perlin_noise {
private:

public:
    static int * generateShitNoise(int size, int seed);
    static int * generateRandomNoise(int size);
    static int * generateWaveNoise(int size);
    static int * generate2DWaveNoiseLeft(int size, int x);
    static int * generateAverageNoise(int *array, int x, int size);

    int *generate2DWaveNoiseRight(int size, int x);
};


#endif //SFTT_PERLIN_NOISE_H

int * perlin_noise::generateShitNoise(int size, int seed) {
    int array[size];
    for (int i = 0; i < size; i++) {
        srand(seed+i);
        int random = rand() % 256;
        array[i] = random;
    }
    return array;
}

int *perlin_noise::generateRandomNoise(int size) {
    int array[size];
    notTrueRandom rando;
    for (int i = 0; i < size; i++) {
        int random = rando.getRandom(0, 256);
        array[i] = random;
    }
    return array;
}

int *perlin_noise::generateWaveNoise(int size) {
    int array[size];
    notTrueRandom rando;
    int wave = 128;
    int step = 0;
    for (int i = 0; i < size; i++) {
        int random = rando.getRandom(0, 100);

        if (random <= 50 ) {
            step += 10;
            if (step > 40) step = 0;
        } else {
            step -= 10;
            if (step < -40) step = 0;
        }
        array[i] = wave + step;
    }
    return array;
}

int *perlin_noise::generate2DWaveNoiseLeft(int size, int x) {
    int y = size/x;
    int array[x][y];
    int arrat[size];
    notTrueRandom rando;
    int wave = 128;
    int step = 0;
    //int * randoma = rando.getRandomList(size);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++ ) {
            int random = rando.getRandom(0, 100);
            if (random <= 50) {
                step += 10;
                if (step > 40) step = 0;
            } else {
                step -= 10;
                if (step < -40) step = 0;
            }
            if (j < 1) {
                array[j][i] = wave + step;
            } else {
                array[j][i] = (array[j][i-1] + array[j-1][i] + step)/2;
            }
            if (array[j][i] > 255) array[j][i] = 255;
            else if (array[j][i] < 0) array[j][i] = 0;
        }
    }

    int k = 0;
    for (int j = 0; j < x; j++) {
        for (int i = x - 1; i >= 0; i--) {
            arrat[k] = array[i][j];
            k++;
        }
    }
    return arrat;
}

int *perlin_noise::generate2DWaveNoiseRight(int size, int x) {
    int array[size];
    notTrueRandom rando;
    int wave = 128;
    int step = 0;
    //int * randoma = rando.getRandomList(size);
    for (int i = 0; i < size; i++) {
        int random = rando.getRandom(0, 100);
        if (random <= 50 ) {
            step += 10;
            if (step > 40) step = 0;
        } else {
            step -= 10;
            if (step < -40) step = 0;
        }
        if (i < x) {
            array[i] = wave + step;
        } else {
            array[i] = ((array[i-1])+array[i-x+1]+step)/2;
        }
        if (array[i] > 255) array[i] = 255;
        else if (array[i] < 0) array[i] = 0;
    }

    return array;
}

int *perlin_noise::generateAverageNoise(int *array, int x, int size) {
    for (int i = x; i < size - x; i++) {
        array[i] = (array[i] + array[i-1] + array[i+1] + array[i-x] + array[i+x])/5;
    }
    sizeof(array);
    return array;
}

