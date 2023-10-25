#include <math.h>
#include <SDL2/SDL.h>
#include "player.h"
#include "display.h"

#define PI 3.141592654

player_t player;
SDL_Rect playerRect;
SDL_Color purple = { 255, 0, 255, 255 };

int playerInit( double posX, double posY ) {
  SDL_Log("Initializing player\n");
  player.x = posX;
  player.y = posY;
  player.direction = 0;
  
  playerRect.h = 10;
  playerRect.w = 10;

  return 1;
}

void drawPlayer( ) {
  playerRect.x = player.x - 5;
  playerRect.y = player.y - 5;
  drawRect( &playerRect, &purple );
}

void movePlayer( double direction, double distance ) {
  direction = ( direction * PI ) / 180;
  double x = cos( direction ) * distance;
  player.x += x;
  player.y += sqrt( pow( distance, 2 ) - pow( x, 2 ) );
}
