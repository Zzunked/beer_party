#include "background.hpp"
#include "constants.hpp"
#include "math.hpp"


Background::Background(SDL_Texture* p_texture)
    :Entity(Vector2f(0, 0), p_texture) {
    
    current_frame.w = RESOLUTION_X;
    current_frame.h = RESOLUTION_Y;
}

