//
// Created by Bahamut on 11/28/22.
//

#ifndef SFTT_SELF_RENDERER_H
#define SFTT_SELF_RENDERER_H

#endif //SFTT_SELF_RENDERER_H
#include "SDL.h"
#include "color.h"
#include <vector>
#include "perlin_noise.h"

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
    void randomShitPixel(int seed);
    void randomRandompixel();

    void randomWavepixel();

    void random2DWavepixel(bool collor);

    void random2DShitTerrain(bool yes, int smoothness);
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

void self_renderer::randomShitPixel(int seed) {
    perlin_noise perlin;
    int * coco = perlin.generateShitNoise(getSize(), seed);
    for (int i = 0; i < getSize(); i++) {
        color *c = &colors[i];
        c->setRGBA(coco[i],coco[i], coco[i],255);
    }
    display();
}

void self_renderer::randomRandompixel() {
    perlin_noise perlin;
    int * coco = perlin.generateRandomNoise(getSize());
    for (int i = 0; i < getSize(); i++) {
        color *c = &colors[i];
        c->setRGBA(coco[i],coco[i], coco[i],255);
    }
    display();
}

void self_renderer::randomWavepixel() {
    perlin_noise perlin;
    int * coco = perlin.generateWaveNoise(getSize());
    for (int i = 0; i < getSize(); i++) {
        color *c = &colors[i];
        c->setRGBA(coco[i],coco[i], coco[i],255);
    }
    display();
}

void self_renderer::random2DWavepixel(bool collor) {
    perlin_noise perlin;
    int * coco = perlin.generate2DWaveNoiseRight(getSize(), screen_size_x);
    if (collor) {
        for (int i = 0; i < getSize(); i++) {
            if(coco[i] > 200) {
                color *c = &colors[i];
                c->setRGBA(200, 200, 200, 255);
            } else if (coco[i] < 100){
                color *c = &colors[i];
                c->setRGBA(100, 100, 200, 255);
            } else {
                color *c = &colors[i];
                c->setRGBA(coco[i], coco[i], coco[i], 255);
            }
        }
    }
    else {
        for (int i = 0; i < getSize(); i++) {
            color *c = &colors[i];
            c->setRGBA(coco[i], coco[i], coco[i], 255);
        }
    }
    display();
}

void self_renderer::random2DShitTerrain(bool yes, int smoothness) {
    perlin_noise perlin;
    int * coco = perlin.generate2DWaveNoiseLeft(getSize(), screen_size_x);
    int * coco2 = perlin.generate2DWaveNoiseRight(getSize(), screen_size_x);
    int * coco3 = perlin.generate2DWaveNoiseRight(getSize(), screen_size_x);
    for (int i = 0; i < screen_size; i++) {
        coco[i] = (coco[i] + coco2[i] + coco3[i])/3;
    }
    for (int i = 0; i < smoothness; i++) {
        coco = perlin.generateAverageNoise(coco, screen_size_x, screen_size);
    }
    if (yes) {
        for (int i = 0; i < getSize(); i++) {
            if (coco[i] < 50) {
                color *c = &colors[i];
                c->setRGBA(25,65,131,255);
            } else if (coco[i] < 100){
                color *c = &colors[i];
                c->setRGBA(35,86,173,255);
            } else if (coco[i] < 125){
                color *c = &colors[i];
                c->setRGBA(238,207,123,255);
            } else if (coco[i] < 140){
                color *c = &colors[i];
                c->setRGBA(122,197,73,255);
            } else if (coco[i] < 180){
                color *c = &colors[i];
                c->setRGBA(93,141,57,255);
            }else if (coco[i] < 220){
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
            c->setRGBA(coco[i], coco[i], coco[i], 255);
        }
    }
    display();
}