#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include "Window.h"
#include "Rectangle.h"

void HandleEvent(SDL_Event& e)
{
    if(e.type == SDL_EVENT_MOUSE_MOTION)
    {
        std::cout << "Mouse Motion" << "x: " << e.motion.x << " y: " << e.motion.y << std::endl;
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
    Window gameWindow;
    Rectangle rect{SDL_Rect{50,50,50,50}};

    bool IsRunning = true;
    SDL_Event event;
    while (IsRunning) {
        // Procesamos eventos
        while (SDL_PollEvent(&event)) {
            rect.HandleEvent(event);

            if (event.type == SDL_EVENT_QUIT) {
                IsRunning = false;
            }
        }

        // Actualizamos los objetos

        // Renderizamos los cambios
        // Renderizamos el color de fondo
        gameWindow.Render();
        rect.Render(gameWindow.GetSurface());

        // Intercambiamos los buffers
        gameWindow.Update();
    }

    // Apagar
    SDL_Quit();
    return 0;
}