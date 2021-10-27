#include"../../include/Engine.h"

float Utils::adjust(float y, float screen_height)
{
    return screen_height - y;
}

void Utils::adjust(float* y, float screen_height)
{
    *y = screen_height - *y;
}

void Utils::adjust(Pos* p, float screen_height)
{
    p -> y = screen_height - p -> y;
}