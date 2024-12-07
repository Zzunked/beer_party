#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "math.hpp"
#include "entity.hpp"
#include "render_window.hpp"


class Background: public Entity {
    public:
        Background(SDL_Texture* p_tex);
};

