#pragma once
#include "raylib.h"

struct FontSettings
{
    FontSettings(int size = 0, Color color = BLACK, Font fontFamily = GetFontDefault(), int spacing = 8)
    {
        FontSize = size;
        FontColor = color;
        FontFamily = fontFamily;
        Spacing = spacing;
    }

    int FontSize;
    int Spacing;
    Color FontColor;
    Font FontFamily;
};
