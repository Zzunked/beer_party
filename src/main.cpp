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
#include "button.hpp"
#include "main_menu.hpp"
#include "music_player.hpp"


void add_beers(std::vector<Beer>& beers, SDL_Texture* beer_texture);


int main(int argc, char* args[])
{   
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) > 0)
        log_error("SDL_Init()");

    if (!(IMG_Init(IMG_INIT_PNG)))
        log_error("IMG_Init()");

    if (!Mix_Init(MIX_INIT_MP3))
        log_error("Mix_Init()");


    RenderWindow window("Beer Party", RESOLUTION_X, RESOLUTION_Y);
    MusicPlayer music_player = MusicPlayer();

    SDL_Event event;
    SDL_Texture* beer_texture = window.load_texture("data/assets/beer.png");
    SDL_Texture* play_btn_texture = window.load_texture("data/assets/play_btn.png");
    SDL_Texture* main_menu_bg_texture = window.load_texture("data/assets/main_menu_bg.png");
    SDL_Texture* beer_party_bg_texture = window.load_texture("data/assets/beer_party_bg.png");

    Background main_menu_bg = Background(main_menu_bg_texture);
    Background beer_party_bg = Background(beer_party_bg_texture);
    Button play_btn = Button(Vector2f(600, 360), play_btn_texture, PLAY_BTN_W, PLAY_BTN_H);

    std::vector<Beer> my_beers; 
    my_beers.reserve(9);

    bool running = true;
    Scene current_scene = main_menu;

    const float time_step = 0.01f;
    float accumulator = 0.0f;
    float current_time = utils::hire_time_in_seconds();

    add_beers(my_beers, beer_texture);

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
                {
                    music_player.play_music_main_menu();
                    handle_events_main_menu(&event, &running, &current_scene, &play_btn);
                    render_scene_main_menu(&window, &main_menu_bg, &play_btn);
                    break;
                }

            case beer_party_scene_1:
                {
                    music_player.play_music_scene_1();
                    handle_events_beer_party_1(&event, &running, my_beers);
                    render_scene_beer_party_1(&window, &beer_party_bg, my_beers);
                    break;
                }

            default:
                {
                    log_error("Unknown scene");
                    running = false;
                    break;
                }
        }

        window.display();
    }

    window.clean_up();
    Mix_Quit();
    SDL_Quit();

    return 0;    
}


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
