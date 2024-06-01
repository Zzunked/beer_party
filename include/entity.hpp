#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "math.hpp"


class Entity
{
public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex);
    Vector2f& GetPos();
    SDL_Texture* GetTex();
    SDL_Rect GetCurrentFrame();
private:
    Vector2f pos;
    SDL_Rect current_frame;
    SDL_Texture* tex;
};