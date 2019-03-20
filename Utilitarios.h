#include "GeometricObject.h"
#include <vector>

void savebmp(const char *filename, int w, int h, int dpi, ColorRGB *data);
ColorRGB getPixelColor(const Ray &ray, vector<GeometricObject*> geometricObjects);
