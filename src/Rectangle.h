#pragma once
#include <iostream>
#include <SDL3/SDL.h>

class Rectangle
{
    SDL_Rect m_rect;
    SDL_Color m_color { 255, 0, 0, 255};
    SDL_Color m_hoverColor { 0, 0, 255, 255};

    bool m_isPointerHovering{false};
    bool isWithinRect(int x, int y)
    {
        if(x < m_rect.x) return false;
        if(x > m_rect.x + m_rect.w) return false;
        if(y < m_rect.y) return false;
        if(y > m_rect.y + m_rect.h) return false;

        return true;
    }
public:
    Rectangle(const SDL_Rect& l_rect) : m_rect(l_rect) {}
    virtual ~Rectangle() = default;

    virtual void Render(SDL_Surface* l_surface) const
    {
        auto [r, g, b, a] {
            m_isPointerHovering ? m_hoverColor : m_color
        };
        const auto* fmt = SDL_GetPixelFormatDetails(l_surface->format);

        SDL_FillSurfaceRect(
            l_surface,
            &m_rect,
            SDL_MapRGB(fmt, nullptr, r, g, b)
        );
    }

    void SetColor(const SDL_Color& l_color)
    {
        m_color = l_color;
    }

    SDL_Color GetColor() const {
        return m_color;
    }

    void HandleEvent(SDL_Event& l_e)
    {
        if(l_e.type == SDL_EVENT_MOUSE_MOTION)
        {
            //isPointerHovering = isWithinRect((int)l_e.motion.x, (int)l_e.motion.y); 
            
            SDL_Point mousePosition{(int)l_e.motion.x, (int)l_e.motion.y};
            m_isPointerHovering = SDL_PointInRect(&mousePosition, &m_rect);
        }
        else if(l_e.type == SDL_EVENT_WINDOW_MOUSE_LEAVE)
        {
            m_isPointerHovering = false;
        }
        else if(l_e.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
        {
            if(m_isPointerHovering && l_e.button.button == SDL_BUTTON_LEFT)
            {
                std::cout << "Left Click" << std::endl;
            }
        }
    }

    void SetHoverColor(const SDL_Color& l_color)
    {
        m_hoverColor = l_color;
    }

    SDL_Color GetHoverColor() const {
        return m_hoverColor;
    }

};