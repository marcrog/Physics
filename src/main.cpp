#include<iostream>
#include<SDL.h>
#include"../include/Engine.h"
#include <cstdlib>
#include <ctime>

bool exe = true;

const float FPS = 0.05;                                     
Uint32 frameStart;
//float x = 892.9833352606; // variabile arbitraria - pixel/s
//float pix_l = 0.000311316; //dimensione pixel

int main()
{
    mySDLManager* manager = new mySDLManager("Physics Engine", 300, SDL_WINDOWPOS_CENTERED, 
                                        600, 600, 0); 
    manager->init();              
    Engine* engine = new Engine(manager);
    while(exe)
    {
        engine->reset();
        manager->setRunning(true);
        SDL_Event event;
        //---------------                                        
        srand(time(NULL));
        Ball* b = new Ball(manager, 300, 300, 50);
        engine->addCorps(b);
        engine->applyCollisions();
        //engine->applyGravity();
        while (manager -> running())
        {
            frameStart = SDL_GetTicks();
    
            // [
            //Clear window with balck
            SDL_SetRenderDrawColor(manager -> getRenderer(), 30, 32, 45, 255);
            SDL_RenderClear(manager -> getRenderer());
            //Engine
            engine->draw();
            engine->update();
            if(SDL_PollEvent(&event))
            {
                if(event.key.keysym.sym == SDLK_UP)
                {
                    engine->getCorpList().getCorp(0)->fill = true;
                    std::cout << "Ollare";
                }
            }
            //Present Render and handle exit
            SDL_RenderPresent(manager -> getRenderer());
            manager -> handleEvents(&exe);
            // ]
    
            if(FPS>(SDL_GetTicks()-frameStart))
            {   
                SDL_Delay(FPS-(SDL_GetTicks()-frameStart)); //SDL_Delay pauses the execution.
            }
        }
    }
    manager->clean();
    return 0;
}
