#include "beer.hpp"


Beer::Beer(Vector2f p_pos, SDL_Texture* p_tex)
    :Entity(p_pos, p_tex) {
    
    set_current_frame_width(32);
    set_current_frame_height(32);    
}

