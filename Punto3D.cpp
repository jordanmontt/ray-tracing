#include "Punto3D.h"

Punto3D::Punto3D() : x(0), y(0), z(0) {}

Punto3D::Punto3D(double n) : x(n), y(n), z(n) {}

Punto3D::Punto3D(double v_x, double v_y, double v_z) : x(v_x), y(v_y), z(v_z) {}

Punto3D::Punto3D(const Punto3D &p) : x(p.x), y(p.y), z(p.z) {}

Punto3D::~Punto3D() {}

Vector3D Punto3D::operator-(const Punto3D &p) const
{
    return Vector3D(this->x - p.x, this->y - p.y, this->z - p.z);
}

Punto3D Punto3D::operator+(const Vector3D &v) const
{
    return Punto3D(this->x + v.x, this->y + v.y, this->z + v.z);
}

Punto3D Punto3D::operator-(const Vector3D &v) const
{
    return Punto3D(this->x - v.x, this->y - v.y, this->z - v.z);
}

Punto3D Punto3D::operator*(const double n) const
{
    return Punto3D(this->x * n, this->y * n, this->z * n);
}

Punto3D operator*(double n, const Punto3D &p)
{
    return Punto3D(p.x * n, p.y * n, p.z * n);
}