#include <math.h>
#include <SDL2/SDL.h>
#include "player.h"
#include "display.h"
#include "vector.h"

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
  controls.mouseSensitivity = 0.2;
}

// This function initializes the player with it's position, direction etc. etc.
int playerInit( double posX, double posY ) {
  SDL_Log("Initializing player\n");
  player.position.x = posX;
  player.position.y = posY;
  player.angle = 35;
  player.direction = unitVectorFromAngle(player.angle);

  playerRect.h = 10;
  playerRect.w = 10;

  initControls();

  return 1;
}

// Function draws the player on screen
void drawPlayer( ) {
  playerRect.x = player.position.x - 5;
  playerRect.y = player.position.y - 5;
  drawRect( &playerRect, &purple );

  Vector2 endOfLine = addVect2( multiplyScalarVector2( player.direction, 100 ), player.position);
  drawLine( player.position, endOfLine, &purple );
}

void onMouseMoved( SDL_MouseMotionEvent motionEvent ) {
  // Calculate the x distance between them
  double XOffset = controls.mousePos.x - motionEvent.x; 

  SDL_Log("X Offset: %f", XOffset);

  // Update player direction accordingly
  player.angle += XOffset * controls.mouseSensitivity;

  SDL_Log("Player angle: %f", player.angle);

  player.direction = unitVectorFromAngle(player.angle);

  // Store the new position of the mouse
  controls.mousePos.x = motionEvent.x;
  controls.mousePos.y = motionEvent.y;
}

void setMousePosition( Vector2 mPos ) {
  controls.mousePos = mPos;
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
  if ( controls.forward ) {
    player.position = addVect2(player.position, player.direction);
  }
  if ( controls.backward ) {
    player.position = subVect2(player.position, player.direction);
  }
  if ( controls.left ) {
    player.angle -= 1;
    player.direction = unitVectorFromAngle(player.angle);
  }
    if ( controls.right ) {
      player.angle += 1;
    player.direction = unitVectorFromAngle(player.angle);
  }
}