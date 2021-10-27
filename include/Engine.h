
#include<SDL.h>
#include<list>

//----------------------------------------------------------------------------
//                                  Pos
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


//----------------------------------------------------------------------------
//                                  mySDLManager  
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
//                                  Corp
class Corp
{
    public:
        mySDLManager* manager;
        Pos pos, vel, acc;
        float mass;
        int color[3];
        void setColor(int r, int g, int b);
        void update();
        virtual void draw() = 0;
        virtual void checkCollisions() = 0;
        virtual void rotateG(float angle) = 0;
};


//----------------------------------------------------------------------------
//                                     Ball
class Ball : public Corp
{
    private:
        int mHeight, mWidth;
        SDL_Renderer* mRenderer;
        const float drawXIncremet = 1;

    public:
        float r;
        Ball(mySDLManager* manager, float posx, float posy, float r, float velx, float vely,
                float accx, float accy);
        //Delegating Contructors
        Ball(mySDLManager* manager, float posx, float posy, float r, float velx, float vely) : 
                Ball(manager, posx, posy, r, velx, vely, 0, 0){};
        Ball(mySDLManager* manager, float posx, float posy, float r) : 
                Ball(manager, posx, posy, r, 0, 0, 0, 0){};

        void draw();
        float calcY(float* x, float Cx, float Cy, float r, float x0, float y0);
        void adjust(float x0, float y0, float* x, float* y);
        void checkCollisions();
        void rotateG(float angle);
};


//----------------------------------------------------------------------------
//                                 Triangle
class Triangle : public Corp
{
    public:
        Pos top, right, left;
        float l, h;
        Triangle(mySDLManager* manager, Pos mid, Pos top) : 
            Triangle(manager, mid.x, mid.y, top.x, top.y){};
        Triangle(mySDLManager* manager, float mx, float my, float vx, float vy);
        void draw();
        void rotateG(float angle);
        void checkCollisions();
};


//----------------------------------------------------------------------------
//                                  CorpList
class CorpList
{
    private:
        std::list<Corp*> corps;

    public:
        CorpList();
        int size();
        bool add(Corp* b);
        bool remove(Corp* b);
        Corp* getCorp(int i);
        std::list<Corp*> getCorps();
};  


//----------------------------------------------------------------------------
//                                  Engine
class Engine
{ 
    private:
        mySDLManager* manager;
        CorpList corpList;

    public:
        Engine(mySDLManager* manager);
        mySDLManager* getManager();
        bool addCorps(Corp* b);
        bool removeCorp(Corp* b);
        bool removeCorpI(int i);
        CorpList getCorpList();
        void draw();
        void applyPhysics();
        void update();
        void gravity();
};


//----------------------------------------------------------------------------
//                                  Vector
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
//                                  Utils
class Utils
{   
    private:
        Utils(){};
    public:
        static float adjust(float y, float screen_height);
        static void adjust(float* y, float screen_height);
        static void adjust(Pos* p, float screen_height);
};