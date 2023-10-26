#ifndef raycaster
#define raycaster

typedef struct {
  double x;
  double y;
  double direction;
  double speed;
} player_t;

typedef struct {
  double x;
  double y;
} point_2d;

int playerInit( double posX, double posY );

void drawPlayer( );

void movePlayer ( int direction );


#endif // !raycaster
