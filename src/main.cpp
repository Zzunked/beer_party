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
#include "button.hpp"
#include "main_menu.hpp"
#include "music_player.hpp"
#include "scene_handler_main_menu.hpp"
#include "scene_handler_party_1.hpp"


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
    Scene current_scene = main_menu;
    bool running = true;
    SDL_Event event;
    SceneHandlerMainMenu main_menu_scene_handler = SceneHandlerMainMenu(&window, &event, &running, &current_scene);
    SceneHandlerPartyOne party_one_scene_handler = SceneHandlerPartyOne(&window, &event, &running, &current_scene);

    const float time_step = 0.01f;
    float accumulator = 0.0f;
    float current_time = utils::hire_time_in_seconds();

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
                    main_menu_scene_handler.load_scene();
                    main_menu_scene_handler.handle_events();
                    main_menu_scene_handler.render_scene();
                    break;
                }
            case beer_party_scene_1:
                {
                    music_player.play_music_scene_1();
                    party_one_scene_handler.load_scene();
                    party_one_scene_handler.handle_events();
                    party_one_scene_handler.render_scene();
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

