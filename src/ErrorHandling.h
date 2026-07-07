#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <string>

#define ERROR_LOGGING

void CheckSDLError(const std::string& action)
{
    #ifdef ERROR_LOGGING
    const char* error{SDL_GetError()};
    if(*error != '\0')
    {
        std::cout << action << " Error: " << error << std::endl;
        SDL_ClearError();
    }
    #endif
}
