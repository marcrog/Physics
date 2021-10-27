#include<iostream>
#include<../include/Engine.h>

//----------------------------------------------------------------------------
//#         BALLSLIST DEFINITIONS

BallsList::BallsList(){}

int BallsList::size()
{
    int result = 0;
    for(auto it = balls.begin(); it != balls.end(); it++)
        result++;
    return result;
}

bool BallsList::add(Ball* b)
{
    int start_size = BallsList::size();
    balls.push_back(b);
    if(BallsList::size() == start_size + 1)
        return true;
    else
        return false;
}

bool BallsList::remove(Ball* b)
{
    int start_size = BallsList::size();
    balls.remove(b);
    if(BallsList::size() == start_size - 1)
        return true;
    else
        return false;
}

std::list<Ball*> BallsList::getBalls()
{
    return balls;
}

Ball* BallsList::getBall(int i)
{
    int j = 0;
    for(auto it = balls.begin(); it != balls.end(); it++)
    {
        if(j == i)
            return *it;
        j++;
    }
    return NULL;
}