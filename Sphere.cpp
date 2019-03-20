#include "Sphere.h"
#include <iostream>
#include <math.h>
using namespace std;

Sphere::Sphere() {}

Sphere::Sphere(Point3D center, double radius) : center(center), radius(radius)
{
    color.red = 1.0;
    color.green = 1.0;
    color.blue = 0.0;
}

Sphere::Sphere(Point3D center, double radius, ColorRGB color) : center(center), radius(radius), color(color) {}

Sphere::~Sphere() {}

bool Sphere::isImpact(const Ray &rayo, double &minEquationRoot, Vector3D &n, Point3D &q) const
{
    double equationRoot;
    Vector3D originMinusCenter = rayo.origin - this->center;
    double a = rayo.direction * rayo.direction;
    double b = 2 * rayo.direction * originMinusCenter;
    double c = originMinusCenter * originMinusCenter - this->radius * this->radius;
    double discriminant = b * b - 4.0 * a * c;
    if (discriminant < 0.0)
        return false;

    double discriminantEvaluation = sqrt(discriminant);
    double denominator = 2.0 * a;
    // smaller root
    equationRoot = (-b - discriminantEvaluation) / denominator;
    if (equationRoot > 0.000001)
    {
        q = rayo.origin + equationRoot * rayo.direction;
        n = (originMinusCenter + equationRoot * rayo.direction) / this->radius;
        minEquationRoot = equationRoot;
        return true;
    }
    // larger root
    equationRoot = (-b + discriminantEvaluation) / denominator;
    if (equationRoot > 0.000001)
    {
        q = rayo.origin + equationRoot * rayo.direction;
        n = (originMinusCenter + equationRoot * rayo.direction) / this->radius;
        minEquationRoot = equationRoot;
        return true;
    }
}

void Sphere::setColor(double red, double green, double blue)
{
    this->color.red = red;
    this->color.green = green;
    this->color.blue = blue;
}

ColorRGB Sphere::getColor()
{
    ColorRGB c;
    c.red = this->color.red;
    c.green = this->color.green;
    c.blue = this->color.blue;
    return c;
}