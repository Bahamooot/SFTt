//
// Created by Bahamut on 12/7/22.
//

#include "average2D.h"

std::vector<std::vector<int>> average2D::average(std::vector<std::vector<int>> array, int size_x, int size_y) {
    // for every value, average it out with the 4 values surrounding it
    for (int i = size_x; i < (size_x*size_y) - size_x; i++) {
        array[0][i] = (array[0][i] + array[0][i-1] + array[0][i+1] + array[0][i-size_x] + array[0][i+size_x])/5;
    }
    return array;
}
