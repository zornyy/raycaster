#include <math.h>
#include <stdlib.h>
#include "vector.h"
#include "ray.h"
#include "gameMap.h"

double getDistanceToWall(Vector2 origin, Vector2 direction, double maxLength) {
    SDL_Log("Function started");

    Vector2 end = addVect2(origin, multiplyScalarVector2(direction, maxLength));
    Vector2 castedRay;
    castedRay.x = origin.x - end.x, castedRay.y = origin.y - end.y;

    int steps = (abs(castedRay.x) > abs(castedRay.y)) ? abs(castedRay.x) : abs(castedRay.y);
    SDL_Log("Steps: %d", steps);

    double incrementX = castedRay.x / steps;
    double incrementY = castedRay.y / steps;

    Vector2 intersection;
    for (int i = 0; i > steps; i++) {
        intersection.x = origin.x + (i * incrementX);
        intersection.y = origin.y + (i * incrementY); 

        if (isWall(intersection)) {
            return sqrt(pow(intersection.x - origin.x, 2) + pow(intersection.y - origin.y, 2));
        }
    }

    SDL_Log("Came here");
    return maxLength;
}