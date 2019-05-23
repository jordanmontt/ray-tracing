#include "Sphere.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

Sphere::Sphere() : GeometricObject()
{
    this->isAIntersectLine = false;
    this->im = NULL;
}

Sphere::Sphere(Point3D center, double radius) : center(center), radius(radius)
{
    this->isAIntersectLine = false;
    color.red = 1.0;
    color.green = 1.0;
    color.blue = 0.0;
    this->im = NULL;
}

Sphere::Sphere(Point3D center, double radius, ColorRGB color) : center(center), radius(radius), color(color)
{
    this->im = NULL;
    this->isAIntersectLine = false;
}

Sphere::Sphere(Point3D center, double radius, ColorRGB color, Ray intersectLine) : center(center), radius(radius),
                                                                                   color(color), intersectLine(intersectLine)
{
    this->isAIntersectLine = true;
    this->im = NULL;
}

Sphere::~Sphere() {}

bool Sphere::isImpact(const Ray &ray, double &minEquationRoot, Vector3D &normal, Point3D &q) const
{
    double equationRoot;
    Vector3D originMinusCenter = ray.origin - this->center;
    double a = ray.direction * ray.direction;
    double b = 2 * ray.direction * originMinusCenter;
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
        q = ray.origin + equationRoot * ray.direction;
        // if (this->isAIntersectLine) {}
        normal = (originMinusCenter + equationRoot * ray.direction) / this->radius;
        minEquationRoot = equationRoot;
        return true;
    }
    // larger root
    equationRoot = (-b + discriminantEvaluation) / denominator;
    if (equationRoot > 0.000001)
    {
        q = ray.origin + equationRoot * ray.direction;
        normal = (originMinusCenter + equationRoot * ray.direction) / this->radius;
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

ColorRGB Sphere::getColor(Point3D hitPoint)
{
    ColorRGB c;
    if (this->im != NULL)
    {
        return im->get_color(hitPoint);
    }
    c.red = this->color.red;
    c.green = this->color.green;
    c.blue = this->color.blue;
    return c;
}

void Sphere::setHasShadow(bool shadow)
{
    this->hasShadow = shadow;
}

void Sphere::setImTexture(string path)
{
    char charArray[path.length() + 1];
    strcpy(charArray, path.c_str());
    im = new ImTexture();
    m.read_ppm_file(charArray);
    im->set_image(&m);
    im->set_SphereMap(&sm);
}