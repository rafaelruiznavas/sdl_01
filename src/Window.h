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
            SDL_CreateWindow("Hello Window", 700, 300, 0)
        };
        // Almacemanos en el smart pointer
        m_SDLWindow = UniqueSDLWindow(ptr);
    }

    void Render()
    {
        const auto* fmt = SDL_GetPixelFormatDetails(GetSurface()->format);

        SDL_FillSurfaceRect(
            GetSurface(),
            nullptr,
            SDL_MapRGB(fmt, nullptr, 50,50,50)
        );
    }

    void Update()
    {
        SDL_UpdateWindowSurface(m_SDLWindow.get());
    }

    SDL_Surface* GetSurface() const {
        return SDL_GetWindowSurface(m_SDLWindow.get());
    }


    // Aun necesitamos una forma de obtener el puntero raw para otras interacciones con funciones de SDL
    SDL_Window* GetRaw() const { return m_SDLWindow.get(); }
};