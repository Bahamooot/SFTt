//
// Created by Bahamut on 11/28/22.
//

#ifndef SFTT_SELF_RENDERER_H
#define SFTT_SELF_RENDERER_H

#endif //SFTT_SELF_RENDERER_H
#include "SDL.h"
#include "color.h"
#include <vector>


class self_renderer {
private:
    std::vector<color> colors;
public:
    self_renderer(int x, int y);
    void renderArray(SDL_Renderer *renderer);
};

void self_renderer::renderArray(SDL_Renderer *renderer) {
    for (color c : colors) {
        SDL_SetRenderDrawColor(renderer, c.getR(), c.getG(), c.getB(), c.getA());
        SDL_RenderDrawPoint(renderer, c.getX(), c.getY()); //Renders on middle of screen.
    }

    SDL_RenderPresent(renderer);
}

self_renderer::self_renderer(int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            colors.push_back(*new color(25,50,255,255,i,j));
        }
    }
}
