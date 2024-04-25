#ifndef display
#define display

#include <stdlib.h>
#include <SDL2/SDL.h>
#include "map.h"
#include "vector.h"


// Functions definition
int displayInit( );

int renderLoop( );

void drawRect( SDL_Rect *rect, SDL_Color *color );
void drawLine( Vector2 start, Vector2 end, SDL_Color* color );

void drawMapTile( SDL_Rect *rect );

void drawPoint( double posX, double posY );

void drawMap( );
#endif 
