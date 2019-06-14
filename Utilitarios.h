#include "GeometricObject.h"
#include "Spotlight.h"
#include "ImageTexture.h"
#include <vector>

void savebmp(const char *filename, int w, int h, int dpi, ColorRGB *data);
ColorRGB getPixelColor(const Ray &ray, vector<GeometricObject *> geometricObjects, Spotlight spotlight, ImageTexture &background);
Point3D randomPoint();
Vector3D randomVector();
ColorRGB randomColor();