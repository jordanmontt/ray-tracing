#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H
#include "Ray.h"
#include "ColorRGB.h"
#include "Point3D.h"

class GeometricObject
{
public:
  bool hasShadow;

public:
  GeometricObject();
  virtual bool isImpact(const Ray &ray, double &t, Vector3D &n, Point3D &q) const = 0;
  virtual ColorRGB getColor() = 0;
  virtual void setHasShadow(bool shadow) = 0;
};
#endif