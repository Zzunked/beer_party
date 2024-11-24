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



int calculate_random_dest(int start_point, int max_point) {

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(start_point, max_point);
    int dest = dist6(rng);

    return dest;
}


void move_beers(std::vector<Beer>& beers) {

    for (Beer &beer : beers) {
    
        Vector2f current_beer_pos = beer.get_position();

        if (current_beer_pos.y == beer.min_point){
            //int dest = calculate_random_dest(beer.max_point, beer.min_point);
            int dest = 0;
            beer.set_dest(dest);
            beer.change_direction();
        } else if (current_beer_pos.y == beer.get_dest()) {
            beer.change_direction();
        }
        beer.move_by_y();
    }
}


int main(int argc, char* args[])
{   
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        log_error("SDL_Init()");

    if (!(IMG_Init(IMG_INIT_PNG)))
        log_error("IMG_Init()");
    
    RenderWindow window("Beer Party", 1280, 720);

    SDL_Event event;
    bool running = true;
    const float time_step = 0.01f;
    float accumulator = 0.0f;
    float current_time = utils::hire_time_in_seconds();

    SDL_Texture* beer_texture = window.load_texture("assets/beer.png");
    SDL_Texture* tavern_background = window.load_texture("assets/tavern_bg.png");
    Entity background = Entity(Vector2f(0, 0), tavern_background, 1280, 720);

    std::vector<Beer> my_beers;
    int beer_position = 24;
    int beer_step = 136;

    for (int i = 0; i < 9; i++)
    {
        my_beers.push_back(Beer(Vector2f(beer_position, 590), beer_texture, i));
        beer_position += beer_step;
    };
    
    while (running)
    {

        int start_ticks = SDL_GetTicks();
        float new_time = utils::hire_time_in_seconds();
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

        move_beers(my_beers);

        window.clear();

        window.render(background, 1);
        
        for (Beer &beer : my_beers) {
            beer.get_info();
            window.render(beer);
        }

        window.display();
    }
    
    window.clean_up();

    return 0;    
}
