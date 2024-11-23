#pragma once
#include <string>

#include "math.hpp"
#include "entity.hpp"
#include "render_window.hpp"


class Beer: public Entity {
    public:
        Beer(Vector2f p_pos, SDL_Texture* p_tex);
};

