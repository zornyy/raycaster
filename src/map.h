#ifndef map
#define map

#include <SDL2/SDL.h>
#include "vector.h"

void drawMapTile( SDL_Rect *rect );

void drawMap( );

int isWall( Vector2 point );

#endif // !raycaster
