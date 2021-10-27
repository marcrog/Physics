#include"../../include/Engine.h"
#include<iostream>

//----------------------------------------------------------------------------
//#         VECTOR DEFINITIONS

Vector::Vector(mySDLManager* manager, float start_x, float start_y, float end_x, float end_y)
{
    Pos start_, end_;
    start_.x = start_x;
    start_.y = start_y;
    end_.x = end_x;
    end_.y = end_y;
    //---------------
    Vector::manager = manager;
    Vector::start = start_;
    Vector::end = end_;
    /*getMag_x/y da sola prende anche il segno, 
    compx/y sono invece positvi */
    Vector::compx = abs(getMag_x());
    Vector::compy = abs(getMag_y());
    Vector::mag = getMag();
    Vector::angle = getAngle();
    Vector::setColor(0, 0, 255); 
}

void Vector::setColor(int r, int g, int b)
{
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

void Vector::draw()
{
    SDL_SetRenderDrawColor(manager -> getRenderer(), color[0], color[1], color[2], 255);
    SDL_RenderDrawLineF(manager->getRenderer(), start.x, Utils::adjust(start.y, manager->getHeight()) , end.x, Utils::adjust(end.y, manager->getHeight()));
}

float Vector::getMag_x()
{
    return end.x - start.x;
}

float Vector::getMag_y()
{
    return end.y - start.y;
}

float Vector::getMag()
{
    return sqrtf(powf(compx, 2) + powf(compy, 2));
}

float Vector::getAngle()
{
    float asin_arg = getMag_x()/getMag();
    //Controllo errori del tipo asin_arg == 1.00001
    if(abs(asin_arg) - 1 > 0 && abs(asin_arg) - 1 < 1)
        asin_arg > 0 ? asin_arg = 1 : asin_arg = -1;

    if(asinf(asin_arg) == 0)
    {
        if(end.y > start.y)
            return 0;
        else 
            return M_PI;
    }
    else if (end.y < start.y)
        return M_PI - asin(asin_arg);
    else
        return asin(asin_arg);
}

float Vector::getAngleD()
{
    return (getAngle()*180)/M_PI;
}

Vector* Vector::moove(float new_x, float new_y)
{
    Pos new_start;
    new_start.x = new_x;
    new_start.y = new_y;
    Pos new_end;
    new_end.x = new_start.x + getMag_x();
    new_end.y = new_start.y + getMag_y(); 
    Vector* result = new Vector(manager, new_start, new_end);
    return result;
}

void Vector::rotateD(float angolo_dato)
{
    Vector* temp = new Vector(manager, start.x, start.y, start.x, start.y + mag);
    float v_angle = angolo_dato + getAngleD();
    float omega = (180 - v_angle) / 2;
    float i = 2*(getMag() * cosf(omega*(M_PI/180)));
    float delta_x = i * sinf(omega*(M_PI/180));
    float delta_y = i * cosf(omega*(M_PI/180));
    temp -> end.x += delta_x;
    temp -> end.y -= delta_y;
    end.x = temp -> end.x;
    end.y = temp -> end.y;
}

void Vector::toString()
{
    std::cout << start.x << ", " << start.y << " -- " << end.x << ", " << end.y << std::endl;
}