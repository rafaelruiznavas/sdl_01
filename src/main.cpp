#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include "Window.h"

void HandleEvent(SDL_Event& e)
{
    if(e.type == SDL_EVENT_MOUSE_MOTION)
    {
        std::cout << "Mouse Motion" << std::endl;
    }
    else if(e.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
    {
        std::cout << "Mouse Button Down" << std::endl;
    }
    else if(e.type == SDL_EVENT_KEY_DOWN)
    {
        std::cout << "Keyboard button pressed" << std::endl;
    }
}

int main(int, char**) {
    // Inicializamos SDL
    SDL_Init(SDL_INIT_VIDEO);
    Window window;

    bool IsRunning = true;
    SDL_Event event;
    while (IsRunning) {
        // Procesamos eventos
        while (SDL_PollEvent(&event)) {
            HandleEvent(event);
            if (event.type == SDL_EVENT_QUIT) {
                IsRunning = false;
            }
        }

        // Actualizamos los objetos

        // Renderizamos los cambios
    }

    // Apagar
    SDL_Quit();
    return 0;
}