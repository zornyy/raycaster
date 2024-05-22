#include <SDL2/SDL.h>
#include "gameMap.h"
#include "display.h"

#define MAP_WIDTH 16
#define MAP_HEIGHT 9


int miniMap[9][16] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
  {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


void drawMap( ) {
  SDL_Rect tileRect;
  tileRect.w = 1920 / MAP_WIDTH;
  tileRect.h = 1080 / MAP_HEIGHT;

  for ( int row = 0; row < MAP_HEIGHT; row++ ) {
    for ( int col = 0; col < MAP_WIDTH; col++ ) {
      if ( miniMap[row][col] ) {
        tileRect.x = col * tileRect.w;
        tileRect.y = row * tileRect.h;
        drawMapTile( &tileRect );
      }
    }
  }
}

int isWall( Vector2 point ) {
  int squareX = (int)(point.x / 120);
  int squareY = (int)(point.y / 120);

  return miniMap[squareY][squareX];
}



