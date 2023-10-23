#include <SDL2/SDL.h>
#include <stdbool.h>
#include "display.h"

#define HEIGHT 1080
#define WIDTH 1920


// SDL Variables
SDL_Window *window;
SDL_Renderer *renderer;

// Framerate
const int FPS = 60;
const int frameDelay;
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
void drawRect( SDL_Rect *rect, SDL_Color *color ) {
  SDL_SetRenderDrawColor( renderer, color->r, color->g, color->b, color->a );
  SDL_RenderFillRect( renderer, rect );
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
      }
    }
    
    // Tick content
    

    // Render current frame
    SDL_RenderPresent( renderer );
    
    fixFramerate( );
  }

  SDL_DestroyWindow( window );
  SDL_Quit( );

  return EXIT_SUCCESS;
}
