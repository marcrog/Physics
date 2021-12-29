#include"../../include/Engine.h"
#include <string>
#include<iostream>
#include <chrono>
#include<thread>

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
    Ball::mHeight = manager -> height;
    Ball::mWidth = manager -> width;
    Ball::mRenderer = manager -> renderer;
    Ball::fill = false;
    Ball::setColor(0, 255, 0);
    Ball::setColorF(0, 0, 255);
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
        if(fill && (x1 != -r + pos.x && x1 != r - 1 + pos.x))
        {
            SDL_SetRenderDrawColor(mRenderer, colorF[0], colorF[1] , colorF[2], 255);
            if(x1 < pos.x)
                SDL_RenderDrawLineF(mRenderer, x1, y1 + 1, x1, ny1 - 1);
            else if(x1 > pos.x)
                SDL_RenderDrawLineF(mRenderer, x1, y1 + delta + 1, x1, ny1 + ndelta - 1);
            else
                SDL_RenderDrawLineF(mRenderer, x1, y1 + delta + 1, x1, ny1 - 1);
        }
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
    float elasticità = -1;
    if(sxEdge < 0)
    {
        pos.x = 0 + r + 1;
        vel.x *= -1;
        //acc.x *= -1;
        vel.x += elasticità;
    }
    if(dxEdge > manager->width)
    {
        pos.x = manager->width - r - 1;
        vel.x *= -1;
        //acc.x *= -1;
        vel.x -= elasticità;
    }
    if(dwEdge < 0)
    {
        pos.y = 0 + r + 1;
        vel.y *= -1;
        //acc.y *= -1;
        vel.y += elasticità;
    }
    if(upEdge > manager->height)
    {
        pos.y = manager -> height - r - 1;
        vel.y *= -1;
        //acc.y *= -1;
        vel.y -= elasticità;
    }
}

void Ball::applyGravity()
{
    acc.y = -1;
}

void Ball::rotateG(float angle){}

void Ball::followMouse()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        if(event.type == SDL_MOUSEBUTTONDOWN)
            fill = true;
    }
}