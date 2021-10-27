
#include<SDL.h>
#include<list>

struct Pos
{
    float x;
    float y;
    float dist(Pos that)
    {
        float cx = abs(that.x - x);
        float cy = abs(that.y - y); 
        return sqrtf(powf(cx, 2) + powf(cy, 2));
    }
};


class mySDLManager
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        const char* title;
        int xpos;
        int ypos;
        int width;
        int height;
        int flags;
        bool isRunning; 

        public:
            mySDLManager(const char* title, int xpos, int ypos, int width, int
                    height, int flags);
            SDL_Renderer* getRenderer();
            int getWidth();
            int getHeight();
            bool init();
            void clean();
            void handleEvents();
        bool running()
        {
            return isRunning;
        }
};


//----------------------------------------------------------------------------

class Ball 
{
    private:
        mySDLManager* manager;
        int mHeight, mWidth;
        SDL_Renderer* mRenderer;
        const float drawXIncremet = 1;

    public:
        float posx, posy, r, mass;
        float velx, vely, accx, accy;
        int color[3]; 
        Ball(mySDLManager* manager, float posx, float posy, float r, float velx, float vely,
                float accx, float accy);
        //Delegating Contructors
        Ball(mySDLManager* manager, float posx, float posy, float r, float velx, float vely) : 
                Ball(manager, posx, posy, r, velx, vely, 0, 0){};
        Ball(mySDLManager* manager, float posx, float posy, float r) : 
                Ball(manager, posx, posy, r, 0, 0, 0, 0){};

        void setColor(int r, int g, int b);
        void draw();
        float calcY(float* x, float Cx, float Cy, float r, float x0, float y0);
        void adjust(float x0, float y0, float* x, float* y);
        void update();
        void checkCollisions();
        std::string toString();
};


//----------------------------------------------------------------------------

class BallsList
{
    private:
        std::list<Ball*> balls;

    public:
        BallsList();
        int size();
        bool add(Ball* b);
        bool remove(Ball* b);
        Ball* getBall(int i);
        std::list<Ball*> getBalls();
};  


//----------------------------------------------------------------------------

class Engine
{ 
    private:
        mySDLManager* manager;
        BallsList ballsList;

    public:
        Engine(mySDLManager* manager);
        mySDLManager* getManager();
        bool addBall(Ball* b);
        bool addBall(float posx, float posy, float r);
        bool addBall(float posx, float posy, float r, float velx, float vely);
        bool addBall(float posx, float posy, float r, float velx, float vely, float accx, float accy);
        bool removeBalls(Ball* b);
        BallsList getBallsList();
        void draw();
        void applyPhysics();
        void update();
        //void checkCollisions(Ball* b, bool* previusInRender);
        void gravity();
};

//----------------------------------------------------------------------------

class Vector
{
    private:
        mySDLManager* manager;
        float mag, compx, compy;
        bool adjust;
        int color[3]; 
    
    public:
        Pos start, end;
        float angle;
        Vector(mySDLManager* manager, Pos start, Pos end) :
            Vector(manager, start.x, start.y, end.x, end.y, false){};
        Vector(mySDLManager* manager, Pos start, Pos end, float adjust) :
            Vector(manager, start.x, start.y, end.x, end.y, adjust){};
        Vector(mySDLManager* manager, float start_x, float start_y, float end_x, float end_y) :
            Vector(manager, start_x, start_y, end_x, end_y, false){};
        Vector(mySDLManager* manager, float start_x, float start_y, float end_x, float end_y, bool adjust);
        void setColor(int r, int g, int b);
        float getMag();
        float getAngle();
        float getAngleD();
        float getMag_x();
        float getMag_y();
        void draw();
        void toString();
        void rotateD(float angle);
        Vector* moove(float new_x, float new_y);
};

//----------------------------------------------------------------------------

class Triangle
{
    private:
        mySDLManager* manager;
        Pos mid, top, right, left;
        float l, h;
        int color[3];

    public:
        Triangle(mySDLManager* manager, Pos top, Pos mid);
        Triangle(mySDLManager* manager, float mx, float my, float vx, float vy);
        void setColor(int r, int g, int b);
        void draw();
        void rotateG(float angle);
};

//----------------------------------------------------------------------------

class Utils
{   
    private:
        Utils(){};
    public:
        static float adjust(float y, float screen_height);
        static void adjust(float* y, float screen_height);
        static void adjust(Pos* p, float screen_height);
};