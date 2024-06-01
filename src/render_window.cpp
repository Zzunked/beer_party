#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "render_window.hpp"
#include "utils.hpp"


RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == nullptr)
        LogError("Window failed to init. SDL_Error");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}


void RenderWindow::CleanUp()
{
    SDL_DestroyWindow(window);
}


SDL_Texture* RenderWindow::LoadTexture(const char* p_filePath)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == nullptr)
        LogError("Failed to load texture");

    return texture;
}

void RenderWindow::Clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::Renderer(SDL_Texture* p_tex)
{
    SDL_RenderCopy(renderer, p_tex, nullptr, nullptr);
}

void RenderWindow::Display()
{
    SDL_RenderPresent(renderer);
}