#include "Vector3D.h"

Vector3D::Vector3D(double n)
{
    this->x = n;
    this->y = n;
    this->z = n;
}

Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D Vector3D::operator+(const Vector3D &v) const
{
    double newX = this->x + v.x;
    double newY = this->y + v.y;
    double newZ = this->z + v.z;
    return Vector3D(newX, newY, newZ);
}

Vector3D Vector3D::operator-(const Vector3D &v) const
{
    double newX = this->x - v.x;
    double newY = this->y - v.y;
    double newZ = this->z - v.z;
    return Vector3D(newX, newY, newZ);
}

Vector3D Vector3D::operator/(double number) const
{
    double newX = this->x / number;
    double newY = this->y / number;
    double newZ = this->z / number;
    return Vector3D(newX, newY, newZ);
}

Vector3D Vector3D::operator*(double number) const
{
    double newX = this->x * number;
    double newY = this->y * number;
    double newZ = this->z * number;
    return Vector3D(newX, newY, newZ);
}

double Vector3D::operator*(const Vector3D &v) const
{
    return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
}

Vector3D Vector3D::operator^(const Vector3D &v) const
{
    double newX = (this->y * v.z) - (v.y * this->z);
    double newY = -(this->x * v.z) + (v.x * this->z);
    double newZ = (this->x * v.y) - (v.x * this->y);
    return Vector3D(newX, newY, newZ);
}
