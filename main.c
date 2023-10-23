#include <stdio.h>
#include <stdlib.h>

#include "src/display.h"

int main( int argv, char *argc[] ) {
  displayInit( );
  renderLoop( );
  return 0;
}
