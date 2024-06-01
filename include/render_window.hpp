#pragma once
#include <SDL.h>
#include <SDL_image.h>


class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    void CleanUp();
    SDL_Texture* LoadTexture(const char* p_filePath);
    void Clear();
    void Renderer(SDL_Texture* p_tex);
    void Display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

};