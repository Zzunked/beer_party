#pragma once
#include <SDL_mixer.h>

#include "math.hpp"
#include "entity.hpp"
#include "render_window.hpp"


class Beer: public Entity {
    private:
        int id;
        int step_y = 5;
        int dest = 0;
        int max_point = 0;
        int min_point = 590;
        Mix_Chunk* sound_hit = Mix_LoadWAV("data/sounds/beer_hit.wav");
        Mix_Chunk* sound_broken_glass = Mix_LoadWAV("data/sounds/broken_glass.wav");
        Mix_Chunk* sound_hey = Mix_LoadWAV("data/sounds/dwarf_hey.wav");
    public:
        Beer(Vector2f p_pos, SDL_Texture* p_tex, int p_id);
        int get_dest();
        int get_max_point();
        int get_min_point();
        void change_direction();
        void set_dest(int p_dest);
        void move_by_y();
        void move_to_bottom();
        void get_info();
        void play_hit_sound();
        void play_broken_glass_sound();
        void play_hey_sound();
};

