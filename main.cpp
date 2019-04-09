#include "Utilitarios.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Sphere.h"
#include "Triangle.h"
#include "GeometricObject.h"
#include "ViewPlane.h"
#include "Plane.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
  srand(time(NULL));
  vector<GeometricObject *> scene;

  // Triangle triangle = Triangle(randomPoint(), randomPoint(), randomPoint(), randomColor());
  // scene.push_back(&triangle);

  Sphere sphere = Sphere(Point3D(0.0, 0.0, -400.0), 120.0, randomColor());
  // sphere.setColor(0.5, 0.3, 0.3);
  sphere.setColor(0.568, 0.0901, 0.1215);
  scene.push_back(&sphere);
  // LUZ
  Spotlight spotlight = Spotlight(1.0, 1.0, 1.0, 0.0, 0.0, -30.0);
  // VIEWPLANE
  int horizontalResolution = 1080;
  int verticalResolution = 720;
  double squareSize = 1.0;
  ViewPlane viewPlane(horizontalResolution, verticalResolution, squareSize);

  // UTILITARIO PARA GUARDAR IMAGEN -------------------------------------------------------------------
  int dpi = 72;
  int width = viewPlane.horizontalResolution;
  int height = viewPlane.verticalResolution;
  ColorRGB *pixeles = new ColorRGB[width * height];

  // ALGORITMO
  for (int rows = 0; rows < viewPlane.verticalResolution; rows++)
  {
    for (int cols = 0; cols < viewPlane.horizontalResolution; cols++)
    {
      // Disparar un rayo
      Vector3D direction(0.0, 0.0, -1.0);
      double x = viewPlane.squareSize * (cols - viewPlane.horizontalResolution / 2 + 0.5);
      double y = viewPlane.squareSize * (rows - viewPlane.verticalResolution / 2 + 0.5);
      double z = 0;
      Point3D origin(x, y, z);
      Ray ray(origin, direction);

      pixeles[rows * width + cols].red = getPixelColor(ray, scene, spotlight).red;
      pixeles[rows * width + cols].green = getPixelColor(ray, scene, spotlight).green;
      pixeles[rows * width + cols].blue = getPixelColor(ray, scene, spotlight).blue;
    }
  }
  savebmp("aaa.bmp", width, height, dpi, pixeles);
  return 0;
}
