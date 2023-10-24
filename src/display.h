#ifndef raycaster
#define raycaster

#include <stdlib.h>
#include <SDL2/SDL.h>

#include "map.h"


// Functions definition
int displayInit( );

int renderLoop( );

void drawRect( SDL_Rect *rect, SDL_Color *color );

void drawMapTile( SDL_Rect *rect );

#endif 
