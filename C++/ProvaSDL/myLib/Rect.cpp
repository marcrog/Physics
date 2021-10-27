#include"Rect.h"
#include<SDL.h>

Rect::Rect(double x, double y, double w, double h)
{
    Rect::x = x;
    Rect::y = y;
    Rect::w = w;
    Rect::h = h;
}

Rect::Rect()
{
    Rect::x = 100;
    Rect::y = 100;
    Rect::w = 50;
    Rect::h = 50;
}

