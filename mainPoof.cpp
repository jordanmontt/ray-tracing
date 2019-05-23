#include "Utilitarios.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Sphere.h"
#include "Triangle.h"
#include "GeometricObject.h"
#include "ViewPlane.h"
#include "Quadrilateral.h"
#include "Plane.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    //ESCENA------------------------------------------------------------------
    //ESFERAS
    vector<GeometricObject *> scene;
    Sphere body = Sphere(Point3D(-270.0, 0.0, -1000.0), 200.0, ColorRGB(1.0, 0.8039, 0.5804));
    body.setImTexture("./Texturas/poof.ppm");

    // Sphere rightEye = Sphere(Point3D(-165.07, 90.46, -830.0), 60.55, ColorRGB(1.0, 0.6549, 0.8235));
    // Sphere leftEye = Sphere(Point3D(-291.78, 95.54, -820.0), 65.16, ColorRGB(1.0, 0.6549, 0.8235));

    Sphere rightEye = Sphere(Point3D(-165.07, 90.46, -830.0), 60.55, ColorRGB(1.0, 1.0, 1.0));
    Sphere leftEye = Sphere(Point3D(-291.78, 95.54, -820.0), 65.16, ColorRGB(1.0, 1.0, 1.0));

    Sphere leftIris = Sphere(Point3D(-253.41, 85.57, -755.0), 27.4, ColorRGB(0.6510, 0.4078, 0.8353));
    Sphere rightIris = Sphere(Point3D(-127.48, 83.23, -755.0), 23.02, ColorRGB(0.6510, 0.4078, 0.8353));

    Sphere rightPupil = Sphere(Point3D(-116.94, 79.34, -725.0), 10.52, ColorRGB(0.0, 0.0, 0.0));
    Sphere leftPupil = Sphere(Point3D(-239.15, 80.61, -725.0), 11.52, ColorRGB(0.0, 0.0, 0.0));

    Sphere ear = Sphere(Point3D(-422.57, 27.76, -725.0), 28.814, ColorRGB(0.7686, 0.6118, 0.4274));

    Triangle leftCrownTriangle = Triangle(Point3D(-457.81, 212.82, -800.0), Point3D(-441.6, 191.31, -800.0), Point3D(-416.36, 209.86, -800.0), ColorRGB(1.0, 0.8745, 0.0));
    Triangle middleCrownTriangle = Triangle(Point3D(-431.8, 233.17, -800.0), Point3D(-428.6, 200.81, -800.0), Point3D(-395.32, 225.26, -800.0), ColorRGB(1.0, 0.8745, 0.0));
    Triangle rightCrownTriangle = Triangle(Point3D(-392.47, 257.97, -800.0), Point3D(-403.74, 219.32, -800.0), Point3D(-375.85, 239.15, -800.0), ColorRGB(1.0, 0.8745, 0.0));

    // Quadrilateral eyelashOne = Quadrilateral(Point3D(-388.24, 101.21, -800.0), Point3D(-359.65, 98.42, -800.0), Point3D(-356.56, 108.94, -800.0), Point3D(-385.92, 116.66, -800.0));
    // eyelashOne.color = ColorRGB(0.0, 0.0, 0.0);
    // Quadrilateral eyelashTwo = Quadrilateral(Point3D(-378.97, 131.34, -800.0), Point3D(-351.92, 123.62, -800.0), Point3D(-347.29, 131.34, -800.0), Point3D(-370.47, 145.25, -800.0));
    // eyelashTwo.color = ColorRGB(0.0, 0.0, 0.0);
    // Quadrilateral eyelashThree = Quadrilateral(Point3D(-360.42, 156.07, -800), Point3D(-338.02, 142.93, -800.0), Point3D(-330.29, 149.88, -800.0), Point3D(-348.06, 169.2, -800.0));
    // eyelashThree.color = ColorRGB(0.0, 0.0, 0.0);

    Quadrilateral eyelashOne = Quadrilateral(Point3D(-353.76, 118.48, -800.0), Point3D(-351.15, 123.7, -800.0), Point3D(-377.24, 139.35, -800.0), Point3D(-384.42, 126.31, -800.0));
    eyelashOne.color = ColorRGB(0.0, 0.0, 0.0);
    Quadrilateral eyelashTwo = Quadrilateral(Point3D(-345.28, 132.83, -800.0), Point3D(-341.74, 137.86, -800.0), Point3D(-365.18, 155.01, -800.0), Point3D(-373.33, 143.27, -800.0));
    eyelashTwo.color = ColorRGB(0.0, 0.0, 0.0);
    Quadrilateral eyelashThree = Quadrilateral(Point3D(-335.5, 143.27, -800), Point3D(-330.6, 147.18, -800.0), Point3D(-349.19, 170.34, -800.0), Point3D(-360.0, 160.0, -800.0));
    eyelashThree.color = ColorRGB(0.0, 0.0, 0.0);

    Quadrilateral upperRightEyelash = Quadrilateral(Point3D(-109.08, 162.0, -800.0), Point3D(-127.37, 137.71, -800.0), Point3D(-124.07, 134.41, -800.0), Point3D(-98.88, 150.01, -800.0));
    upperRightEyelash.color = ColorRGB(0.0, 0.0, 0.0);
    Quadrilateral middleRightEyelash = Quadrilateral(Point3D(-94.62, 146.55, -800.0), Point3D(-116.96, 128.13, -800.0), Point3D(-113.03, 122.25, -800.0), Point3D(-86.01, 135.07, -800.0));
    middleRightEyelash.color = ColorRGB(0.0, 0.0, 0.0);
    Quadrilateral lowerRightEyelash = Quadrilateral(Point3D(-82.28, 130.57, -800.0), Point3D(-110.09, 114.34, -800.0), Point3D(-107.28, 107.59, -800.0), Point3D(-76.1, 115.89, -800.0));
    lowerRightEyelash.color = ColorRGB(0.0, 0.0, 0.0);

    Quadrilateral bottle = Quadrilateral(Point3D(-470.52, -151.26, -800.0), Point3D(-510.8, -186.18, -800.0), Point3D(-426.04, -271.53, -800.0), Point3D(-384.32, -235.32, -800.0));
    bottle.color = ColorRGB(0.8627, 0.85098, 0.8039);
    Quadrilateral bottleCap = Quadrilateral(Point3D(-426.96, -286.28, -800.0), Point3D(-368.84, -236.23, -800.0), Point3D(-376.37, -229.19, -800.0), Point3D(-434.49, -278.42, -800.0));
    bottleCap.color = ColorRGB(0.8078, 0.5647, 0.6235);

    Sphere pacifier = Sphere(Point3D(-395.9, -264.4, -900.0), 29.5733, ColorRGB(0.8078, 0.5647, 0.6235));
    Sphere pacifierTop = Sphere(Point3D(-374.12, -284.94, -900.0), 8.34146, ColorRGB(0.8078, 0.5647, 0.6235));

    Sphere handInBottle = Sphere(Point3D(-426.98, -186.18, -700.0), 39.1311, ColorRGB(1.0, 0.8039, 0.5804));
    Quadrilateral rightArm = Quadrilateral(Point3D(-402.43695, -157.37612, -600.0), Point3D(-407.77192, -68.81551, -600.0), Point3D(-453.65272, -48.5426, -600.0), Point3D(-454.71971, -157.37612, -600.0), ColorRGB(0.7569, 0.5843, 0.8941));
    Sphere leftHand = Sphere(Point3D(-104.28, -158.52, -1300.0), 38.51, ColorRGB(1.0, 0.8039, 0.5804));
    Quadrilateral leftArm = Quadrilateral(Point3D(-88.93116, -59.13149, -1200.0), Point3D(-135.26087, -62.10503, -1200.0), Point3D(-139.0977, -135.964, -1200.0), Point3D(-74.83081, -135.964, -1200.0), ColorRGB(0.7569, 0.5843, 0.8941));

    Quadrilateral rightLeg = Quadrilateral(Point3D(-345.21, -221.07, -1000.0), Point3D(-300.0, -221.08, -1000.0), Point3D(-300.0, -161.08, -1000.0), Point3D(-345.54, -160.86, -1000.0), ColorRGB(0.7569, 0.5843, 0.8941));
    Sphere rightFoot = Sphere(Point3D(-322.55, -223.15, -1100.0), 23.0, ColorRGB(1.0, 1.0, 1.0));
    Quadrilateral leftLeg = Quadrilateral(Point3D(-244.04, -220.06, -1000.0), Point3D(-198.78, -220.21, -1000.0), Point3D(-198.73, -160.27, -1000.0), Point3D(-244.04, -159.77, -1000.0), ColorRGB(0.7569, 0.5843, 0.8941));
    Sphere leftFoot = Sphere(Point3D(-220.67, -222.72, -1100.0), 22.5, ColorRGB(1.0, 1.0, 1.0));

    Triangle faso = Triangle(Point3D(-67.25, 67.67, -800), Point3D(-266.4, -28.94, -800), Point3D(-55.78, 43.68, -800), ColorRGB(0.18, 0.2274, 0.1333));

    scene.push_back(&body);
    scene.push_back(&rightEye);
    scene.push_back(&leftEye);
    scene.push_back(&leftIris);
    scene.push_back(&rightIris);
    scene.push_back(&rightPupil);
    scene.push_back(&leftPupil);
    scene.push_back(&ear);
    scene.push_back(&faso);
    scene.push_back(&eyelashOne);
    scene.push_back(&eyelashTwo);
    scene.push_back(&eyelashThree);
    scene.push_back(&upperRightEyelash);
    scene.push_back(&middleRightEyelash);
    scene.push_back(&lowerRightEyelash);
    scene.push_back(&leftCrownTriangle);
    scene.push_back(&middleCrownTriangle);
    scene.push_back(&rightCrownTriangle);
    scene.push_back(&bottle);
    scene.push_back(&bottleCap);
    scene.push_back(&pacifier);
    scene.push_back(&pacifierTop);
    scene.push_back(&handInBottle);
    scene.push_back(&rightArm);
    scene.push_back(&leftHand);
    scene.push_back(&leftArm);
    scene.push_back(&rightLeg);
    scene.push_back(&rightFoot);
    scene.push_back(&leftLeg);
    scene.push_back(&leftFoot);

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
