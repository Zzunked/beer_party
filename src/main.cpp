#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "render_window.hpp"
#include "utils.hpp"
#include "entity.hpp"
#include "math.hpp"
#include "beer.hpp"


void move_beer(std::vector<Beer> beers, int beer_num, int dist) {
    
}


int main(int argc, char* args[])
{   
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        LogError("SDL_Init()");

    if (!(IMG_Init(IMG_INIT_PNG)))
        LogError("IMG_Init()");
    
    RenderWindow window("Beer Party", 1280, 720);

    SDL_Event event;
    bool running = true;
    const float time_step = 0.01f;
    float accumulator = 0.0f;
    float current_time = utils::HireTimeInSeconds();

    SDL_Texture* beer_texture = window.LoadTexture("assets/beer.png");
    SDL_Texture* tavern_background = window.LoadTexture("assets/tavern_bg.png");

    std::vector<Beer> my_beers;
    int beer_position = 24;
    int beer_step = 136;

    for (int i = 0; i < 9; i++)
    {
        my_beers.push_back(Beer(Vector2f(beer_position, 590), beer_texture));
        beer_position += beer_step;
    };

    Entity background = Entity(Vector2f(0, 0), tavern_background, 1280, 720);

    int beer_step_y = 10;
    int direction_up = 1;
    while (running)
    {

        int start_ticks = SDL_GetTicks();
        float new_time = utils::HireTimeInSeconds();
        float frame_time = new_time - current_time;
        current_time = new_time;
        accumulator += frame_time;


        while (accumulator >= time_step)
        {
            while(SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }
            }    
            accumulator -= time_step;
        }

        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0,8);

        int rand_beer = dist6(rng);

        Vector2f beer_pos = my_beers.at(rand_beer).GetPos();


        if (direction_up == 1) beer_pos.y -= beer_step_y;
        else beer_pos.y += beer_step_y;

        if (beer_pos.y == 0) {
            direction_up = 0;
        } else if (beer_pos.y == 590) {
            direction_up = 1;
        }
        //std::cout << beer_pos.y << std::endl;
        //std::cout << current_time << std::endl;
        my_beers.at(rand_beer).SetPos(Vector2f(beer_pos.x, beer_pos.y));

        window.Clear();

        window.Render(background, 1);
        
        for (Beer beer: my_beers)
            window.Render(beer);

        window.Display();
    }
    
    window.CleanUp();

    return 0;    
}
