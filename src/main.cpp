#include <SDL.h>
#include <SDL_image.h>
#include <format>
#include <iostream>

#include "constants.hpp"
#include "render_window.hpp"



void printRectPosition(SDL_Rect rect)
{
    std::string formatted_str = std::format("Rectangle position (x: {}, y: {})", rect.x, rect.y);
    std::cout << formatted_str << std::endl;
}


int main(int argc, char* args[])
{   
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;
    
    RenderWindow window("Simple Game", 1280, 720);

    // SDL_Window* window = nullptr;
    // SDL_Renderer* renderer = nullptr;
    SDL_Event event; 
    // SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer);
    // SDL_PumpEvents();
    bool runnnig = true;

    std::cout << "I AM WORKING!!!" << std::endl;

    while (runnnig)
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                runnnig = false;
            }
        }
    }
    

    // SDL_Delay(10000);

    return 0;    
}
