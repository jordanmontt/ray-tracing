#ifndef Point3D_H
#define Point3D_H
#include "Vector3D.h"
#include <iostream>
using namespace std;

class Point3D
{
public:
  double x, y, z;

public:
  Point3D();
  Point3D(double n);
  Point3D(double v_x, double v_y, double v_z);
  Point3D(const Point3D &p);
  ~Point3D();
  Vector3D operator-(const Point3D &p) const;
  Point3D operator+(const Vector3D &v) const;
  Point3D operator-(const Vector3D &v) const;
  Point3D operator*(const double n) const;
  friend Point3D operator*(double n, const Point3D &p);
  void show();
};
#endif