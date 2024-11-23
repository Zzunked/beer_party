#include "beer.hpp"


Beer::Beer(Vector2f p_pos, SDL_Texture* p_tex)
    :Entity(p_pos, p_tex) {
    
    SetCurrentFrameWidth(32);
    SetCurrentFrameHeight(32);    
}

