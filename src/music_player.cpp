#include <iostream>

#include "music_player.hpp"


Mix_Music* MUSIC_MAIN_MENU = Mix_LoadMUS("data/sounds/main_menu_music.mp3");
Mix_Music* MUSIC_SCENE_1 = Mix_LoadMUS("data/sounds/tavern_music.mp3");


MusicPlayer::MusicPlayer() 
{
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);
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
        std::cout << "Play main menu music at the start" << "\n";
        main_music_callback();
        music_current = bg_music_main_menu;
    } 
    else if (music_current != bg_music_main_menu)
    {
        std::cout << "Play main menu music" << "\n";
        Mix_HookMusicFinished(main_music_callback);
        Mix_FadeOutMusic(MUSIC_FADEOUT_TIME);
        music_current = bg_music_main_menu;
    }
}


void MusicPlayer::play_music_scene_1()
{
    if (music_current == bg_music_none)
    {
        std::cout << "Play scene 1 music" << "\n";
        scene_1_music_callback();
        music_current = bg_music_scene_1;
    } 
    else if (music_current != bg_music_scene_1)
    {
        std::cout << "Play scene 1 music" << "\n";
        Mix_HookMusicFinished(scene_1_music_callback);
        Mix_FadeOutMusic(MUSIC_FADEOUT_TIME);
        music_current = bg_music_scene_1;
    } 
}


void main_music_callback()
{
    Mix_FadeInMusic(MUSIC_MAIN_MENU, -1, MUSIC_FADEIN_TIME);
}


void scene_1_music_callback()
{
    Mix_FadeInMusic(MUSIC_SCENE_1, -1, MUSIC_FADEIN_TIME);
}

