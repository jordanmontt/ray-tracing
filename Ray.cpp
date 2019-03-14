#include "Ray.h"

Ray::Ray() : origin(0.0), direction(0.0, 0.0, 1.0) {}

Ray::Ray(const Point3D &origin, const Vector3D &direction) : origin(origin), direction(direction) {}

Ray::~Ray() {}
