#include"../../include/Engine.h"
#include <string>
#include<iostream>

//----------------------------------------------------------------------------
//#         BALL DEFINITIONS

Ball::Ball(mySDLManager* manager, float posx, float posy, float r, float velx, float vely, 
            float accx, float accy)
{
    Ball::manager = manager;
    Ball::pos.x = posx;
    Ball::pos.y = posy;
    Ball::r = r;
    Ball::vel.x = velx;
    Ball::vel.y = vely;
    Ball::acc.x = accx;
    Ball::acc.y = accy;
    Ball::mHeight = manager -> getHeight();
    Ball::mWidth = manager -> getWidth();
    Ball::mRenderer = manager -> getRenderer();

    Ball::setColor(0, 255, 0);
}

void Ball::draw()
{
    float x1, x2, y1, y2;
    float Cx = 0, Cy = 0;

    for(float p = -r; p < r; p += drawXIncremet)
    {
        x1 = p;
        x2 = x1 + drawXIncremet;
        y1 = Ball::calcY(&x1, Cx, Cy, r, pos.x, pos.y);
        y2 = Ball::calcY(&x2, Cx, Cy, r, pos.x, pos.y);
        int delta = y2 - y1;

        float ny1 = (mHeight - pos.y)*2 - y1;
        float ny2 = (mHeight - pos.y)*2 - y2;
        float ndelta = ny2 - ny1;

        SDL_SetRenderDrawColor(mRenderer, color[0], color[1] , color[2], 255);
        SDL_RenderDrawLineF(mRenderer, x1, y1, x1, y1 + delta);
        SDL_RenderDrawLineF(mRenderer, x1, ny1, x1, ny1 + ndelta);
    }
}

float Ball::calcY(float* x, float Cx, float Cy, float r, float x0, float y0)
{
    float y = sqrt(pow(r, 2) - pow((*x - Cx), 2)) + Cy;
    float delta = (sqrt(pow(r, 2) - pow((0 - Cx), 2)) + Cy) - 
            (sqrt(pow(r, 2) - pow((drawXIncremet - Cx), 2)) + Cy);
    if(*x != 0){
        Ball::adjust(x0, y0, x, &y);
        return y;
    }
    else{
        y < 0 ? y = y + delta : y = y - delta;
        Ball::adjust(x0, y0, x, &y);
        return y;
    }
}

void Ball::adjust(float x0, float y0, float* x, float* y)
{
    *x += x0;
    *y = mHeight - y0 - *y;
}

void Ball::checkCollisions()
{
    float sxEdge = pos.x - r;
    float dxEdge = pos.x + r;
    float upEdge = pos.y + r;
    float dwEdge = pos.y - r;
    float elasticit?? = 0;
    if(sxEdge < 0)
    {
        pos.x = 0 + r + 1;
        vel.x *= -1;
        vel.x += elasticit??;
    }
    if(dxEdge > manager->getWidth())
    {
        pos.x = manager->getWidth() - r - 1;
        vel.x *= -1;
        vel.x -= elasticit??;
    }
    if(dwEdge < 0)
    {
        pos.y = 0 + r + 1;
        vel.y *= -1;
        vel.y += elasticit??;
    }
    if(upEdge > manager->getHeight())
    {
        pos.y = manager -> getHeight() - r - 1;
        vel.y *= -1;
        vel.y -= elasticit??;
    }
}

void Ball::rotateG(float angle){}