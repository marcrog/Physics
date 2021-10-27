#include<iostream>
#include<SDL.h>
#include"../include/Engine.h"

int main()
{
    Engine* engine = new Engine("Physics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                    600, 600, 0);
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;                                    
    Uint32 frameStart;
    int frameTime;

    engine -> init();
    while (engine -> running())
    {
        frameStart = SDL_GetTicks();

        // [
        //Clear window with balck
        SDL_SetRenderDrawColor(engine -> renderer, 0, 0, 0, 255);
        SDL_RenderClear(engine -> renderer);

        //Draw a
        engine -> drawCircle();
        SDL_RenderPresent(engine -> renderer);
        // ]
        engine -> handleEvent();


        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    engine -> clean();
    return 0;
}