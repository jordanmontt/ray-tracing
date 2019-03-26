#include "Plane.h"

Plane::Plane() {}

Plane::Plane(Vector3D normal, Point3D p) : normal(normal), p(p) {}

Plane::Plane(Vector3D normal, Point3D p, ColorRGB color) : normal(normal), p(p), color(color) {}

bool Plane::isImpact(const Ray &ray, double &t, Vector3D &n, Point3D &q) const
{
    double numerator = (this->p - ray.origin) * this->normal;
    double denominator = ray.direction * this->normal;
    if (numerator == 0 && denominator == 0)
        return false;
    t = numerator / denominator;
    q = ray.origin + t * ray.direction;
    n = this->normal;
    return true;
}

void Plane::setColor(double red, double green, double blue)
{
    this->color.red = red;
    this->color.green = green;
    this->color.blue = blue;
}

ColorRGB Plane::getColor()
{
    ColorRGB c;
    c.red = this->color.red;
    c.green = this->color.green;
    c.blue = this->color.blue;
    return c;
}