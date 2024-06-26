#include <math.h>
#include <SDL2/SDL.h>
#include "gameMap.h"
#include "player.h"
#include "display.h"
#include "vector.h"
#include "ray.h"

player_t player;
controls_t controls;
SDL_Rect playerRect;
SDL_Color purple = { 255, 0, 255, 255 };


void initControls( ) {
  controls.forward = 0;
  controls.backward = 0;
  controls.right = 0;
  controls.right = 0;

  controls.mousePos.x = 0, controls.mousePos.y = 0;
  controls.mouseSensitivity = 0.05;
}

// This function initializes the player with it's position, direction etc. etc.
int playerInit( double posX, double posY ) {
  SDL_Log("Initializing player\n");
  player.position.x = posX;
  player.position.y = posY;
  player.angle = 35;
  player.direction = unitVectorFromAngle(player.angle);
  player.speed = 2.5;

  playerRect.h = 10;
  playerRect.w = 10;

  initControls();

  return 1;
}

double getPlayerAngle( ) {
  return player.angle;
}

void setPlayerAngle( double angle ) {
  player.angle = angle;
  player.direction = unitVectorFromAngle( player.angle );
}

// Function draws the player on screen
void drawPlayer( ) {
  playerRect.x = player.position.x - 5;
  playerRect.y = player.position.y - 5;
  drawRect( &playerRect, &purple );

  double length = getDistanceToWall(player.position, player.direction, 1000.0);

  Vector2 endOfLine = addVect2( multiplyScalarVector2( player.direction, 1000 ), player.position);
  drawLine( player.position, endOfLine, &purple );
}

// Those functions must be optimized with arrays and intexes to make it cleaner
void onKeypress( int keyPressed ) {
  switch ( keyPressed ) {
    case SDLK_w:
      controls.forward = 1;
      break;
    
    case SDLK_d:
      controls.right = 1;
      break;
    
    case SDLK_s:
      controls.backward = 1;
      break;

    case SDLK_a:
      controls.left = 1;
      break;
  }
}

void onKeyrelease( int keyReleased ) {
  switch ( keyReleased ) {
    case SDLK_w:
      controls.forward = 0;
      break;
    
    case SDLK_d:
      controls.right = 0;
      break;
    
    case SDLK_s:
      controls.backward = 0;
      break;

    case SDLK_a:
      controls.left = 0;
      break;
  }
}

void updatePlayer( ) {
  player.direction = unitVectorFromAngle(player.angle);
  
  Vector2 newPos;
  Vector2 movement;

  if ( controls.forward ) {
    movement = multiplyScalarVector2(player.direction, player.speed);
  }
  if ( controls.backward ) {
    movement = multiplyScalarVector2(unitVectorFromAngle(player.angle - 180), player.speed);
  }
  if ( controls.left ) {
    movement = multiplyScalarVector2(unitVectorFromAngle(player.angle - 90), player.speed);
  }
  if ( controls.right ) {
    movement = multiplyScalarVector2(unitVectorFromAngle(player.angle + 90), player.speed);
  }

  newPos = addVect2(player.position, movement);

  if (!isWall(newPos)) {
    player.position = newPos;
  }
}