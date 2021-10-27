#include<SDL.h>
#include"myLib/Game.h"
#include<iostream>

int main(int argc, char const *argv[])
{    
   Game* g_game = new Game();
   g_game -> init("OllareGang", 100, 100, 600, 600, 0);
   while(g_game -> running())
   {
      g_game -> draw();
      g_game -> physic();
      g_game -> handleEvent();
   }
   g_game -> clean();
   return 0;
}
