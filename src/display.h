#ifndef display
#define display

#include <stdlib.h>
#include <SDL2/SDL.h>
#include "map.h"
#include "vector.h"

#define HEIGHT 1080
#define WIDTH 1920

// Functions definition
int displayInit( );

int renderLoop( );

void drawRect( SDL_Rect *rect, SDL_Color *color );

void drawLine( Vector2 start, Vector2 end, SDL_Color* color );

void drawMapTile( SDL_Rect *rect );

void drawPoint( double posX, double posY );

void drawMap( );
#endif 
