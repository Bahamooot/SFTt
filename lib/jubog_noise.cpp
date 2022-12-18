//
// Created by Bahamut on 12/7/22.
//

#include "jubog_noise.h"
// combines 1 right diagonal noise which is slightly slanted with 45 deg noises
std::vector<int> jubog_noise::generate(int size_x, int size_y) {
    std::vector<int> right = rightDiagonal(size_x, size_y);
    std::vector<int> left1 = leftDiagonal(size_x, size_y);
    std::vector<int> left2 = leftDiagonal(size_x, size_y);

    for (int i = 1; i < size_x*size_y; i++) {
        right[i] = (right[i] + left1[i] + left2[i])/3;
    }

    return right;
}
// it's just left noise flipped 90 deg to the right and slightly slanted down
std::vector<int> jubog_noise::rightDiagonal(int size_x, int size_y) {
    int array[size_x][size_y];
    std::vector<int> arrat;
    notTrueRandom rando;
    int wave = 128;
    int step = 0;
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++ ) {
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

    for (int j = 0; j < size_x; j++) {
        for (int i = size_x - 1; i >= 0; i--) {
            arrat.push_back(array[i][j]);
        }
    }
    return arrat;
}

std::vector<int> jubog_noise::leftDiagonal(int size_x, int size_y) {
    std::vector<int> array;
    notTrueRandom rando;
    // 128 is midpoint between 0 and 255
    int wave = 128;
    int step = 0;
    // loop through every value
    for (int i = 0; i < size_x*size_y; i++) {
        // works the same as linear noise for the first row
        // each subsequent row is the average between a wave value behind it and the value above it to the left.
        int random = rando.getRandom(0, 100);
        if (random <= 50 ) {
            step += 10;
            if (step > 40) step = 0;
        } else {
            step -= 10;
            if (step < -40) step = 0;
        }
        if (i < size_x) {
            array.push_back(wave + step);
        } else {
            array.push_back(((array[i-1])+array[i-size_x+1]+step)/2);
        }
        if (array[i] > 255) array[i] = 255;
        else if (array[i] < 0) array[i] = 0;
    }

    return array;
}
