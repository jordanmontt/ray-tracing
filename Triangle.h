#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Vector3D.h"
#include "Point3D.h"
#include "GeometricObject.h"
#include "ImTexture.h"

class Triangle : public GeometricObject
{
public:
  Point3D A;
  Point3D B;
  Point3D C;
  ColorRGB color;

  ImTexture *im;
  Image m;
  SphereMap sm;

public:
  Triangle();
  Triangle(Point3D a, Point3D b, Point3D c);
  Triangle(Point3D a, Point3D b, Point3D c, ColorRGB color);
  bool isImpact(const Ray &ray, double &t, Vector3D &n, Point3D &q) const;
  void setColor(double red, double green, double blue);
  ColorRGB getColor(Point3D);
  void setHasShadow(bool shadow);
  void setImTexture(string path);
};
#endif