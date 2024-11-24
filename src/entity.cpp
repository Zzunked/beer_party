#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"


Entity::Entity(Vector2f p_position, SDL_Texture* p_texture)
    :position(p_position), texture(p_texture)
{
    id = 0;
    current_frame.x = 0;
    current_frame.y = 0;
    current_frame.w = 0;
    current_frame.h = 0;
}


Entity::Entity(Vector2f p_position, SDL_Texture* p_texture, int p_width, int p_height)
    :position(p_position), texture(p_texture), width(p_width), height(p_height)
{
    id = 0;
    current_frame.x = 0;
    current_frame.y = 0;
    current_frame.w = width;
    current_frame.h = height;
}


Entity::Entity(Vector2f p_position, SDL_Texture* p_texture, int p_id)
    :position(p_position), texture(p_texture), id(p_id)
{
    current_frame.x = 0;
    current_frame.y = 0;
    current_frame.w = 0;
    current_frame.h = 0;
}


SDL_Texture* Entity::get_texture() const
{
    return texture;
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
    return position;
}

void Entity::set_position(Vector2f p_position) {
   position = p_position; 
}

void Entity::move_by_y(float step) {
    float current_pos_x = position.x;
    float current_pos_y = position.y;
    float new_pos_y = current_pos_y + step;

    set_position(Vector2f(current_pos_x, new_pos_y));
}


int Entity::get_id() {
    return id;
}
