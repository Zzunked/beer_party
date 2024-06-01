#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"


Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
:x(p_x), y(p_y), tex(p_tex)
{
    current_frame.x = 0;
    current_frame.y = 0;
    current_frame.w = 32;
    current_frame.h = 32;
}


float Entity::Get_X()
{
    return x;
}


float Entity::Get_Y()
{
    return y;
}


SDL_Texture* Entity::GetTex()
{
    return tex;
}


SDL_Rect Entity::GetCurrentFrame()
{
    return current_frame;
}