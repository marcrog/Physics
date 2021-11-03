#include<iostream>
#include<SDL.h>
#include"../include/Console.h"
#include <cstdlib>
#include <ctime>

//float x = 892.9833352606; // variabile arbitraria - pixel/s
//float pix_l = 0.000311316; //dimensione pixel

int main()
{
    Engine* engine = new Engine(new mySDLManager("Physics Engine", 239, SDL_WINDOWPOS_CENTERED, 
                                    600, 600, 0));
    Console* console = new Console(engine);
    mySDLManager* manager = engine -> getManager();
    manager->init();
    Corp* b = new Ball(manager, 300, 300, 50);
    Corp* t = new Triangle(manager, 300, 300, 300, 350);
    engine -> addCorps(t);
    engine -> addCorps(b);

    mainLoop(engine, manager);
    
    manager -> clean();
    return 0;
}
