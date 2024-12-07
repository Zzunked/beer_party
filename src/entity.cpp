#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"


Entity::Entity(Vector2f p_position, SDL_Texture* p_texture)
    :position(p_position), texture(p_texture) {

    current_frame.x = 0;
    current_frame.y = 0;
    current_frame.w = 0;
    current_frame.h = 0;
}


Vector2f Entity::get_position() {
    return position;
}


SDL_Texture* Entity::get_texture() {
    return texture;
}


SDL_Rect Entity::get_current_frame() {
    return current_frame;
}


void Entity::set_position(Vector2f p_position) {
   position = p_position; 
}

