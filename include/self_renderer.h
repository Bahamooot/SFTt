//
// Created by Bahamut on 11/28/22.
//

#ifndef SFTT_SELF_RENDERER_H
#define SFTT_SELF_RENDERER_H

#endif //SFTT_SELF_RENDERER_H
#include "SDL.h"
#include "color.h"
#include <vector>
#include "interface/noise.h"
#include "basic_noise.h"
#include "average2D.h"

class self_renderer {
private:
    int screen_size_x;
    int screen_size_y;
    int screen_size;
    std::vector<color> colors;
    SDL_Renderer *renderer = nullptr;
public:
    self_renderer(SDL_Renderer *ren, int x, int y);
    void display();
    void setPixel(color c);
    int getSize();

    color *getPixel(int index);
    void renderNoise(noise &noize, bool color, int smoothness, int iterations);

    std::vector<int> generate(int size_x, int size_y);
};

void self_renderer::display() {
    for (color c : colors) {
        SDL_SetRenderDrawColor(renderer, c.getR(), c.getG(), c.getB(), c.getA());
        SDL_RenderDrawPoint(renderer, c.getX(), c.getY());
    }

    SDL_RenderPresent(renderer);
}

self_renderer::self_renderer(SDL_Renderer *renderer, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            colors.push_back(*new color(255,255,255,255,i,j));
        }
    }
    screen_size_x = x;
    screen_size_y = y;
    screen_size = x * y;
    this->renderer = renderer;
    display();
}

void self_renderer::setPixel(color c) {
    color *coco = &colors[c.getY() + (c.getX()* screen_size_x)];
    coco->setRGBA(c.getR(), c.getG(), c.getB(), c.getA());
    display();
}

int self_renderer::getSize() {
    return colors.size();
}

color * self_renderer::getPixel(int index) {
    return &colors[index];
}

void self_renderer::renderNoise(noise &noize, bool color_on, int smoothness, int iterations) {
    noise *noise = &noize;
    average2D average2D;
    std::vector<std::vector<int>> noises;
    if(iterations <= 0 ) iterations = 1;
    for (int i = 0; i < iterations; i++) {
        noises.push_back(noise->generate(screen_size_x, screen_size_y));
    }
    if (iterations > 1) {
        for (int i = 1; i < screen_size; i++) {
            int total = 0;
            for (int j = 0; j < noises.size(); j++) {
                total += noises[j][i];
            }
            noises[0][i] = total / iterations;
        }
    }
    for (int i = 0; i < smoothness; i++) {
        noises = average2D.average(noises, screen_size_x, screen_size_y);
    }
    if (color_on) {
        for (int i = 0; i < getSize(); i++) {
            if (noises[0][i] < 50) {
                color * c = &colors[i];
                c->setRGBA(25,65,131,255);
            } else if (noises[0][i] < 100){
                color *c = &colors[i];
                c->setRGBA(35,86,173,255);
            } else if (noises[0][i] < 125){
                color *c = &colors[i];
                c->setRGBA(238,207,123,255);
            } else if (noises[0][i] < 140){
                color *c = &colors[i];
                c->setRGBA(122,197,73,255);
            } else if (noises[0][i] < 180){
                color *c = &colors[i];
                c->setRGBA(93,141,57,255);
            }else if (noises[0][i] < 220){
                color *c = &colors[i];
                c->setRGBA(113,102,92,255);
            } else {
                color *c = &colors[i];
                c->setRGBA(250,226,204,255);
            }
        }
    } else {
        for (int i = 0; i < getSize(); i++) {
            color *c = &colors[i];
            c->setRGBA(noises[0][i], noises[0][i], noises[0][i], 255);
        }
    }
    display();
}

