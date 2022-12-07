//
// Created by Bahamut on 11/28/22.
//

#ifndef SFTT_COLOR_H
#define SFTT_COLOR_H

#endif //SFTT_COLOR_H

class color {
private:
    int r = 255;
    int g = 255;
    int b = 255;
    int a = 255;
    int x = 0;
    int y = 0;
public:
    color(int r, int g, int b, int a, int x, int y) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
        this->x = x;
        this->y = y;
    };
    int getR() {return r;};
    int getG() {return g;};
    int getB() {return b;};
    int getA() {return a;};
    int getX() {return x;};
    int getY() {return y;};

    void setRGBA(int r, int g, int b , int a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
    void setR(int r) {this->r = r;};
    void setG(int g) {this->r = g;};
    void setB(int b) {this->r = b;};
    void setA(int a) {this->r = a;};
    void setX(int x) {this->r = x;};
    void setY(int y) {this->r = y;};
};