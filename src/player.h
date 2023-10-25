#ifndef raycaster
#define raycaster

typedef struct {
  double x;
  double y;
  double direction;
} player_t;


int playerInit( double posX, double posY );

void drawPlayer( );

void movePlayer ( double direction, double distance );


#endif // !raycaster
