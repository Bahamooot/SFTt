//
// Created by Bahamut on 12/7/22.
//

#ifndef SFTT_AVERAGE2D_H
#define SFTT_AVERAGE2D_H
#include <vector>

class average2D {
public:
    std::vector<std::vector<int>> average(std::vector<std::vector<int>> array, int size_x, int size_y);
    std::vector<int> average(std::vector<int> array, int size_x, int size_y);
};


#endif //SFTT_AVERAGE2D_H
