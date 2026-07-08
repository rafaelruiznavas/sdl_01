#pragma once
#include <SDL3/SDL.h>
#include "Rectangle.h"

class GreenRectangle : public Rectangle
{
public:
    GreenRectangle(const SDL_Rect& l_rect) : Rectangle(l_rect)
    {
        SetColor({0, 255, 0, 255});
    }
};