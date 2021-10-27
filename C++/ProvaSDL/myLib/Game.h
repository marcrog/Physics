#include<SDL.h>
#include"Rect.h"

class Game
{
    private:
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        bool m_bRunning;
    
    public:
        Game();

        bool init(const char* title, int xpos, int ypos, int width, int
                    height, int flags);
        void draw();
        void handleEvent();
        void clean();
        void physic();

        bool running()
        {
            return m_bRunning;
        }
};
