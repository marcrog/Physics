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
