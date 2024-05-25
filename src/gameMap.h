#ifndef gameMap
#define gameMap

#include <SDL2/SDL.h>
#include "vector.h"

void drawMapTile( SDL_Rect *rect );

void drawMap( );

Vector2 getTile(Vector2 point);

int isWall( Vector2 point );

#endif // !raycaster
