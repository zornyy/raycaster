#include "vector.h"

#define PI 3.14159265

Vector2 addVect2(Vector2 v1, Vector2 v2) {
  Vector2 res = {v1.x + v2.x, v1.y + v2.y};
  return res;
}

Vector2 subVect2(Vector2 v1, Vector2 v2) {
  Vector2 res = {v1.x - v2.x, v1.y - v2.y};
  return res;
}

Vector2 multiplyScalarVector2( Vector2 v, double s ) {
  Vector2 res = {v.x * s, v.y * s};
  return res;
}

Vector2 unitVectorFromAngle( double angle ) { 
  angle = angle * PI / 180; // Convert to radians
  Vector2 vect = {cos( angle ), sin( angle )}; // calculate unit vector for angle
  return vect;
}

// I might want to use the fast inverse sqrt as a meme for this function (instead of doing expensive calculations)
Vector2 normalizeVect2( Vector2 vect ) {
  double norm = sqrt(vect.x * vect.x) + sqrt(vect.y * vect.y); // Calculate the norm
  Vector2 unitVect; 
  unitVect.x = 1 / norm * vect.x; // 1 / ||vect|| * vect => unit vector
  unitVect.y = 1 / norm * vect.y; // Same for y component

  return unitVect;
}
