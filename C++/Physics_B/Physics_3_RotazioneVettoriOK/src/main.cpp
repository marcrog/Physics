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
    manager -> init();
    Triangle* t = new Triangle(manager, 300, 300, 300, 400);  
    Vector* v1 = new Vector(manager, 300, 300, 300, 350);
    Vector* v2 = new Vector(manager, v1->start, v1->end);
    engine->addBall(v1->start.x, v1->start.y, v1->getMag());
    v2 -> setColor(255, 0, 0);
    while (manager -> running())
    {
        frameStart = SDL_GetTicks();

        // [
        //Clear window with balck
        SDL_SetRenderDrawColor(manager -> getRenderer(), 30, 32, 45, 255);
        SDL_RenderClear(manager -> getRenderer());
        //Engine
        v1 -> draw();
        v2 -> rotateD(1);
        v2 -> draw();
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
