//
// Created by Bahamut on 12/7/22.
//

#include "jubog_noise.h"

std::vector<int> jubog_noise::generate(int size_x, int size_y) {
    std::vector<int> right = rightDiagonal(size_x, size_y);
    std::vector<int> left1 = leftDiagonal(size_x, size_y);
    std::vector<int> left2 = leftDiagonal(size_x, size_y);

    for (int i = 1; i < size_x*size_y; i++) {
        right[i] = (right[i] + left1[i] + left2[i])/3;
    }

    return right;
}

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
