#include "Quadrilateral.h"

Quadrilateral::Quadrilateral() : GeometricObject() {}

Quadrilateral::Quadrilateral(Point3D A, Point3D B, Point3D C, Point3D D, ColorRGB color)
{
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    this->color = color;
}

Quadrilateral::Quadrilateral(Point3D A, Point3D B, Point3D C, Point3D D) : GeometricObject()
{
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}

Quadrilateral::~Quadrilateral() {}

bool Quadrilateral::isImpact(const Ray &ray, double &t, Vector3D &normal, Point3D &qPoint) const
{
    Triangle triangleA(A, B, C, color);
    Triangle triangleB(A, C, D, color);
    if (triangleA.isImpact(ray, t, normal, qPoint) || triangleB.isImpact(ray, t, normal, qPoint))
        return true;
    else
        return false;
}

ColorRGB Quadrilateral::getColor(Point3D hitPoint)
{
    return this->color;
}