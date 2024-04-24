#include <math.h>
#include <SDL2/SDL.h>
#include "player.h"
#include "display.h"

#define PI 3.14159265

player_t player;
controls_t controls;
SDL_Rect playerRect;
SDL_Color purple = { 255, 0, 255, 255 };


void initControls( ) {
  controls.forward = 0;
  controls.backward = 0;
  controls.right = 0;
  controls.right = 0;
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
}

Vector2 addVect2(Vector2 v1, Vector2 v2) {
  Vector2 res;
  res.x = v1.x + v2.x;
  res.y = v1.y + v2.y;
  return res;
}

Vector2 subVect2(Vector2 v1, Vector2 v2) {
  Vector2 res;
  res.x = v1.x - v2.x;
  res.y = v1.y - v2.y;
  return res;
}

Vector2 unitVectorFromAngle( double angle ) { 
  angle = angle * PI / 180; // Convert to radians
  Vector2 vect = {cos( angle ), sin( angle )}; // calculate unit vector for angle
  return vect;
}

// I might want to use the fast inverse sqrt as a meme for this function (instead of doing expensive calculations)
Vector2 normalizeVect2( Vector2 vect ) {
  double norm = sqrt(vect.x * vect.x) + sqrt(vect.y * vect.y); // Calculate the norm
  Vector2 unitVect; 
  unitVect.x = 1 / norm * vect.x; // 1 / ||vect|| * vect => unit vector
  unitVect.y = 1 / norm * vect.y; // Same for y component

  return unitVect;
}

// Those functions must be optimized with arrays and intexes to make it cleaner
void onKeypress( int keyPressed ) {
  switch ( keyPressed ) {
    case SDLK_w:
      SDL_Log("Started moving forward");
      controls.forward = 1;
      break;
    
    case SDLK_d:
      SDL_Log("Started moving right");
      controls.right = 1;
      break;
    
    case SDLK_s:
      SDL_Log("Started moving backward");
      controls.backward = 1;
      break;

    case SDLK_a:
      SDL_Log("Started moving left");
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
}