#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H
#include "Point3D.h"
#include "ColorRGB.h"
class Spotlight
{
  public:
    Point3D position;
    ColorRGB color;

  public:
    Spotlight(double red, double green, double blue, double xCoordinates, double yCoordinates, double zCoordinates);
};
#endif