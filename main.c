#include <stdio.h>
#include <stdlib.h>

#include "src/display.h"
#include "src/player.h"

int main( int argv, char *argc[] ) { 
  displayInit( );
  playerInit( 100.0, 100.0 );
  renderLoop( );
  return 0;
}
