#include <SDL2/SDL.h>
#include "self_renderer.h"
#include "basic_noise.h"
#include "random_noise.h"
#include "linear_wave_noise.h"
#include "jubog_noise.h"
#include "berlin_noise.h"

int main(void)
{
    // Screen size
    int screen_size_x = 500;
    int screen_size_y = 500;

    // Setting up the SDL window and renderer
    SDL_Window      *window = NULL;
    SDL_Renderer    *sdl_renderer = NULL;

    // Initialize the window with the renderer
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(screen_size_x, screen_size_y, 0, &window, &sdl_renderer);

    // Making our own renderer so we can render custom data
    self_renderer renderer(sdl_renderer, screen_size_x, screen_size_y);


    //Event handler
    SDL_Event event;

    // Generation parameters for keyboard inputs
    int smoothness = 0;
    int iterations = 1;
    bool colour = 0;
    int current_noise = 0;
    bool regenerate = 0;

    bool quit = false;
    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &event ) != 0 ) // poll for event
        {
            // Generate different types of noise based on key press
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
            // If a key is pressed beforehand to change color, increase soothness, etc, then regenerate the noise with
            // the new parameters
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
    // bye bye code
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return (0);
}


