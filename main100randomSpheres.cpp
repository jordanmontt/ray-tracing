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

void fillSpheres(Sphere *spheres, int numberOfSpheres)
{
    for (int i = 0; i < numberOfSpheres; i++)
    {
        spheres[i].center = randomPoint();
        spheres[i].radius = 50.0;
        spheres[i].color = randomColor();
    }
}

int main()
{
    srand(time(NULL));
    //ESCENA------------------------------------------------------------------
    //ESFERAS
    vector<GeometricObject *> scene;
    int numberOfSpheres = 100;
    Sphere *spheres = new Sphere[numberOfSpheres];
    fillSpheres(spheres, numberOfSpheres);
    for (int i = 0; i < numberOfSpheres; i++)
        scene.push_back(&spheres[i]);
    //PLANOS
    // Plane plane = Plane(randomVector(), randomPoint(), randomColor());
    // scene.push_back(&plane);

    ColorRGB c = randomColor();
    // Spotlight spotlight = Spotlight(1.0, 1.0, 1.0, 0.0, 0.0, -30.0);
    Spotlight spotlight = Spotlight(c.red, c.green, c.blue, 0.0, 0.0, -30.0);

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
    savebmp("randomSpheres.bmp", width, height, dpi, pixeles);
    return 0;
}
