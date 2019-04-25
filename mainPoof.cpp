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

vector<GeometricObject *> makeScene()
{
    vector<GeometricObject *> scene;
    Sphere body = Sphere(Point3D(-270.0, 0.0, -500.0), 240.0, ColorRGB(1.0, 0.8039, 0.5804));

    scene.push_back(&body);
    return scene;
}

int main()
{
    srand(time(NULL));
    //ESCENA------------------------------------------------------------------
    //ESFERAS
    vector<GeometricObject *> scene;
    Sphere body = Sphere(Point3D(-270.0, 0.0, -1000.0), 200.0, ColorRGB(1.0, 0.8039, 0.5804));

    // Sphere rightEye = Sphere(Point3D(-165.07, 90.46, -830.0), 60.55, ColorRGB(1.0, 0.6549, 0.8235));
    // Sphere leftEye = Sphere(Point3D(-291.78, 95.54, -820.0), 65.16, ColorRGB(1.0, 0.6549, 0.8235));

    Sphere rightEye = Sphere(Point3D(-165.07, 90.46, -830.0), 60.55, ColorRGB(1.0, 1.0, 1.0));
    Sphere leftEye = Sphere(Point3D(-291.78, 95.54, -820.0), 65.16, ColorRGB(1.0, 1.0, 1.0));

    Sphere leftIris = Sphere(Point3D(-253.41, 85.57, -755.0), 27.4, ColorRGB(0.6510, 0.4078, 0.8353));
    Sphere rightIris = Sphere(Point3D(-127.48, 83.23, -755.0), 23.02, ColorRGB(0.6510, 0.4078, 0.8353));

    Sphere rightPupil = Sphere(Point3D(-116.94, 79.34, -725.0), 10.52, ColorRGB(0.0, 0.0, 0.0));
    Sphere leftPupil = Sphere(Point3D(-239.15, 80.61, -725.0), 11.52, ColorRGB(0.0, 0.0, 0.0));

    Triangle eyelashOne = Triangle(Point3D(-385.6, 111.88, -800), Point3D(-388.03, 99.24, -800), Point3D(-357.24, 99.7, -800), ColorRGB(0.0, 0.0, 0.0));
    Triangle eyelashTwo = Triangle(Point3D(-380.61, 130.18, -800), Point3D(-384.81, 118.53, -800), Point3D(-356.32, 113.48, -800), ColorRGB(0.0, 0.0, 0.0));
    Triangle eyelashThree = Triangle(Point3D(-371.74, 148.47, -800), Point3D(-376.54, 135.99, -800), Point3D(-348.51, 129.33, -800), ColorRGB(0.0, 0.0, 0.0));

    Triangle faso = Triangle(Point3D(-67.25, 67.67, -800), Point3D(-266.4, -28.94, -800), Point3D(-55.78, 43.68, -800), ColorRGB(0.18, 0.2274, 0.1333));

    scene.push_back(&body);
    scene.push_back(&rightEye);
    scene.push_back(&leftEye);
    scene.push_back(&leftIris);
    scene.push_back(&rightIris);
    scene.push_back(&rightPupil);
    scene.push_back(&leftPupil);
    scene.push_back(&faso);
    scene.push_back(&eyelashOne);
    scene.push_back(&eyelashTwo);
    scene.push_back(&eyelashThree);

    // Spotlight spotlight = Spotlight(1.0, 1.0, 1.0, 0.0, 0.0, -30.0);
    Spotlight spotlight = Spotlight(0.5, 0.5, 0.5, 0.0, 0.0, -30.0);

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
    savebmp("poof.bmp", width, height, dpi, pixeles);
    return 0;
}
