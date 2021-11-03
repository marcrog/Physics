#include"Engine.h"

class Console
{
    private:
        Engine* engine;
    public:
        Console(Engine* engine);
        void takeInput();
        void clear();
};

class Command
{
    private:
    public:
        Command();
        std::string getName();
        std::string setName();

};