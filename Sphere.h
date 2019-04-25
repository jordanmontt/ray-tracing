#include "Ray.h"
#include "Point3D.h"
#include "GeometricObject.h"

class Sphere : public GeometricObject
{
public:
  Point3D center;
  double radius;
  ColorRGB color;
  Ray intersectLine;
  bool isAIntersectLine;

public:
  Sphere();
  Sphere(Point3D center, double radius);
  Sphere(Point3D center, double radius, ColorRGB color);
  Sphere(Point3D center, double radius, ColorRGB color, Ray intersectLine);
  ~Sphere();
  bool isImpact(const Ray &ray, double &minEquationRoot, Vector3D &n, Point3D &q) const;
  void setColor(double red, double green, double blue);
  ColorRGB getColor();
  void setHasShadow(bool shadow);
};