#ifndef DISPLAY_H
#define DISPLAY_H
#include "color.h"
#include "SDL.h"

extern SDL_Renderer* renderer;

void show_cell(int x, int y, const Color& color, int zoom);

#endif