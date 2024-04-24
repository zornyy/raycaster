#ifndef raycaster
#define raycaster

#include <SDL2/SDL.h>

typedef struct {
  double x;
  double y;
} Vector2;

typedef struct {
  Vector2 position;
  Vector2 direction;
} player_t;

typedef struct {
  int forward;
  int backward;
  int right;
  int left;
} controls_t;

int playerInit( double posX, double posY );

void drawPlayer( );

void onKeypress( int keyPressed );

void onKeyrelease( int keyReleased);

void updatePlayer( );

#endif // !raycaster
