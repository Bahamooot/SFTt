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
    // Color array of each pixel on the screen
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

// displays the color array
void self_renderer::display() {
    for (color c : colors) {
        // for every color buffer that color with it's rgba values
        SDL_SetRenderDrawColor(renderer, c.getR(), c.getG(), c.getB(), c.getA());
        SDL_RenderDrawPoint(renderer, c.getX(), c.getY());
    }
    // tells to render the previous values sent to the buffer
    SDL_RenderPresent(renderer);
}
// constructor
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
// set a specific pixel, unused
void self_renderer::setPixel(color c) {
    color *coco = &colors[c.getY() + (c.getX()* screen_size_x)];
    coco->setRGBA(c.getR(), c.getG(), c.getB(), c.getA());
    display();
}
// get screen size/color vector size, same thing
int self_renderer::getSize() {
    return colors.size();
}
// get color at index, unused
color * self_renderer::getPixel(int index) {
    return &colors[index];
}
// renders any type of noise
void self_renderer::renderNoise(noise &noize, bool color_on, int smoothness, int iterations) {
    noise *noise = &noize;
    // cpp file that handles smoothing
    average2D average2D;
    // vector of multiple noises for iterations
    std::vector<std::vector<int>> noises;
    // if iterations are invalid set to 1
    if(iterations <= 0 ) iterations = 1;
    // make new iterations of noise
    for (int i = 0; i < iterations; i++) {
        noises.push_back(noise->generate(screen_size_x, screen_size_y));
    }
    // combine the iterations
    if (iterations > 1) {
        for (int i = 1; i < screen_size; i++) {
            int total = 0;
            for (int j = 0; j < noises.size(); j++) {
                total += noises[j][i];
            }
            noises[0][i] = total / iterations;
        }
    }
    // smooth out the current noise
    for (int i = 0; i < smoothness; i++) {
        noises = average2D.average(noises, screen_size_x, screen_size_y);
    }
    // sets the values based on height of noise
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
    // sets the values to default black and white gradient
    } else {
        for (int i = 0; i < getSize(); i++) {
            color *c = &colors[i];
            c->setRGBA(noises[0][i], noises[0][i], noises[0][i], 255);
        }
    }
    // displays the color array
    display();
}
