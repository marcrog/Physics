#include"../../include/Engine.h"
#include <string>
#include<iostream>

//----------------------------------------------------------------------------
//#         CORPS DEFINITIONS

void Corp::setColor(int r, int g, int b)
{
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

void Corp::setColorF(int r, int g, int b)
{
    colorF[0] = r;
    colorF[1] = g;
    colorF[2] = b;
}

void Corp::update()
{
    vel.x += acc.x;
    vel.y += acc.y;
    pos.x += vel.x; 
    pos.y += vel.y;
}
