#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include <iostream>
#include "Point3D.h"
#include "ColorRGB.h"
#include "GeometricObject.h"
#include "Triangle.h"
using namespace std;

class Quadrilateral : public GeometricObject
{
public:
    Point3D A, B, C, D;
    ColorRGB color;

public:
    Quadrilateral();
    Quadrilateral(Point3D A, Point3D B, Point3D C, Point3D D, ColorRGB color);
    Quadrilateral(Point3D A, Point3D B, Point3D C, Point3D D);
    ~Quadrilateral();
    bool isImpact(const Ray &ray, double &t, Vector3D &n, Point3D &q) const;
    ColorRGB getColor(Point3D);
};
#endif