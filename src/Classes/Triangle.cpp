#include<iostream>
#include"../../include/Engine.h"

//----------------------------------------------------------------------------
//#         TRIANGLE DEFINITIONS

Triangle::Triangle(mySDLManager* manager, float mx, float my ,float tx, float ty)
{
    Triangle::manager = manager;
    Triangle::pos.x = mx;
    Triangle::pos.y = my;
    Triangle::top.x = tx;
    Triangle::top.y = ty;
    Triangle::l = 2*(top.dist(pos) * cosf(30 * (M_PI/180)));
    //std::cout << l;
    Triangle::h = top.dist(pos) + top.dist(pos) * sinf(30*M_PI/180);
    Triangle::right.x = pos.x + l/2;
    Triangle::right.y = top.y - h;
    Triangle::left.x = pos.x - l/2;
    Triangle::left.y = top.y - h;
    //ADJUST POSITIONS
    Utils::adjust(&pos, manager->getHeight());
    Utils::adjust(&top, manager->getHeight());
    Utils::adjust(&left, manager->getHeight());
    Utils::adjust(&right, manager->getHeight());
}


void Triangle::draw()
{
    SDL_SetRenderDrawColor(manager -> getRenderer(), color[0], color[1] , color[2], 255);
    SDL_RenderDrawLineF(manager -> getRenderer(), top.x, top.y, right.x, right.y);
    SDL_RenderDrawLineF(manager -> getRenderer(), top.x, top.y, left.x, left.y);
    SDL_RenderDrawLineF(manager -> getRenderer(), left.x, left.y, right.x, right.y);
}

void Triangle::rotateG(float angolo_dato)
{
    Vector* t = new Vector(manager, pos.x, pos.y, top.x, top.y);
    Vector* r = new Vector(manager, pos.x, pos.y, right.x, right.y);
    Vector* l = new Vector(manager, pos.x, pos.y, left.x, left.y);
    Vector* arr [] = {t, r, l};
    for(int i = 0; i < 3; i++){
       arr[i]->rotateD(angolo_dato);
       t->draw();
       r->draw();
       l->draw();
    }
    top = t->end;
    right = r->end;
    left = l->end;
}

void Triangle::checkCollisions(){}

void Triangle::applyGravity()
{
    acc.y = -1;
}

