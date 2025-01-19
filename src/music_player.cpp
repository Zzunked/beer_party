#include <iostream>

#include "music_player.hpp"
#include "utils.hpp"


MusicPlayer::MusicPlayer()
{
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) < 0)
        log_error("Mix_OpenAudio()");
}


MusicPlayer::~MusicPlayer()
{
    Mix_HaltMusic();
    Mix_CloseAudio();
}


void MusicPlayer::play_music_main_menu()
{
    if (music_current == bg_music_none)
    {
        main_music_callback();
        music_current = bg_music_main_menu;
    } 
    else if (music_current != bg_music_main_menu)
    {
        Mix_HookMusicFinished(main_music_callback);
        Mix_FadeOutMusic(MUSIC_FADEOUT_TIME);
        music_current = bg_music_main_menu;
    }
}


void MusicPlayer::play_music_scene_1()
{
    if (music_current == bg_music_none)
    {
        scene_1_music_callback();
        music_current = bg_music_scene_1;
    } 
    else if (music_current != bg_music_scene_1)
    {
        Mix_HookMusicFinished(scene_1_music_callback);
        Mix_FadeOutMusic(MUSIC_FADEOUT_TIME);
        music_current = bg_music_scene_1;
    } 
}


void main_music_callback()
{
    Mix_Music* music_main_menu = Mix_LoadMUS("data/sounds/main_menu_music.mp3");
    Mix_FadeInMusic(music_main_menu, -1, MUSIC_FADEIN_TIME);
}


void scene_1_music_callback()
{
    Mix_Music* music_scene_1 = Mix_LoadMUS("data/sounds/tavern_music.mp3");
    Mix_FadeInMusic(music_scene_1, -1, MUSIC_FADEIN_TIME);
}

