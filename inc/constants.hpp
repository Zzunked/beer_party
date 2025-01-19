#pragma once

const int RESOLUTION_X = 1280;
const int RESOLUTION_Y = 720;

const int BEER_MAX_Y = 0;
const int BEER_MIN_Y = 590;

const int BEER_WIDTH = 32 * 4;
const int BEER_HEIGHT = 32 * 4;

const int PLAY_BTN_W = 144;
const int PLAY_BTN_H = 72;

const int MUSIC_FADEOUT_TIME = 300;
const int MUSIC_FADEIN_TIME = 300;


enum Scene 
{
    main_menu,
    beer_party_scene_1
};


enum BackgroundMusic
{
    bg_music_none,
    bg_music_main_menu,
    bg_music_scene_1
};

