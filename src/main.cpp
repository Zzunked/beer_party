#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "render_window.hpp"
#include "utils.hpp"


int main(int argc, char* args[])
{   
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        LogError("SDL_Init()");

    if (!(IMG_Init(IMG_INIT_PNG)))
        LogError("IMG_Init()");
    
    RenderWindow window("Simple Game", 1280, 720);

    SDL_Event event;
    bool runnnig = true;

    SDL_Texture* beer_texture = window.LoadTexture("assets/beer.png");

    while (runnnig)
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                runnnig = false;
            }
            window.Clear();
            window.Renderer(beer_texture);
            window.Display();
        }
    }
    
    window.CleanUp();

    return 0;    
}
