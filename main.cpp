#include <SDL2/SDL.h>
#include "interface/self_renderer.h"

int main(void)
{

    int ScreenSizeX = 800;
    int ScreenSizeY = 800;

    SDL_Window      *win = NULL;
    SDL_Renderer    *ren = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(ScreenSizeX, ScreenSizeY, 0, &win, &ren);

    self_renderer renderer(ren, ScreenSizeX, ScreenSizeY);
    //renderer.setPixel(*new color(0,0,0,255,250,250));

    bool quit = false;
    //Event handler
    SDL_Event e;
    int seed = 0;
    //While application is running
    while( !quit )
    {


        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) // poll for event
        {

            switch (e.type) {
                case SDL_KEYDOWN:
                    renderer.random2DShitTerrain(1,7);
                    seed++;
                    break;
            }

            //User requests quit
            if( e.type == SDL_QUIT ) // unless player manually quits
            {
                quit = true;
            }
        }
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return (0);
}


