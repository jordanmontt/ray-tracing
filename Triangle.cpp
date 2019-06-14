#include "Triangle.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

Triangle::Triangle() : GeometricObject()
{
    this->im = NULL;
}

Triangle::Triangle(Point3D a, Point3D b, Point3D c) : A(a), B(b), C(c)
{
    this->im = NULL;
}

Triangle::Triangle(Point3D a, Point3D b, Point3D c, ColorRGB color) : A(a), B(b), C(c), color(color)
{
    this->im = NULL;
}

bool Triangle::isImpact(const Ray &ray, double &tmin, Vector3D &normal, Point3D &pointQ) const
{
    double determinantDenominator, determinantBeta, determinantGamma, determinantTLine;
    double a, b, c, d, e, f, g, h, i, j, k, l;
    double beta, gamma, alpha, tLine;
    a = this->A.x - this->B.x;
    b = this->A.x - this->C.x;
    c = ray.direction.x;
    d = this->A.x - ray.origin.x;
    e = this->A.y - this->B.y;
    f = this->A.y - this->C.y;
    g = ray.direction.y;
    h = this->A.y - ray.origin.y;
    i = this->A.z - this->B.z;
    j = this->A.z - this->C.z;
    k = ray.direction.z;
    l = this->A.z - ray.origin.z;

    determinantDenominator = a * (f * k - g * j) + b * (g * i - e * k) + c * (e * j - f * i);
    determinantBeta = d * (f * k - g * j) + b * (g * l - h * k) + c * (h * j - f * l);
    determinantGamma = a * (h * k - g * l) + d * (g * i - e * k) + c * (e * l - h * i);
    determinantTLine = a * (f * l - h * j) + b * (h * i - e * l) + d * (e * j - f * i);

    beta = determinantBeta / determinantDenominator;
    gamma = determinantGamma / determinantDenominator;
    tLine = determinantTLine / determinantDenominator;

    alpha = 1.0 - beta - gamma;
    pointQ = ray.origin + tLine * ray.direction;
    normal = ((this->B - this->A) ^ (this->C - this->A)).hat();
    tmin = tLine;
    if (beta > 0.0 && gamma > 0.0 && (beta + gamma) < 1.0)
        return true;
    return false;
}

void Triangle::setColor(double red, double green, double blue)
{
    this->color.red = red;
    this->color.green = green;
    this->color.blue = blue;
}

ColorRGB Triangle::getColor(Point3D hitPoint)
{
    if (this->im != NULL)
    {
        return im->get_color(hitPoint);
    }
    ColorRGB c;
    c.red = this->color.red;
    c.green = this->color.green;
    c.blue = this->color.blue;
    return c;
}

void Triangle::setHasShadow(bool shadow)
{
    this->hasShadow = shadow;
}

void Triangle::setImTexture(string path)
{
    char charArray[path.length() + 1];
    strcpy(charArray, path.c_str());
    im = new ImTexture();
    m.read_ppm_file(charArray);
    im->set_image(&m);
    im->set_SphereMap(&sm);
}