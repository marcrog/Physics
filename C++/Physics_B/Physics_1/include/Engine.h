
#include<SDL.h>

class Engine
{
    private:
        SDL_Window* window;
        bool isRunning;
        const char* title;
        int xpos;
        int ypos;
        int width;
        int height;
        int flags;
    
    public:
        SDL_Renderer* renderer;
        Engine(const char* title, int xpos, int ypos, int width, int
                    height, int flags);

        bool init();
        void draw();
        void handleEvent();
        void clean();
        void applyPhysics();
        void drawBall();
        void drawCircle();
        void adjust(int x0, int y0, int* x, int* y);
        int calcY(int* x, int Cx, int Cy, int r, int x0, int y0);
        bool running()
        {
            return isRunning;
        }
};

class Form
{
    public:
        int posx, posy;
        Form(int posx, int posy);
};

class Ball : public Form
{

};

class mySDLManager
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool isRunning;
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
            bool init();
            void clean();
            void handleEvents();
        bool running()
        {
            return isRunning;
        }
};