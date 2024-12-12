#pragma once
#include <SDL_mixer.h>

#include "math.hpp"
#include "entity.hpp"


class Button : public Entity
{
    private:
        Mix_Chunk* click_sound = Mix_LoadWAV("data/sounds/button_click.wav");
    public:
        Button(Vector2f p_pos, SDL_Texture* p_tex, int p_width, int p_height);
        void play_click_sound();
};

