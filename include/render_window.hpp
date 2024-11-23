#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"


class RenderWindow
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    const int mux = 4;
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* LoadTexture(const char* p_filePath);

    void CleanUp();
    void Clear();
    void Render(Entity& p_entity);
    void Render(Entity& p_entity, int mux);
    void Display();
};
