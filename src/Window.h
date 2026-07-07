#pragma once
#include <memory>
#include <SDL3/SDL.h>

// Definimos un custom Deleter para SDL_Window*
struct SDLWindowDeleter
{
    void operator()(SDL_Window* ptr) const
    {
        if(ptr && SDL_WasInit(SDL_INIT_VIDEO))
        {
            SDL_DestroyWindow(ptr);
        }
    }
};

// Alias por comodidad
using UniqueSDLWindow = std::unique_ptr<SDL_Window, SDLWindowDeleter>;

class Window
{
    UniqueSDLWindow m_SDLWindow{nullptr};
public:
    Window() {
        SDL_Window* ptr{
            SDL_CreateWindow("Hello Window", 800, 300, SDL_WINDOW_RESIZABLE)
        };
        
        SDL_GetWindowSurface(ptr);
        SDL_UpdateWindowSurface(ptr);

        // Almacemanos en el smart pointer
        m_SDLWindow = UniqueSDLWindow(ptr);
    }

    // Aun necesitamos una forma de obtener el puntero raw para otras interacciones con funciones de SDL
    SDL_Window* GetRaw() const { return m_SDLWindow.get(); }
};