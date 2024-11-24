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
        log_error("Window failed to init. SDL_Error");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

}


SDL_Texture* RenderWindow::load_texture(const char* p_filePath)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == nullptr)
        log_error("Failed to load texture");

    return texture;
}


void RenderWindow::clean_up()
{
    SDL_DestroyWindow(window);
}


void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}


void RenderWindow::render(Entity& p_entity)
{
    SDL_Rect src;
    src.x = p_entity.get_current_frame().x;
    src.y = p_entity.get_current_frame().y;
    src.w = p_entity.get_current_frame().w;
    src.h = p_entity.get_current_frame().h;

    SDL_Rect dst;
    dst.x = p_entity.get_position().x;
    dst.y = p_entity.get_position().y;
    dst.w = p_entity.get_current_frame().w * this -> mux;
    dst.h = p_entity.get_current_frame().h * this -> mux;

    SDL_RenderCopy(renderer, p_entity.get_texture(), &src, &dst);
}


void RenderWindow::render(Entity& p_entity, int p_mux)
{
    SDL_Rect src;
    src.x = p_entity.get_current_frame().x;
    src.y = p_entity.get_current_frame().y;
    src.w = p_entity.get_current_frame().w;
    src.h = p_entity.get_current_frame().h;

    SDL_Rect dst;
    dst.x = p_entity.get_position().x;
    dst.y = p_entity.get_position().y;
    dst.w = p_entity.get_current_frame().w * p_mux;
    dst.h = p_entity.get_current_frame().h * p_mux;

    SDL_RenderCopy(renderer, p_entity.get_texture(), &src, &dst);
}


void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}
