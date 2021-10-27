#include"../include/Engine.h"
#include <string>

//----------------------------------------------------------------------------
//#         BALL DEFINITIONS

// Ball::Ball(mySDLManager* manager, int posx, int posy, int r)
// {
//     Ball:Ball(manager, posx, posy, r, 0, 0, 0, 0);
// }

// Ball::Ball(mySDLManager* manager, int posx, int posy, int r, int velx, int vely)
// {
//     Ball:Ball(manager, posx, posy, r, velx, vely, 0, 0);
// }

Ball::Ball(mySDLManager* manager, int posx, int posy, int r, int velx, int vely, 
            int accx, int accy)
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
    int x1, x2, y1, y2;
    int Cx = 0, Cy = 0;

    for(int p = -r; p < r; p += 0.5)
    {
        x1 = p;
        x2 = x1 + 1;
        y1 = Ball::calcY(&x1, Cx, Cy, r, posx, posy);
        y2 = Ball::calcY(&x2, Cx, Cy, r, posx, posy);
        int delta = y2 - y1;

        int ny1 = (mHeight - posy)*2 - y1;
        int ny2 = (mHeight - posy)*2 - y2;
        int ndelta = ny2 - ny1;

        SDL_SetRenderDrawColor(mRenderer, color[0], color[1] , color[2], 255);
        SDL_RenderDrawLine(mRenderer, x1, y1, x1, y1 + delta);
        SDL_RenderDrawLine(mRenderer, x1, ny1, x1, ny1 + ndelta);
    }
}

int Ball::calcY(int* x, int Cx, int Cy, int r, int x0, int y0)
{
    int y = sqrt(pow(r, 2) - pow((*x - Cx), 2)) + Cy;
    if(*x != 0){
        Ball::adjust(x0, y0, x, &y);
        return y;
    }
    else{
        y < 0 ? y = y + 1 : y = y - 1;
        Ball::adjust(x0, y0, x, &y);
        return y;
    }
}

void Ball::adjust(int x0, int y0, int* x, int* y)
{
    *x += x0;
    *y = mHeight - y0 - *y;
}

void Ball::update()
{
    posx += velx; 
    posy += vely;
}

std::string Ball::toString()
{
    std::string result = "";
    return "";
}
