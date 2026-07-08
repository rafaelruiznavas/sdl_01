#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include <memory>
#include "Rectangle.h"
#include "GreenRectangle.h"


class Grid
{
    std::vector<std::unique_ptr<Rectangle>> m_rectangles;

public:
    Grid()
    {
        int verticalPosition{65};
        int rowCount{3}, colCount{12};
        m_rectangles.reserve(rowCount * colCount);

        for(int row{0}; row < rowCount; ++row)
        {
            for(int col{0}; col < colCount; ++col)
            {
                bool useGreen{(row + col)%2 == 0};
                m_rectangles.emplace_back(useGreen ? 
                    std::make_unique<GreenRectangle>(SDL_Rect{60 * col, 60 * row + verticalPosition, 50, 50}) :
                    std::make_unique<Rectangle>(SDL_Rect{60 * col, 60 * row + verticalPosition, 50, 50}));
            }
        }
    }

    void Render(SDL_Surface* l_surface) const
    {
        for(auto& rectangle : m_rectangles)
        {
            rectangle->Render(l_surface);
        }
    }

    void HandleEvent(SDL_Event& l_e)
    {
        for(auto& rectangle : m_rectangles)
        {
            rectangle->HandleEvent(l_e);
        }
    }
};