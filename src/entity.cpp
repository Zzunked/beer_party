#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"


Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
    :pos(p_pos), tex(p_tex)
{
    current_frame.x = 0;
    current_frame.y = 0;
    current_frame.w = 0;
    current_frame.h = 0;
}


Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, int p_width, int p_height)
    :pos(p_pos), tex(p_tex), width(p_width), height(p_height)
{
    current_frame.x = 0;
    current_frame.y = 0;
    current_frame.w = width;
    current_frame.h = height;
}


SDL_Texture* Entity::get_texture() const
{
    return tex;
}


SDL_Rect Entity::get_current_frame() const
{
    return current_frame;
}


void Entity::set_current_frame_width(int p_width) {
    current_frame.w = p_width;
} 


void Entity::set_current_frame_height(int p_height) {
    current_frame.h = p_height;
} 


Vector2f Entity::get_position()
{
    return pos;
}

void Entity::set_position(Vector2f p_pos) {
   pos = p_pos; 
}
