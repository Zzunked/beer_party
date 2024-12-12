#include "button.hpp"


Button::Button(Vector2f p_position, SDL_Texture* p_texture, int p_width, int p_height)
    :Entity(p_position, p_texture)
{
    current_frame.w = p_width;
    current_frame.h = p_height;
}


void Button::play_click_sound() {
    Mix_PlayChannel(-1, click_sound, 0);
}

