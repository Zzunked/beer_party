#pragma once

#include <SDL.h>
#include <vector>

#include "render_window.hpp"
#include "background.hpp"
#include "beer.hpp"
#include "constants.hpp"


int calculate_random_dest(int start_point, int max_point);

void move_beers(std::vector<Beer>& beers);

void handle_events_beer_party_1(SDL_Event* event, bool* running, std::vector<Beer>& beers);

void render_scene_beer_party_1(RenderWindow* window, Background* background, std::vector<Beer>& beers);

