#include "display.h"
#include "SDL.h"



// Affiche un rectangle aux coordonnées voulues

void show_cell(int x, int y, const Color& color, int zoom)
{
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, SDL_ALPHA_OPAQUE);

	SDL_Rect rectangle[1];

	rectangle[0].h = zoom;
	rectangle[0].w = zoom;
	rectangle[0].x = y * zoom;
	rectangle[0].y = x * zoom;

	SDL_RenderFillRect(renderer, rectangle);
}