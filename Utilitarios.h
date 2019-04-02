#include "GeometricObject.h"
#include <vector>

void savebmp(const char *filename, int w, int h, int dpi, ColorRGB *data);
ColorRGB getPixelColor(const Ray &ray, vector<GeometricObject *> geometricObjects);
Point3D randomPoint();
Vector3D randomVector();
ColorRGB randomColor();