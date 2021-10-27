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

bool Engine::addBall(Ball* b)
{  
    return ballsList.add(b);
}

bool Engine::addBall(float posx, float posy, float r)
{   
    return Engine::addBall(posx, posy, r, 0, 0, 0, 0);
}

bool Engine::addBall(float posx, float posy, float r, float velx, float vely)
{
    return Engine::addBall(posx, posy, r, velx, vely, 0, 0);
}

bool Engine::addBall(float posx, float posy, float r, float velx, float vely,
                        float accx, float accy)
{
    Ball* b = new Ball(manager, posx, posy, r, velx, vely, accx, accy);
    return ballsList.add(b);
}

bool Engine::removeBalls(Ball* b)
{   
    return ballsList.remove(b);
}

BallsList Engine::getBallsList()
{
    return ballsList;
}

void Engine::draw()
{
    for(int i = 0; i < ballsList.size(); i++){
        Ball* control = new Ball(manager, ballsList.getBall(i) -> posx, ballsList.getBall(i) -> posy, 10);
        control -> setColor(255 , 0 , 0);
        control->draw();
        ballsList.getBall(i)->draw();
    }
}

void Engine::update()
{
    for(int i = 0; i < ballsList.size(); i++)
        ballsList.getBall(i)->update();
}

void Engine::applyPhysics()
{
    for(int i = 0; i < ballsList.size(); i++){
        Ball* temp = ballsList.getBall(i);
        temp -> update();
        //Engine::checkCollisions(temp, &previusInRender);
    }
}

// void Engine::checkCollisions(Ball* b, bool* previusInRender)
// { 
//     if((b -> posx - b -> r < 0 || b -> posx + b -> r > manager->getWidth()) && previusInRender)
//     {
//         b -> velx *= -1;
//         *previusInRender = false;
//     }
//     else if((b->posy - b -> r < 0 || b ->posy + b -> r > manager->getHeight()) && previusInRender){
//         b -> vely *= -1; 
//         *previusInRender = false;
//     }
//     else if (((b -> posx - b -> r >= 0 + 1 || b -> posx + b -> r <= manager->getWidth() - 1 ) && !previusInRender)
//                 || ((b->posy - b -> r >= 0 + 1 || b ->posy + b -> r <= manager->getHeight() - 1) && !previusInRender))
//         *previusInRender = true;
// }

void Engine::gravity()
{
    for(int i = 0; i < ballsList.size(); i++)
    {
        ballsList.getBall(i) -> accy = -1;
    }
}
