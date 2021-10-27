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
    SDL_SetRenderDrawColor(manager -> getRenderer(), 0, 0 , 255, 255);
    SDL_RenderDrawLineF(manager -> getRenderer(), top.x, top.y, right.x, right.y);
    SDL_RenderDrawLineF(manager -> getRenderer(), top.x, top.y, left.x, left.y);
    SDL_RenderDrawLineF(manager -> getRenderer(), left.x, left.y, right.x, right.y);
}

void Triangle::rotateG(float angolo_dato)
{
    Vector* t = new Vector(manager, mid.x, mid.y, top.x, top.y, false);
    Vector* r = new Vector(manager, mid.x, mid.y, right.x, right.y, false);
    Vector* l = new Vector(manager, mid.x, mid.y, left.x, left.y, false);
    Vector* arr [] = {t, r, l};
    for(int i = 0; i < 3; i++)
    {
       arr[i]->rotateD(angolo_dato);
       arr[i]->draw();
    }
    top = t->end;
    right = r->end;
    left = l->end;
}

