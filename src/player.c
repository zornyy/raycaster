#include <SDL2/SDL.h>
#include "player.h"

player_t player;

int playerInit( double posX, double posY ) {
  SDL_Log("Initializing player\n");
  player.x = posX;
  player.y = posY;
  player.direction = 0;

  return 1;
}
