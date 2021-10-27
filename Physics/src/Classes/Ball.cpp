#include"../../include/Engine.h"
#include <string>
#include<iostream>

//----------------------------------------------------------------------------
//#         BALL DEFINITIONS

Ball::Ball(mySDLManager* manager, float posx, float posy, float r, float velx, float vely, 
            float accx, float accy)
{
    Ball::manager = manager;
    Ball::posx = posx;
    Ball::posy = posy;
    Ball::r = r;
    Ball::velx = velx;
    Ball::vely = vely;
    Ball::accx = accx;
    Ball::accy = accy;

    Ball::mHeight = manager -> getHeight();
    Ball::mWidth = manager -> getWidth();
    Ball::mRenderer = manager -> getRenderer();

    Ball::setColor(0, 255, 0);
}

void Ball::setColor(int r, int g, int b)
{
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

void Ball::draw()
{
    float x1, x2, y1, y2;
    float Cx = 0, Cy = 0;

    for(float p = -r; p < r; p += drawXIncremet)
    {
        x1 = p;
        x2 = x1 + drawXIncremet;
        y1 = Ball::calcY(&x1, Cx, Cy, r, posx, posy);
        y2 = Ball::calcY(&x2, Cx, Cy, r, posx, posy);
        int delta = y2 - y1;

        float ny1 = (mHeight - posy)*2 - y1;
        float ny2 = (mHeight - posy)*2 - y2;
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

void Ball::update()
{
    velx += accx;
    vely += accy;
    posx += velx; 
    posy += vely;
    Ball::checkCollisions();
    if(std::abs(velx) < 0.1){
        velx = 0;
        accx = 0;
    }
    if(std::abs(vely) < 0.1)
        vely = 0;
        accy = 0;
}

void Ball::checkCollisions()
{
    float sxEdge = posx - r;
    float dxEdge = posx + r;
    float upEdge = posy + r;
    float dwEdge = posy - r;
    float elasticità = 0;
    if(sxEdge < 0)
    {
        posx = 0 + r + 1;
        velx *= -1;
        velx += elasticità;
    }
    if(dxEdge > manager->getWidth())
    {
        posx = manager->getWidth() - r - 1;
        velx *= -1;
        velx -= elasticità;
    }
    if(dwEdge < 0)
    {
        posy = 0 + r + 1;
        vely *= -1;
        vely += elasticità;
    }
    if(upEdge > manager->getHeight())
    {
        posy = manager -> getHeight() - r - 1;
        vely *= -1;
        vely -= elasticità;
    }
}


std::string Ball::toString()
{
    std::string result = "";
    return "";
}