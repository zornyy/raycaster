#include <SDL2/SDL.h>
#include <stdbool.h>
#include "player.h"
#include "display.h"
#include "map.h"
#include "vector.h"


// SDL Variables
SDL_Window *window;
SDL_Renderer *renderer;

// Framerate
const int FPS = 60;
const int frameDelay = 1000 / FPS;
Uint64 frameStart;
Uint64 frameTime;


// Private functions
int fixFramerate( ) {
  frameTime = SDL_GetTicks() - frameStart;

  if ( frameDelay > frameTime ) {
    SDL_Delay( frameDelay - frameTime );
  }
}

// Public functions
void clearDisplay( ) {
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
  SDL_RenderClear( renderer );
}

void drawRect( SDL_Rect *rect, SDL_Color *color ) {
  SDL_SetRenderDrawColor( renderer, color->r, color->g, color->b, color->a );
  SDL_RenderFillRect( renderer, rect );
}

void drawLine( Vector2 start, Vector2 end, SDL_Color* color ) {
  SDL_SetRenderDrawColor( renderer, color->r, color->g, color->b, color->a );
  SDL_RenderDrawLine( renderer, start.x, start.y, end.x, end.y );
}

void drawMapTile( SDL_Rect *rect ) {
  SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
  SDL_RenderDrawRect( renderer, rect );
}

void drawPoint( double posX, double posY ) {
  SDL_SetRenderDrawColor( renderer, 255, 0, 255, 255 );
  SDL_RenderDrawPoint( renderer, posX, posY );
  SDL_Log( "Drew player at x = %f, y = %f", posX, posY );
}

void wrapMouse( ) {
  int mouseX, mouseY;
  SDL_GetMouseState( &mouseX, &mouseY );

  if (mouseX <= 0) {
    SDL_WarpMouseInWindow(window, WIDTH, mouseY); // Wrap to the right edge
  } else if (mouseX >= WIDTH - 1) {
    SDL_WarpMouseInWindow(window, 0, mouseY); // Wrap to the left edge
  } 
  
  if (mouseY <= 0) {
    SDL_WarpMouseInWindow(window, mouseX, HEIGHT); // Wrap to the bottom edge
  } else if (mouseY >= HEIGHT - 1) {
    SDL_WarpMouseInWindow(window, mouseX, 0); // Wrap to the top edge
  }

  Vector2 pos = {mouseX, mouseY};

  setMousePosition(pos);
}

int displayInit( ) {
 SDL_Init( SDL_INIT_EVERYTHING );

  window = SDL_CreateWindow(
    "raycaster",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    WIDTH,
    HEIGHT,
    SDL_WINDOW_ALLOW_HIGHDPI
  );

  if ( NULL == window ) {
    printf("Could not create window");
    return 1;
  }

  renderer = SDL_CreateRenderer( window, -1, 0 );
  if ( NULL == renderer ) {
    printf("Could not create renderer");
    return 1;
  }

  // IDK why it does not work but it ain't urgent
  // SDL_EnableKeyRepeat(0, 0); // Disables key repeat
  SDL_SetRelativeMouseMode( SDL_TRUE );

  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
  SDL_RenderClear( renderer );
  SDL_RenderPresent( renderer );

  return 0;
}

int renderLoop( ) {
  SDL_Event windowEvent; // Store current event

  // Main loop
  bool isRunning = true;
  while ( isRunning ) {
    frameStart = SDL_GetTicks( );
    
    // Handle SDL events
    while ( SDL_PollEvent( &windowEvent ) ) {
      if ( SDL_QUIT == windowEvent.type ) {
        isRunning = false;
      } else if ( SDL_KEYDOWN == windowEvent.type ) {
        onKeypress( windowEvent.key.keysym.sym );
      } else if ( SDL_KEYUP == windowEvent.type ) {
        onKeyrelease( windowEvent.key.keysym.sym );
      } else if ( SDL_MOUSEMOTION == windowEvent.type ) {
        onMouseMoved( windowEvent.motion );
      }
    }

    // Handle player movement & update
    updatePlayer( );

    // WrapMousePosition
    wrapMouse( );

    // Clear display before drawing frame
    clearDisplay( );
    
    // Tick content
    drawMap( );
    drawPlayer( );

    // Render current frame
    SDL_RenderPresent( renderer );
    
    fixFramerate( );
  }

  SDL_DestroyWindow( window );
  SDL_Quit( );

  return EXIT_SUCCESS;
}
