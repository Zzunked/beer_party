#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"


class RenderWindow
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        RenderWindow(const char* p_title, int p_w, int p_h);
        SDL_Texture* load_texture(const char* p_filePath);

        void clean_up();
        void clear();
        void render(Entity& p_entity);
        void display();
};
