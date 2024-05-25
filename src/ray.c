#include <math.h>
#include <stdlib.h>
#include "vector.h"
#include "ray.h"
#include "gameMap.h"

// TEMP
#include "display.h"
#include <SDL2/SDL.h>

double getDistanceToWall(Vector2 origin, Vector2 direction, double maxLength) {
    
    // THOSE WILL BE USED FOR DEBUGGING IF NEEDED
    SDL_Rect test;
    test.w = 10, test.h = 10;
    SDL_Color purple;
    purple.r = 255, purple.g = 0, purple.b = 255, purple.a = SDL_ALPHA_OPAQUE;

    // ACTUAL LOGIC

    double directionRatio = direction.x / direction.y;
    
    double incX = 120 * sqrt(1 + ( (1 / directionRatio) * (1 / directionRatio) ));
    double incY = sqrt(1 + ( (1 * directionRatio) * (1 * directionRatio) ));

    printf("Increment X: %f\nIncrement Y: %f\nDirectionRatio: %f\n\n", incX, incY, directionRatio);

    // Vector2 playerTile = getTile(origin);
    // double offsetX = (origin.x / 120) - playerTile.x;
    // double offsetY = (origin.y / 120) - playerTile.y; 

    Vector2 pointToCheck = origin;

    pointToCheck = addVect2(origin, multiplyScalarVector2(direction, incX));

    pointToCheck.y += incX, pointToCheck.x += incY;
    test.x = pointToCheck.x, test.y = pointToCheck.y;
    drawRect(&test, &purple);
    // pointToCheck.x += sqrt(offsetX + ( (offsetX / directionRatio) * (offsetX / directionRatio) ));
    // pointToCheck.y += sqrt(offsetY + ( (offsetY * directionRatio) * (offsetY * directionRatio) ));

    // for (int i; i < 20; i++) {
    //     // isWall(pointToCheck);
    //     test.x = pointToCheck.x, test.y = pointToCheck.y;
    //     printf("Point position: (%d, %d)\n", test.x, test.y);
    //     drawRect(&test, &purple);

    //     pointToCheck.x += incX;
    // }

    return 100.0;
}