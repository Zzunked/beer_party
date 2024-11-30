#pragma once
#include <string>
#include <SDL_mixer.h>

#include "math.hpp"
#include "entity.hpp"
#include "render_window.hpp"


class Beer: public Entity {
    private:
        int step_y;
        int dest;
        Mix_Chunk* sound_hit = Mix_LoadWAV("assets/sounds/beer_hit.wav");
        Mix_Chunk* sound_broken_glass = Mix_LoadWAV("assets/sounds/broken_glass.wav");
        Mix_Chunk* sound_explosion = Mix_LoadWAV("assets/sounds/beer_explosion.wav");
    public:
        const int max_point = 0;
        const int min_point = 590;
        Beer(Vector2f p_pos, SDL_Texture* p_tex);
        Beer(Vector2f p_pos, SDL_Texture* p_tex, int id);
        void change_direction();
        void set_dest(int p_dest);
        int get_dest();
        void move_by_y();
        void move_to_bottom();
        void get_info();
        void play_hit_sound();
        void play_broken_glass_sound();
        void play_explosion_sound();
};

