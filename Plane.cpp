#include "Plane.h"

Plane::Plane() : GeometricObject() {}

Plane::Plane(Vector3D normal, Point3D p) : normal(normal), p(p)
{
    this->limitsDefined = false;
}

Plane::Plane(Vector3D normal, Point3D p, ColorRGB color) : normal(normal), p(p), color(color)
{
    this->limitsDefined = false;
}

Plane::Plane(Vector3D normal, Point3D p, ColorRGB color, double upperLimit,
             double rightLimit, double lowerLimit, double leftLimit) : normal(normal),
                                                                       p(p), color(color), upperLimit(upperLimit), rightLimit(rightLimit), lowerLimit(lowerLimit), leftLimit(leftLimit)
{
    this->limitsDefined = true;
}

bool Plane::isImpact(const Ray &ray, double &t, Vector3D &n, Point3D &q) const
{
    double numerator = (this->p - ray.origin) * this->normal;
    double denominator = ray.direction * this->normal;
    if (denominator == 0)
        return false;
    t = numerator / denominator;
    q = ray.origin + t * ray.direction;
    n = this->normal;
    if (this->limitsDefined)
    {
        if (q.x > this->rightLimit || q.x < this->leftLimit)
            return false;
        if (q.y > this->upperLimit || q.y < this->lowerLimit)
            return false;
    }
    return true;
}

void Plane::setColor(double red, double green, double blue)
{
    this->color.red = red;
    this->color.green = green;
    this->color.blue = blue;
}

ColorRGB Plane::getColor(Point3D hitPoint)
{
    ColorRGB c;
    c.red = this->color.red;
    c.green = this->color.green;
    c.blue = this->color.blue;
    return c;
}

void Plane::setHasShadow(bool shadow)
{
    this->hasShadow = shadow;
}