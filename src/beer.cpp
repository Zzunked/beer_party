#include <SDL_mixer.h>

#include "beer.hpp"
#include "constants.hpp"


Beer::Beer(Vector2f p_position, SDL_Texture* p_texture, int p_id)
    :Entity(p_position, p_texture) {
    
    current_frame.w = BEER_WIDTH;
    current_frame.h = BEER_HEIGHT;
    id = p_id;
}


int Beer::get_dest() {
    return dest;
}


int Beer::get_max_point() {
    return max_point;
}


int Beer::get_min_point() {
    return min_point;
}


void Beer::change_direction() {
    step_y *= -1;
}


void Beer::set_dest(int p_dest) {
    dest = p_dest;
}


void Beer::move_by_y() {
    float pos_y_new = position.y + step_y;
    position = Vector2f(position.x, pos_y_new);
}


void Beer::move_to_bottom() {
    float bottom = min_point - abs(step_y);
    position = Vector2f(position.x, bottom);
}


void Beer::get_info() {
    std::cout << "Beer[" << id << "] dest: " << dest << " position: " << std::endl;   
    position.print();
}


void Beer::play_hit_sound() {
    Mix_PlayChannel(-1, sound_hit, 0);
}


void Beer::play_broken_glass_sound() {
    Mix_PlayChannel(-1, sound_broken_glass, 0);
}


void Beer::play_hey_sound() {
    Mix_PlayChannel(-1, sound_hey, 0);
}

