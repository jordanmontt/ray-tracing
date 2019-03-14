#ifndef Ray_H
#define Ray_H
#include "Point3D.h"
#include "Vector3D.h"

class Ray
{
  public:
    Point3D origin;
    Vector3D direction;
  public:
    Ray();
    Ray(const Point3D &origin, const Vector3D &direction);
    ~Ray();
};
#endif