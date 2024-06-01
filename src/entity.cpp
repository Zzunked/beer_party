#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"


Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
    current_frame.x = 0;
    current_frame.y = 0;
    current_frame.w = 32;
    current_frame.h = 32;
}


SDL_Texture* Entity::GetTex()
{
    return tex;
}


SDL_Rect Entity::GetCurrentFrame()
{
    return current_frame;
}


Vector2f& Entity::GetPos()
{
    return pos;
}