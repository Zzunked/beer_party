#include <string>
#include <SDL_mixer.h>

#include "beer.hpp"


Beer::Beer(Vector2f p_position, SDL_Texture* p_texture)
    :Entity(p_position, p_texture) {
    
    set_current_frame_width(32);
    set_current_frame_height(32);    
    dest = 0;
    step_y = 5;
}


Beer::Beer(Vector2f p_position, SDL_Texture* p_texture, int p_id)
    :Entity(p_position, p_texture, p_id) {
    
    set_current_frame_width(32);
    set_current_frame_height(32);    
    dest = 0;
    step_y = 5;
}


void Beer::change_direction() {
    step_y *= -1;
}


void Beer::set_dest(int p_dest) {
    dest = p_dest;
}

int Beer::get_dest() {
    return dest;
}


void Beer::move_by_y() {
    Vector2f current_position = get_position();
    float new_pos_y = current_position.y + step_y;

    set_position(Vector2f(current_position.x, new_pos_y));
}


void Beer::move_to_bottom() {
    Vector2f current_position = get_position();
    float bottom = min_point - abs(step_y);
    set_position(Vector2f(current_position.x, bottom));
}


void Beer::get_info() {
    std::cout << "Beer[" << get_id() << "] dest: " << get_dest() << " position: " << std::endl;   
    get_position().print();
}


void Beer::play_hit_sound() {
    Mix_PlayChannel(-1, sound_hit, 0);
}


void Beer::play_broken_glass_sound() {
    Mix_PlayChannel(-1, sound_broken_glass, 0);
}


void Beer::play_explosion_sound() {
    Mix_PlayChannel(-1, sound_explosion, 0);
}

