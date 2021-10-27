#include"Game.h"
#include<SDL.h>
#include<iostream>

Game::Game(){}

bool Game::init(const char* title, int xpos, int ypos, int width,
        int height, int flags)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n" ;
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
        if(m_pWindow != 0)
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if (m_pRenderer != 0)
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer,255,255,255,255);
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
    m_bRunning = true; // everything inited successfully, start the main loop
    return true;
}

void Game::draw()
{
    SDL_RenderClear(m_pRenderer);

    SDL_Rect rect;
    rect.x = 100;
    rect.y = 100;
    rect.w = 50;
    rect.h = 50;

    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(m_pRenderer, &rect);

    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

    SDL_RenderPresent(m_pRenderer);
}

void Game::physic()
{
    
}

void Game::handleEvent()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {    
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break; 
        }
    }
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
