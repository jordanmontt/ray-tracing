#ifndef VECTOR3D_H
#define VECTOR3D_H
class Vector3D
{
  public:
    double x, y, z;

  public:
    Vector3D(double n);
    Vector3D(double x, double y, double z);
    Vector3D operator+(const Vector3D &v) const;
    Vector3D operator-(const Vector3D &v) const;
    Vector3D operator/(double number) const;
    Vector3D operator*(double number) const;
    double operator*(const Vector3D &v) const;
    Vector3D operator^(const Vector3D &v) const;    
};
#endif