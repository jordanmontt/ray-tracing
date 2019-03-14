#ifndef PUNTO3D_H
#define PUNTO3D_H
#include "Vector3D.h"
class Punto3D
{
  public:
    double x, y, z;

  public:
    Punto3D();
    Punto3D(double n);
    Punto3D(double v_x, double v_y, double v_z);
    Punto3D(const Punto3D &p);
    ~Punto3D();
    Vector3D operator-(const Punto3D &p) const;
    Punto3D operator+(const Vector3D &v) const;
    Punto3D operator-(const Vector3D &v) const;
    Punto3D operator*(const double n) const;
    friend Punto3D operator*(double n, const Punto3D &p);
};
#endif