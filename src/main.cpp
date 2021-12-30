#include<iostream>
#include<SDL.h>
#include"../include/Engine.h"
#include <cstdlib>
#include <ctime>

const float FPS = 0.05;                                     
Uint32 frameStart;
bool exe = true;

SDL_Event event;

int main()
{
    mySDLManager* manager = new mySDLManager("Physics Engine", 300, SDL_WINDOWPOS_CENTERED, 
                                        1000, 600, 0); 
    manager->init();              
    Engine* engine = new Engine(manager);
    engine->collisions = true;
    engine->gravity = false;
    while(exe)
    {
        engine->reset();
        manager->isRunning = true;
        //---------------                                        
        srand(time(NULL));
        Ball* b = new Ball(manager, 950, 300, 50, 25, 0);
        std::list <Vector*> v;

        for(int i=0; i < 1000; i+=25)
            v.push_back(new Vector(manager, i, 0, i, manager->height));
        
        b->fill = true;
        b->setColorF(0, 255, 0);
        b->setColor(255, 0, 0);
        engine->addCorps(b);
        while (manager -> running())
        {
            frameStart = SDL_GetTicks();
    
            // [
            //Clear window with balck
            SDL_SetRenderDrawColor(manager -> renderer, 30, 32, 45, 255);
            SDL_RenderClear(manager -> renderer);
            //Engine
            for(Vector* a : v)
                a->draw();
            engine->draw();                
            engine->update();
            if(SDL_PollEvent(&event))
            {
                if(event.key.keysym.sym == SDLK_UP)
                {
                    engine->corpList.getCorp(0)->fill = true;
                    std::cout << "Ollare";
                }
            }

            //Present Render and handle exit
            SDL_RenderPresent(manager -> renderer);
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