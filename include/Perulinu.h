//
// Created by Bahamut on 12/4/22.
//

#ifndef SFTT_PERULINU_H
#define SFTT_PERULINU_H

#include <vector>

class Perulinu {

private:
    std::vector<int> p;
    double fade(double t);
    double lerp(double t, double a, double b);
    double grad(int hash, double x, double y, double z);
public:
    Perulinu();
    Perulinu(unsigned int seed);
    double noise(double x, double y);
    
};


#endif //SFTT_PERULINU_H
