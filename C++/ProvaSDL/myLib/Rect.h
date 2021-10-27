#include<SDL.h>

class Rect
{   
    public:
        double x, y, w, h;
        
        Rect(double x, double y, double w, double h);
        Rect();
        void show();
};