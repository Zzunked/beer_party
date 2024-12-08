#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "constants.hpp"
#include "render_window.hpp"
#include "utils.hpp"
#include "entity.hpp"
#include "math.hpp"
#include "beer.hpp"
#include "background.hpp"
#include "beer_party_1.hpp"


void add_beers(std::vector<Beer>& beers, SDL_Texture* beer_texture)
{

    int beer_x_position = 24;
    int beer_y_position = 590;
    int beer_step = 136;
    for (int i = 0; i < 9; i++)
    {
        beers.push_back(Beer(Vector2f(beer_x_position, beer_y_position), beer_texture, i));
        beer_x_position += beer_step;
    };

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
    SDL_Texture* beer_texture = window.load_texture("data/assets/beer.png");
    SDL_Texture* tavern_background = window.load_texture("data/assets/tavern_bg.png");
    Mix_Music* tavern_music = Mix_LoadMUS("data/sounds/tavern_music.mp3");


    Background background = Background(tavern_background);

    std::vector<Beer> my_beers; 
    my_beers.reserve(9);

    bool running = true;
    Scene current_scene = beer_party_1;
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

        switch (current_scene)
        {
            case main_menu:
            break;

            case beer_party_1:
            handle_events_beer_party_1(&accumulator, &time_step, &event, my_beers, &running);
            render_scene_beer_party_1(&window, &background, my_beers);
            break;

            default:
            log_error("Unknown scene");
            running = false;
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
