#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "math.hpp"


class Entity {
private:
    Vector2f pos;
    SDL_Texture* tex;
    int width;
    int height;
    SDL_Rect current_frame;
public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex);
    Entity(Vector2f p_pos, SDL_Texture* p_tex, int p_width,  int p_height);
    Vector2f GetPos();
    void SetPos(Vector2f p_pos);
    SDL_Texture* GetTex() const;
    SDL_Rect GetCurrentFrame() const;
    void SetCurrentFrameWidth(int p_width);
    void SetCurrentFrameHeight(int p_height);
};
