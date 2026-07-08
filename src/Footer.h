#pragma once
#include <SDL3/SDL.h>
#include "Rectangle.h"

class Footer
{
    Rectangle m_background{SDL_Rect{0, 250, 700, 50}};
public:
    Footer()
    {
        m_background.SetColor({100,100,100,255});
    }

    void Render(SDL_Surface* l_surface) const
    {
        m_background.Render(l_surface);
    }

    void HandleEvent(SDL_Event& l_e)
    {
        m_background.HandleEvent(l_e);
    }
};