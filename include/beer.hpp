#pragma once
#include <string>

#include "math.hpp"
#include "entity.hpp"
#include "render_window.hpp"


class Beer: public Entity {
    private:
        int step_y;
        int dest;
    public:
        const int max_point = 0;
        const int min_point = 590;
        Beer(Vector2f p_pos, SDL_Texture* p_tex);
        Beer(Vector2f p_pos, SDL_Texture* p_tex, int id);
        void change_direction();
        void set_dest(int p_dest);
        int get_dest();
        void move_by_y();
        void get_info();
};

