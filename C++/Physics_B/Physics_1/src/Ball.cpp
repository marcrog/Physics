#include"../include/Ball.h"

Ball::Ball(int xpos, int ypos, int r)
{
    Ball::xpos = xpos;
    Ball::ypos = ypos;
    Ball::r = r;
}

void draw()
{
     /* (x - Cx)^2 + (y - Cy)^2 - r^2 = 0
        y = sqrt(r^2 - (x - Cx)^2) + Cy
     */
    
    
}