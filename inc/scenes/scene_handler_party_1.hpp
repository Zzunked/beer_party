#pragma once

#include <SDL.h>

#include "render_window.hpp"
#include "background.hpp"
#include "button.hpp"
#include "constants.hpp"
#include "beer.hpp"
#include "scene_handler_base.hpp"


class SceneHandlerPartyOne : SceneHandlerBase
{
    private:
        RenderWindow* window;
        SDL_Event* event;
        bool* running;
        Scene* current_scene;
        bool is_scene_loaded;
        SDL_Texture* beer_texture;
        SDL_Texture* beer_party_bg_texture;
        Background beer_party_bg;
        std::vector<Beer> my_beers; 
        void add_beers();
        void move_beers();
    public:
        SceneHandlerPartyOne(RenderWindow* p_window, SDL_Event* p_event, bool* p_running, Scene* p_current_scene);
        ~SceneHandlerPartyOne();
        virtual void load_scene() override;
        virtual void handle_events() override;
        virtual void render_scene() override;
};


int calculate_random_dest(int start_point, int max_point);

