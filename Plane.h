#ifndef PLANE_H
#define PLANE_H
#include "Vector3D.h"
#include "Point3D.h"
#include "GeometricObject.h"

class Plane : public GeometricObject
{
  public:
    Vector3D normal;
    Point3D p;
    ColorRGB color;

  public:
    Plane();
    Plane(Vector3D normal, Point3D p);
    Plane(Vector3D normal, Point3D p, ColorRGB color);
    bool isImpact(const Ray &ray, double &t, Vector3D &n, Point3D &q) const;
    void setColor(double red, double green, double blue);
    ColorRGB getColor();
};
#endif