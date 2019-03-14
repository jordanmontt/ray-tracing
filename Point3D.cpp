#include "Point3D.h"

Point3D::Point3D() : x(0), y(0), z(0) {}

Point3D::Point3D(double n) : x(n), y(n), z(n) {}

Point3D::Point3D(double v_x, double v_y, double v_z) : x(v_x), y(v_y), z(v_z) {}

Point3D::Point3D(const Point3D &p) : x(p.x), y(p.y), z(p.z) {}

Point3D::~Point3D() {}

Vector3D Point3D::operator-(const Point3D &p) const
{
    return Vector3D(this->x - p.x, this->y - p.y, this->z - p.z);
}

Point3D Point3D::operator+(const Vector3D &v) const
{
    return Point3D(this->x + v.x, this->y + v.y, this->z + v.z);
}

Point3D Point3D::operator+(const Point3D &p) const
{
    return Point3D(this->x + p.x, this->y + p.y, this->z + p.z);
}

Point3D Point3D::operator-(const Vector3D &v) const
{
    return Point3D(this->x - v.x, this->y - v.y, this->z - v.z);
}

Point3D Point3D::operator*(const double n) const
{
    return Point3D(this->x * n, this->y * n, this->z * n);
}

Point3D operator*(double n, const Point3D &p)
{
    return Point3D(p.x * n, p.y * n, p.z * n);
}

void Point3D::show()
{
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}