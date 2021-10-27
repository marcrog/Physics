#include"../include/Engine.h"
#include<SDL.h>
#include<iostream>

Engine::Engine(const char* title, int xpos, int ypos, int width, int
                    height, int flags)
{
    Engine::title = title;
    Engine::xpos = xpos;
    Engine::ypos = ypos;
    Engine::width = width;
    Engine::height = height;
    Engine::flags = flags;
}

//Init SDL_Window and SDL_Renderer, if no error isRunning = true
bool Engine::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n" ;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window != 0)
        {
            std::cout << "window creation success\n";
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer != 0)
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
            }
            else 
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else 
        {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }
    std::cout << "init success\n";
    isRunning = true; // everything inited successfully, start the main loop
    return true;
}

//If an SDL_Quit event is triggered isRunning = false
void Engine::handleEvent()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
    }
}

//Close and clean SDL instances
void Engine::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Engine::drawCircle()
{
    int x1, x2, y1, y2;
    int Cx = 0, Cy = 0, r = 50;
    int x0 = 50, y0 = 50;
    for(int p = -r; p < r; p++)
    {
        x1 = p;
        x2 = x1 + 1;
        y1 = Engine::calcY(&x1, Cx, Cy, r, x0, y0);
        y2 = Engine::calcY(&x2, Cx, Cy, r, x0, y0);
        int delta = y2 - y1;

        int ny1 = (height - y0)*2 - y1;
        int ny2 = (height - y0)*2 - y2;
        int ndelta = ny2 - ny1;

        SDL_SetRenderDrawColor(renderer, 255, 0 , 0, 255);
        SDL_RenderDrawLine(renderer, x1, y1, x1, y1 + delta);
        SDL_RenderDrawLine(renderer, x1, ny1, x1, ny1 + ndelta);
    }
}

int Engine::calcY(int* x, int Cx, int Cy, int r, int x0, int y0)
{
    int y = sqrt(pow(r, 2) - pow((*x - Cx), 2)) + Cy;
    if(*x != 0){
        Engine::adjust(x0, y0, x, &y);
        return y;
    }
    else{
        y < 0 ? y = y + 1 : y = y - 1;
        Engine::adjust(x0, y0, x, &y);
        return y;
    }
}

void Engine::adjust(int x0, int y0, int* x, int* y)
{
    *x += x0;
    *y = height - y0 - *y;
}