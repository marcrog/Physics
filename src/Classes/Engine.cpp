#include"../../include/Engine.h"
#include<SDL.h>
#include<iostream>

//----------------------------------------------------------------------------
//#         ENGINE DEFINITIONS

Engine::Engine(mySDLManager* manager){
    Engine::manager = manager;
    initial = this;
};

bool Engine::addCorps(Corp* c)
{  
    return corpList.add(c);
}

bool Engine::removeCorp(Corp* b)
{   
    return corpList.remove(b);
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
    {
        Corp* temp = corpList.getCorp(i);
        if(collisions)
            temp->checkCollisions();
        if(gravity)
            temp->applyGravity();
        temp->update();
    }    
}

void Engine::reset()
{
    Engine::gravity = initial->gravity;
    Engine::collisions = initial->collisions;
    for(int i = 0; i < corpList.size(); i++)
        corpList.remove(corpList.getCorp(i));
    Engine::corpList = initial->corpList;

}
