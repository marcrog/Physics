
#include<SDL.h>
#include<list>

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
    
    public:
        int posx, posy, r;
        int velx, vely, accx, accy;
        int color[3]; 
        Ball(mySDLManager* manager, int posx, int posy, int r, int velx, int vely,
                int accx, int accy);
        //Delegating Contructors
        Ball(mySDLManager* manager, int posx, int posy, int r, int velx, int vely) : 
                Ball(manager, posx, posy, r, velx, vely, 0, 0){};
        Ball(mySDLManager* manager, int posx, int posy, int r) : 
                Ball(manager, posx, posy, r, 0, 0, 0, 0){};

        void setColor(int r, int g, int b);
        void draw();
        int calcY(int* x, int Cx, int Cy, int r, int x0, int y0);
        void adjust(int x0, int y0, int* x, int* y);
        void update();
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
        bool addBall(int posx, int posy, int r);
        bool addBall(int posx, int posy, int r, int velx, int vely);
        bool addBall(int posx, int posy, int r, int velx, int vely, int accx, int accy);
        bool removeBalls(Ball* b);
        BallsList getBallsList();
        void draw();
        void applyPhysics();
        void update();
        void checkCollisions(Ball* b, bool* previusInRender);
        void gravity();
};
