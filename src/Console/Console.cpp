#include"../include/Console.h"
#include <string>
#include<iostream>

//----------------------------------------------------------------------------
//#         CONSOLE DEFINITIONS

Console::Console(Engine* engine)
{
    Console::engine = engine;
}

void Console::takeInput()
{
    std::string Input;
    std::cin >> Input;
}

void Console::clear()
{
    system("clear");

} 