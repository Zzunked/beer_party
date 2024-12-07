#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "math.hpp"


class Entity {
private:
    Vector2f position;
    SDL_Texture* texture;
    int id;
    int width;
    int height;
    SDL_Rect current_frame;
public:
    Entity(Vector2f p_position, SDL_Texture* p_texture);
    Entity(Vector2f p_position, SDL_Texture* p_texture, int p_width,  int p_height);
    Entity(Vector2f p_position, SDL_Texture* p_texture, int id);
    Vector2f get_position();
    void set_position(Vector2f p_position);
    SDL_Texture* get_texture() const;
    SDL_Rect get_current_frame() const;
    void set_current_frame_width(int p_width);
    void set_current_frame_height(int p_height);
    void move_by_y(float step);
    int get_id();
};
