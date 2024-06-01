#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "render_window.hpp"
#include "utils.hpp"
#include "entity.hpp"
#include "math.hpp"


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

    std::vector<Entity> my_beers = {
        Entity(Vector2f(0, 0), beer_texture),
        Entity(Vector2f(30, 0), beer_texture),
        Entity(Vector2f(30, 30), beer_texture),
        Entity(Vector2f(30, 60), beer_texture)
    };

    while (runnnig)
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                runnnig = false;
            }
            window.Clear();
            for (auto beer : my_beers)
            {
                window.Render(beer);
            }
            
            window.Display();
        }
    }
    
    window.CleanUp();

    return 0;    
}
