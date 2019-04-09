#include "Triangle.h"

Triangle::Triangle() {}

Triangle::Triangle(Point3D a, Point3D b, Point3D c) : a(a), b(b), c(c) {}

Triangle::Triangle(Point3D a, Point3D b, Point3D c, ColorRGB color) : a(a), b(b), c(c), color(color) {}

bool Triangle::isImpact(const Ray &ray, double &t, Vector3D &normal, Point3D &pointQ) const
{
    double determinantDenominator, determinantBeta, determinantGamma, determinantTLine;
    double a, b, c, d, e, f, g, h, i, j, k, l;
    double beta, gamma, alpha, tLine;
    a = this->a.x - this->b.x;
    b = this->a.x - this->c.x;
    c = ray.direction.x;
    d = this->a.x - ray.origin.x;
    e = this->a.y - this->b.y;
    f = this->a.y - this->c.y;
    g = ray.direction.y;
    h = this->a.y - ray.origin.y;
    i = this->a.z - this->b.z;
    j = this->a.z - this->c.z;
    k = ray.direction.z;
    l = this->a.z - ray.origin.z;

    determinantDenominator = a * (f * k - g * j) + b * (g * i - e * k) + c * (e * j - f * i);
    determinantBeta = d * (f * k - g * j) + b * (g * l - h * k) + c * (h * j - f * l);
    determinantGamma = a * (h * k - g * l) + d * (g * i - e * k) + c * (e * l - h * i);
    determinantTLine = a * (f * l - h * j) + b * (h * i - e * l) + d * (e * j - f * i);

    beta = determinantBeta / determinantDenominator;
    gamma = determinantGamma / determinantDenominator;
    tLine = determinantTLine / determinantDenominator;
    alpha = 1.0 - beta - gamma;
    pointQ = alpha * this->a + beta * this->b + gamma * this->c;
    normal = ((this->b - this->a) ^ (this->c - this->a)).hat();
    if (beta > 0 && gamma > 0 && (beta + gamma) < 1)
        return true;
    return false;
}

void Triangle::setColor(double red, double green, double blue)
{
    this->color.red = red;
    this->color.green = green;
    this->color.blue = blue;
}

ColorRGB Triangle::getColor()
{
    ColorRGB c;
    c.red = this->color.red;
    c.green = this->color.green;
    c.blue = this->color.blue;
    return c;
}