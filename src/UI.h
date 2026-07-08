#pragma once
#include <SDL3/SDL.h>
#include "Header.h"
#include "Footer.h"
#include "Grid.h"

class UI
{
    Header m_topMenu;
    Grid m_grid;
    Footer m_bottomMenu;

public:

    void Render(SDL_Surface* l_surface) const
    {
        m_topMenu.Render(l_surface);
        m_grid.Render(l_surface);
        m_bottomMenu.Render(l_surface);
    }

    void HandleEvent(SDL_Event& l_e)
    {
        m_topMenu.HandleEvent(l_e);
        m_grid.HandleEvent(l_e);
        m_bottomMenu.HandleEvent(l_e);
    }
};