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
  player.speed = 1;
  
  playerRect.h = 10;
  playerRect.w = 10;

  return 1;
}

void drawPlayer( ) {
  playerRect.x = player.x - 5;
  playerRect.y = player.y - 5;
  drawRect( &playerRect, &purple );
}

point_2d calcMovement(
    double x, 
    double y, 
    double direc,
    double dist 
  ) {
  direc = ( direc * PI ) / 180;
  x += cos( direc ) * dist;
  y += sqrt( pow( dist, 2 ) - pow( x, 2 ) );
  point_2d res = { x, y };
  return res;
}

void movePlayer( int direction ) {
  point_2d newPos;
  switch ( direction ) {
    case SDLK_w:
      newPos = calcMovement( 
        player.x, 
        player.y, 
        player.direction, 
        player.speed 
      );
      break;
    
    case SDLK_d:
      newPos = calcMovement( 
        player.x, 
        player.y, 
        player.direction + 90, 
        player.speed 
      );
      break;
    
    case SDLK_s:
      newPos = calcMovement( 
        player.x, 
        player.y, 
        player.direction + 180, 
        player.speed 
      );
      break;

    case SDLK_a:
      newPos = calcMovement( 
        player.x, 
        player.y, 
        player.direction + 270, 
        player.speed 
      );
      break;
  }

  player.x = newPos.x;
  player.y = newPos.y;
}
