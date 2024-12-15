#pragma once

#include <SDL_mixer.h>

#include "constants.hpp"


class MusicPlayer
{
    private:
        BackgroundMusic music_current = bg_music_none;
    public:
        MusicPlayer();
        ~MusicPlayer(); 
        void play_music_main_menu();
        void play_music_scene_1();
};


void main_music_callback();
void scene_1_music_callback();

