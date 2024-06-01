#pragma once
#include <SDL.h>
#include <SDL_image.h>


class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    float Get_X();
    float Get_Y();
    SDL_Texture* GetTex();
    SDL_Rect GetCurrentFrame();
private:
    float x, y;
    SDL_Rect current_frame;
    SDL_Texture* tex;
};