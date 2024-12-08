#pragma once

#include <SDL.h>
#include <vector>

#include "render_window.hpp"
#include "background.hpp"
#include "beer.hpp"


int calculate_random_dest(int start_point, int max_point);


void move_beers(std::vector<Beer>& beers);


void handle_events_beer_party_1(float* accumulator, const float* timestep, SDL_Event* event,  std::vector<Beer>& beers, bool* running);


void render_scene_beer_party_1(RenderWindow* window, Background* background, std::vector<Beer>& beers);

