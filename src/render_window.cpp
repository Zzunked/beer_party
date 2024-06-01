#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "render_window.hpp"
#include "utils.hpp"
#include "entity.hpp"


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


void RenderWindow::Render(Entity& p_entity)
{
    SDL_Rect src;
    src.x = p_entity.GetCurrentFrame().x;
    src.y = p_entity.GetCurrentFrame().y;
    src.w = p_entity.GetCurrentFrame().w;
    src.h = p_entity.GetCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.GetPos().x;
    dst.y = p_entity.GetPos().y;
    dst.w = p_entity.GetCurrentFrame().w * 4;
    dst.h = p_entity.GetCurrentFrame().h * 4;

    SDL_RenderCopy(renderer, p_entity.GetTex(), &src, &dst);
}


void RenderWindow::Display()
{
    SDL_RenderPresent(renderer);
}