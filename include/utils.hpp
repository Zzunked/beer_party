#pragma once
#include <SDL.h>
// #include <iostream>
// #include <format>


namespace utils
{
    inline float HireTimeInSeconds()
    {
        float t = SDL_GetTicks();
        t *= 0.001f;

        return t;
    }
}

void LogError(const char* error_message);


// void PrintRectPosition(SDL_Rect rect)
// {
//     std::string formatted_str = std::format("Rectangle position (x: {}, y: {})", rect.x, rect.y);
//     std::cout << formatted_str << std::endl;
// }