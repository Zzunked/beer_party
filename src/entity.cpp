#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"


Entity::Entity(Vector2f p_position, SDL_Texture* p_texture)
    :position(p_position), texture(p_texture)
{

    current_frame.x = 0;
    current_frame.y = 0;
    current_frame.w = 0;
    current_frame.h = 0;
}


Vector2f Entity::get_position()
{
    return position;
}


SDL_Texture* Entity::get_texture()
{
    return texture;
}


SDL_Rect Entity::get_current_frame()
{
    return current_frame;
}


void Entity::set_position(Vector2f p_position)
{
   position = p_position; 
}


void Entity::set_texture(SDL_Texture* p_texture)
{
    texture = p_texture;
}


void Entity::set_size(int p_width, int p_height)
{
    current_frame.w = p_width;
    current_frame.h = p_height;
}

