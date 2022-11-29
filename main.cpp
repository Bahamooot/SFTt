#include <stdlib.h>
#include <SDL2/SDL.h>
#include "interface/self_renderer.h"

int main(void)
{

    int ScreenSizeX = 500;
    int ScreenSizeY = 500;

    SDL_Window      *win = NULL;
    SDL_Renderer    *ren = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(ScreenSizeX, ScreenSizeY, 0, &win, &ren);

    self_renderer renderer(ScreenSizeX, ScreenSizeY);
    renderer.renderArray(ren);
    bool quit = false;
    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit )
    {


        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) // poll for event
        {
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


