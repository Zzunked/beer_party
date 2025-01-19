#include "button.hpp"


Button::Button()
    :Entity(Vector2f(0, 0), nullptr) {}


Button::Button(Vector2f p_position, SDL_Texture* p_texture, int p_width, int p_height)
    :Entity(p_position, p_texture)
{
    Mix_Chunk* click_sound = Mix_LoadWAV("data/sounds/button_click.wav");
    current_frame.w = p_width;
    current_frame.h = p_height;
}


void Button::play_click_sound() {
    Mix_PlayChannel(-1, click_sound, 0);
}

