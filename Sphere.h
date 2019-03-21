#include "Ray.h"
#include "Point3D.h"
#include "GeometricObject.h"

class Sphere : public GeometricObject
{
public:
  Point3D center;
  double radius;
  ColorRGB color;

public:
  Sphere();
  Sphere(Point3D center, double radius);
  Sphere(Point3D center, double radius, ColorRGB color);
  ~Sphere();
  bool isImpact(const Ray &ray, double &minEquationRoot, Vector3D &n, Point3D &q) const;
  void setColor(double red, double green, double blue);
  ColorRGB getColor();
};