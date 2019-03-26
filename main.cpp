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

Point3D randomCenter()
{
  double x = (rand() % 748 + 1) - 374;
  double y = (rand() % 548 + 1) - 274;
  double z = (rand() % 400 + 1) - 400;
  Point3D p(x, y, z);
  return p;
}

ColorRGB randomColor()
{
  ColorRGB color;
  color.red = (1.0) * ((double)rand() / (double)RAND_MAX);
  color.green = (1.0) * ((double)rand() / (double)RAND_MAX);
  color.blue = (1.0) * ((double)rand() / (double)RAND_MAX);
  return color;
}

Vector3D randomVector()
{
  double x = (2.0 - 1.0) * ((double)rand() / (double)RAND_MAX) + 1.0;
  double y = (2.0 - 1.0) * ((double)rand() / (double)RAND_MAX) + 1.0;
  double z = (2.0 - 1.0) * ((double)rand() / (double)RAND_MAX) + 1.0;
  return Vector3D(x, y, z);
}

void fillSpheres(Sphere *spheres, int numberOfSpheres)
{
  for (int i = 0; i < numberOfSpheres; i++)
  {
    spheres[i].center = randomCenter();
    spheres[i].radius = 25.0;
    spheres[i].color = randomColor();
  }
}

int main()
{
  srand(time(NULL));
  // ESCENA------------------------------------------------------------------
  //ESFERAS
  // vector<GeometricObject *> scene;
  // int numberOfSpheres = 100;
  // Sphere *spheres = new Sphere[numberOfSpheres];
  // fillSpheres(spheres, numberOfSpheres);
  // for (int i = 0; i < numberOfSpheres; i++)
  //   scene.push_back(&spheres[i]);
  // //PLANOS
  // Plane plane = Plane(randomVector(), randomCenter(), randomColor());
  // // Plane plane = Plane(Vector3D(0, 0, 1), Point3D(50, 50, -100), randomColor());
  // scene.push_back(&plane);

  vector<GeometricObject *> scene;
  Triangle triangle = Triangle(randomCenter(), randomCenter(), randomCenter(), randomColor());
  scene.push_back(&triangle);
  // VIEWPLANE
  int horizontalResolution = 800;
  int verticalResolution = 600;
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

      pixeles[rows * width + cols].red = getPixelColor(ray, scene).red;
      pixeles[rows * width + cols].green = getPixelColor(ray, scene).green;
      pixeles[rows * width + cols].blue = getPixelColor(ray, scene).blue;
    }
  }
  savebmp("triangle.bmp", width, height, dpi, pixeles);
  return 0;
}
