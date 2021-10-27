#include<iostream>
#include"../../include/Engine.h"

//----------------------------------------------------------------------------
//#         TRIANGLE DEFINITIONS

Triangle::Triangle(mySDLManager* manager, float mx, float my ,float tx, float ty)
{
    Triangle::manager = manager;
    Triangle::mid.x = mx;
    Triangle::mid.y = my;
    Triangle::top.x = tx;
    Triangle::top.y = ty;
    Triangle::l = 2*(top.dist(mid) * cosf(30 * (M_PI/180)));
    //std::cout << l;
    Triangle::h = top.dist(mid) + top.dist(mid) * sinf(30*M_PI/180);
    Triangle::right.x = mid.x + l/2;
    Triangle::right.y = top.y - h;
    Triangle::left.x = mid.x - l/2;
    Triangle::left.y = top.y - h;
    //ADJUST POSITIONS
    Utils::adjust(&mid, manager->getHeight());
    Utils::adjust(&top, manager->getHeight());
    Utils::adjust(&left, manager->getHeight());
    Utils::adjust(&right, manager->getHeight());
}


void Triangle::draw()
{
    struct Pos ps [4] = {top, mid, right, left};
    SDL_SetRenderDrawColor(manager -> getRenderer(), 0, 0 , 255, 255);
    SDL_RenderDrawLineF(manager -> getRenderer(), ps[0].x, ps[0].y, ps[2].x, ps[2].y);
    SDL_RenderDrawLineF(manager -> getRenderer(), ps[0].x, ps[0].y, ps[3].x, ps[3].y);
    SDL_RenderDrawLineF(manager -> getRenderer(), ps[3].x, ps[3].y, ps[2].x, ps[2].y);
}

