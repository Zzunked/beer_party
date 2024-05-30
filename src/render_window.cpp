#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "render_window.hpp"


RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == nullptr)
        std::cout << "Window failed to init. SDL_Error: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

};