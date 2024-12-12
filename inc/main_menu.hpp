#pragma once

#include <SDL.h>

#include "render_window.hpp"
#include "background.hpp"
#include "button.hpp"
#include "constants.hpp"


void handle_events_main_menu(SDL_Event* event, bool* running, Scene* current_scene, Button* play_btn);

void render_scene_main_menu(RenderWindow* window, Background* background, Button* play_btn);

