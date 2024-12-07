#pragma once
#include <SDL.h>


namespace utils
{
    inline float hire_time_in_seconds()
    {
        float t = SDL_GetTicks();
        t *= 0.001f;

        return t;
    }
}

void log_error(const char* error_message);

