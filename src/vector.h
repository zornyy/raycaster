#ifndef vector
#define vector

typedef struct {
  double x;
  double y;
} Vector2;

Vector2 unitVectorFromAngle( double angle );

Vector2 normalizeVect2( Vector2 vect );

Vector2 addVect2( Vector2 v1, Vector2 v2 );

Vector2 subVect2( Vector2 v1, Vector2 v2 );

Vector2 multiplyScalarVector2( Vector2 v, double s );

#endif // !vector