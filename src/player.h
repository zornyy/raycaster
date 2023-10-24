#ifndef raycaster
#define raycaster

typedef struct {
  double x;
  double y;
  double direction;
} player_t;

extern player_t player;

int playerInit( double posX, double posY );


#endif // !raycaster
