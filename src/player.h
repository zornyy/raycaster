#ifndef raycaster
#define raycaster

#include <SDL2/SDL.h>
#include "./vector.h"

typedef struct {
  Vector2 position;
  Vector2 direction; 
  double angle;
} player_t;
// NOTE: I kept the direction vector even tho it is not strictly needed to avoid 
// always having to calculate that vector from the angle

typedef struct {
  int forward;
  int backward;
  int right;
  int left;
  Vector2 mousePos;
  double mouseSensitivity;
} controls_t;

int playerInit( double posX, double posY );

void drawPlayer( );

void onMouseMoved( SDL_MouseMotionEvent motionEvent );

void onKeypress( int keyPressed );

void onKeyrelease( int keyReleased);

void updatePlayer( );

#endif // !raycaster
