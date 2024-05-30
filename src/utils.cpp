#include <SDL.h>

#include "utils.hpp"


void LogError(const char* error_message)
{
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, error_message, SDL_GetError(), 0);
    SDL_Log("%s: %s", error_message, SDL_GetError());
}