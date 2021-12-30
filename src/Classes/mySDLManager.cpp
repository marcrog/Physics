#include"../../include/Engine.h"
#include<SDL.h>
#include<iostream>

//----------------------------------------------------------------------------
//#         MYSDLMANAGER DEFINITIONS

mySDLManager::mySDLManager(const char* title, int xpos, int ypos, int width, int
                    height, int flags)
{
    mySDLManager::title = title;
    mySDLManager::xpos = xpos;
    mySDLManager::ypos = ypos;
    mySDLManager::width = width;
    mySDLManager::height = height;
    mySDLManager::flags = flags;
}

//Init SDL_Window and SDL_Renderer, if no error isRunning = true
bool mySDLManager::init()
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
void mySDLManager::handleEvents(bool* exe)
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            isRunning = false;
            *exe = false;
        }
        else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
            isRunning = false;
    }
}

//Close and clean SDL instances
void mySDLManager::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
