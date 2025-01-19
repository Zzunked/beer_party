#pragma once

#include <SDL.h>

#include "render_window.hpp"
#include "background.hpp"
#include "button.hpp"
#include "constants.hpp"
#include "scene_handler_base.hpp"


class SceneHandlerMainMenu : SceneHandlerBase
{
    private:
        RenderWindow* window;
        SDL_Event* event;
        bool* running;
        Scene* current_scene;
        SDL_Texture* play_btn_texture;
        SDL_Texture* main_menu_bg_texture;
        Background main_menu_bg;
        Button play_btn;
        bool is_scene_loaded;
    public:
        SceneHandlerMainMenu(RenderWindow* p_window, SDL_Event* event, bool* running, Scene* current_scene);
        ~SceneHandlerMainMenu();
        virtual void load_scene() override;
        virtual void handle_events() override;
        virtual void render_scene() override;
};

