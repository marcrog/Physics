#include<iostream>
#include<SDL.h>
#include"../include/Engine.h"
#include <cstdlib>
#include <ctime>

const float FPS = 0.05;                                     
Uint32 frameStart;
//float x = 892.9833352606; // variabile arbitraria - pixel/s
//float pix_l = 0.000311316; //dimensione pixel

int main()
{
    Engine* engine = new Engine(new mySDLManager("Physics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                    600, 600, 0));
    mySDLManager* manager = engine -> getManager();
    manager->init();
    Corp* b = new Ball(manager, 300, 300, 50);
    Corp* t = new Triangle(manager, 300, 300, 300, 350);
    t->vel.x = 0.1;
    t->acc.x = 0;
    t->vel.y = 0;
    t->acc.y = 0;
    engine -> addCorps(t);
    engine -> addCorps(b);

    while (manager -> running())
    {
        frameStart = SDL_GetTicks();

        // [
        //Clear window with balck
        SDL_SetRenderDrawColor(manager -> getRenderer(), 30, 32, 45, 255);
        SDL_RenderClear(manager -> getRenderer());
        //Engine
        engine->draw();
        t->rotateG(1);
        t->update();
        //Present Render and handle exit
        SDL_RenderPresent(manager -> getRenderer()); 
        manager -> handleEvents();
        // ]

        if(FPS>(SDL_GetTicks()-frameStart))
        {   
            SDL_Delay(FPS-(SDL_GetTicks()-frameStart)); //SDL_Delay pauses the execution.
        }
    }
    manager -> clean();
    return 0;
}
