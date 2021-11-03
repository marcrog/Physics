#include"../../include/Engine.h"
#include<SDL.h>
#include<iostream>

//----------------------------------------------------------------------------
//#         ENGINE DEFINITIONS

Engine::Engine(mySDLManager* manager){
    Engine::manager = manager;
};

mySDLManager* Engine::getManager()
{
    return manager;
}

bool Engine::addCorps(Corp* c)
{  
    return corpList.add(c);
}

bool Engine::removeCorp(Corp* b)
{   
    return corpList.remove(b);
}

CorpList Engine::getCorpList()
{
    return corpList;
}

Corp* Engine::getCorpI(int i)
{
    return corpList.getCorp(i);
}

void Engine::draw()
{
    for(int i = 0; i < corpList.size(); i++){
        corpList.getCorp(i)->draw();
    }
}

void Engine::update()
{
    for(int i = 0; i < corpList.size(); i++)
        corpList.getCorp(i)->update();
}

void Engine::applyPhysics()
{
    for(int i = 0; i < corpList.size(); i++){
        Corp* temp = corpList.getCorp(i);
        temp -> update();
        //Engine::checkCollisions(temp, &previusInRender);
    }
}

void Engine::gravity()
{
    for(int i = 0; i < corpList.size(); i++)
    {
        corpList.getCorp(i) -> acc.y = -1;
    }
}

//--------------------------------------------------------------------------------------------
void mainLoop(Engine* engine, mySDLManager* manager)
{
    const float FPS = 0.05;                                     
    Uint32 frameStart;
    while (manager -> running())
    {
        frameStart = SDL_GetTicks();

        // [
        //Clear window with balck
        SDL_SetRenderDrawColor(manager -> getRenderer(), 30, 32, 45, 255);
        SDL_RenderClear(manager -> getRenderer());
        engine->draw();
        engine->getCorpI(0)->rotateG(-1);
        //Present Render and handle exit
        SDL_RenderPresent(manager -> getRenderer()); 
        manager -> handleEvents();
        // ]

        if(FPS>(SDL_GetTicks()-frameStart))
        {   
            SDL_Delay(FPS-(SDL_GetTicks()-frameStart)); //SDL_Delay pauses the execution.
        }
    }
}
