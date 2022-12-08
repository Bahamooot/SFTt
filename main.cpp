#include <SDL2/SDL.h>
#include "self_renderer.h"
#include "basic_noise.h"
#include "random_noise.h"
#include "linear_wave_noise.h"
#include "jubog_noise.h"
#include "berlin_noise.h"

int main(void)
{

    int screen_size_x = 1000;
    int screen_size_y = 1000;

    SDL_Window      *window = NULL;
    SDL_Renderer    *sdl_renderer = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(screen_size_x, screen_size_y, 0, &window, &sdl_renderer);

    self_renderer renderer(sdl_renderer, screen_size_x, screen_size_y);
    //renderer.setPixel(*new color(0,0,0,255,250,250));

    bool quit = false;
    //Event handler
    SDL_Event event;
    int smoothness = 0;
    int iterations = 1;
    bool colour = 0;
    int current_noise = 0;
    bool regenerate = 0;
    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &event ) != 0 ) // poll for event
        {

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_g: {
                        basic_noise noise;
                        renderer.renderNoise(*(&noise), colour, smoothness, iterations);
                        current_noise = 0;
                        break;
                    }
                    case SDLK_h: {
                        random_noise noise;
                        renderer.renderNoise(*(&noise), colour, smoothness, iterations);
                        current_noise = 1;
                        break;
                    }
                    case SDLK_j: {
                        linear_wave_noise noise;
                        renderer.renderNoise(*(&noise), colour, smoothness, iterations);
                        current_noise = 2;
                        break;
                    }
                    case SDLK_k: {
                        jubog_noise noise;
                        renderer.renderNoise(*(&noise), colour, smoothness, iterations);
                        current_noise = 3;
                        break;
                    }
                    case SDLK_l: {
                        berlin_noise noise;
                        renderer.renderNoise(*(&noise), colour, smoothness, iterations);
                        current_noise = 4;
                        break;
                    }
                    case SDLK_v: {
                        smoothness--;
                        if (smoothness < 0) {
                            smoothness = 0;
                        }
                        regenerate = 1;
                        break;
                    }
                    case SDLK_b: {
                        smoothness++;
                        regenerate = 1;
                        break;
                    }
                    case SDLK_n: {
                        iterations--;
                        if (iterations < 0) {
                            iterations = 0;
                        }
                        regenerate = 1;
                        break;
                    }
                    case SDLK_m: {
                        iterations++;
                        regenerate = 1;
                        break;
                    }
                    case SDLK_z: {
                        colour = !colour;
                        regenerate = 1;
                        break;
                    }
                    case SDLK_x: {
                        smoothness = 0;
                        regenerate = 1;
                        break;
                    }
                    case SDLK_c: {
                        iterations = 0;
                        regenerate = 1;
                        break;
                    }
                }
            }

            if (regenerate) {
                switch (current_noise) {
                    case 0: {
                        basic_noise noise;
                        renderer.renderNoise(*(&noise), colour, smoothness, iterations);
                        current_noise = 0;
                        break;
                    }
                    case 1: {
                        random_noise noise;
                        renderer.renderNoise(*(&noise), colour, smoothness, iterations);
                        break;
                    }
                    case 2: {
                        linear_wave_noise noise;
                        renderer.renderNoise(*(&noise), colour, smoothness, iterations);
                        break;
                    }
                    case 3: {
                        jubog_noise noise;
                        renderer.renderNoise(*(&noise), colour, smoothness, iterations);
                        break;
                    }
                    case 4: {
                        berlin_noise noise;
                        renderer.renderNoise(*(&noise), colour, smoothness, iterations);
                        break;
                    }
                }
                regenerate = 0;
            }

            //User requests quit
            if( event.type == SDL_QUIT ) // unless player manually quits
            {
                quit = true;
            }
        }
    }

    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return (0);
}


