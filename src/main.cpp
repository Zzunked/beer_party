#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "render_window.hpp"
#include "utils.hpp"
#include "entity.hpp"
#include "math.hpp"
#include "beer.hpp"
#include "constants.hpp"



int calculate_random_dest(int start_point, int max_point) {

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(start_point, max_point);
    int dest = dist6(rng);

    return dest;
}


void add_beers(std::vector<Beer>& beers, SDL_Texture* beer_texture) {

    int beer_x_position = 24;
    int beer_y_position = 590;
    int beer_step = 136;
    for (int i = 0; i < 9; i++)
    {
        beers.push_back(Beer(Vector2f(beer_x_position, beer_y_position), beer_texture, i));
        beer_x_position += beer_step;
    };

}


void move_beers(std::vector<Beer>& beers) {

    for (Beer &beer : beers) {
    
        Vector2f current_beer_pos = beer.get_position();

        if (current_beer_pos.y >= beer.min_point){
            int dest = calculate_random_dest(beer.max_point, beer.min_point);
            beer.set_dest(dest);
            beer.change_direction();
        } else if (current_beer_pos.y <= beer.get_dest()) {
            beer.change_direction();
        }
        beer.move_by_y();
    }
}


int main(int argc, char* args[])
{   
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) > 0)
        log_error("SDL_Init()");

    if (!(IMG_Init(IMG_INIT_PNG)))
        log_error("IMG_Init()");

    if (!Mix_Init(MIX_INIT_MP3))
        log_error("Mix_Init()");


    RenderWindow window("Beer Party", RESOLUTION_X, RESOLUTION_Y);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);


    SDL_Event event;
    SDL_Texture* beer_texture = window.load_texture("assets/pictures/beer.png");
    SDL_Texture* tavern_background = window.load_texture("assets/pictures/tavern_bg.png");
    Mix_Music* tavern_music = Mix_LoadMUS("assets/sounds/tavern_music.mp3");
    Entity background = Entity(Vector2f(0, 0), tavern_background, RESOLUTION_X, RESOLUTION_Y);
    std::vector<Beer> my_beers; 
    my_beers.reserve(9);
    bool running = true;
    const float time_step = 0.01f;
    float accumulator = 0.0f;
    float current_time = utils::hire_time_in_seconds();

    add_beers(my_beers, beer_texture);

    Mix_PlayMusic(tavern_music, 999);
    
    while (running)
    {

        int start_ticks = SDL_GetTicks();
        float new_time = utils::hire_time_in_seconds();
        float frame_time = new_time - current_time;
        current_time = new_time;
        accumulator += frame_time;


        while (accumulator >= time_step) {

            while(SDL_PollEvent(&event)) {

                if (event.type == SDL_QUIT) {

                    running = false;

                } else if (event.type == SDL_MOUSEBUTTONDOWN) {

                    Vector2f click_pos =  Vector2f(event.button.x, event.button.y);

                    for (Beer &beer: my_beers) {

                        Vector2f beer_pos = beer.get_position();

                        if ((click_pos.x >= beer_pos.x) && (click_pos.x <= (beer_pos.x + 128))) {

                            if ((click_pos.y >= beer_pos.y) && (click_pos.y <= (beer_pos.y + 128))) {

                                beer.play_broken_glass_sound();
                                beer.move_to_bottom();

                                break;
                            }
                        }
                    }
                }
            }    
            accumulator -= time_step;
        }

        move_beers(my_beers);

        window.clear();

        window.render(background, 1);
        
        for (Beer &beer : my_beers) {
            beer.get_info();
            float beer_y = beer.get_position().y;

            if (beer_y == beer.min_point) {
                beer.play_hit_sound();

            } else if (beer_y <= (beer.max_point)) {
                std::cout << "BOOM" << std::endl;
                beer.play_explosion_sound();
            }
            window.render(beer);

        }

        window.display();
    }
    Mix_HaltMusic();
    Mix_CloseAudio();
    
    window.clean_up();
    Mix_Quit();
    SDL_Quit();

    return 0;    
}
