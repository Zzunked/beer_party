#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "math.hpp"


class Entity
{
    protected:
        Vector2f position;
        SDL_Texture* texture;
        SDL_Rect current_frame;
    public:
        Entity(Vector2f p_position, SDL_Texture* p_texture);

        Vector2f get_position();
        SDL_Texture* get_texture();
        SDL_Rect get_current_frame();

        void set_position(Vector2f p_position);
        void set_texture(SDL_Texture* p_texture);
        void set_size(int p_width, int p_height);
};

