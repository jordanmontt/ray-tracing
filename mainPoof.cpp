#include "Utilitarios.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Sphere.h"
#include "Triangle.h"
#include "GeometricObject.h"
#include "ViewPlane.h"
#include "Quadrilateral.h"
#include "ImageTexture.h"
#include "Plane.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    //ESCENA------------------------------------------------------------------
    vector<GeometricObject *> scene;

    Image backgroundImage;
    backgroundImage.read_ppm_file("./Texturas/fondo.ppm");
    ImageTexture background(&backgroundImage);

    Sphere body = Sphere(Point3D(-270.0, 0.0, -1000.0), 200.0, ColorRGB(1.0, 0.8039, 0.5804));
    body.setImTexture("./Texturas/poof-body.ppm");

    Sphere rightEye = Sphere(Point3D(-165.07, 90.46, -830.0), 60.55, ColorRGB(1.0, 1.0, 1.0));
    Sphere leftEye = Sphere(Point3D(-291.78, 95.54, -820.0), 65.16, ColorRGB(1.0, 1.0, 1.0));

    Sphere leftIris = Sphere(Point3D(-253.41, 85.57, -755.0), 27.4, ColorRGB(0.6510, 0.4078, 0.8353));
    Sphere rightIris = Sphere(Point3D(-127.48, 83.23, -755.0), 23.02, ColorRGB(0.6510, 0.4078, 0.8353));

    Sphere rightPupil = Sphere(Point3D(-116.94, 79.34, -725.0), 10.52, ColorRGB(0.0, 0.0, 0.0));
    Sphere leftPupil = Sphere(Point3D(-239.15, 80.61, -725.0), 11.52, ColorRGB(0.0, 0.0, 0.0));

    Sphere ear = Sphere(Point3D(-422.57, 27.76, -725.0), 28.814, ColorRGB(0.7686, 0.6118, 0.4274));
    ear.setImTexture("./Texturas/poof-ear.ppm");
    Triangle leftCrownTriangle = Triangle(Point3D(-457.81, 212.82, -800.0), Point3D(-441.6, 191.31, -800.0), Point3D(-416.36, 209.86, -800.0), ColorRGB(1.0, 0.8745, 0.0));
    Triangle middleCrownTriangle = Triangle(Point3D(-431.8, 233.17, -800.0), Point3D(-428.6, 200.81, -800.0), Point3D(-395.32, 225.26, -800.0), ColorRGB(1.0, 0.8745, 0.0));
    Triangle rightCrownTriangle = Triangle(Point3D(-392.47, 257.97, -800.0), Point3D(-403.74, 219.32, -800.0), Point3D(-375.85, 239.15, -800.0), ColorRGB(1.0, 0.8745, 0.0));

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

    Quadrilateral rightArm = Quadrilateral(Point3D(-402.43695, -157.37612, -600.0), Point3D(-407.77192, -68.81551, -600.0), Point3D(-453.65272, -48.5426, -600.0), Point3D(-454.71971, -157.37612, -600.0), ColorRGB(0.7569, 0.5843, 0.8941));
    Sphere leftHand = Sphere(Point3D(-104.28, -158.52, -1300.0), 38.51, ColorRGB(1.0, 0.8039, 0.5804));
    leftHand.setImTexture("./Texturas/poof-hand.ppm");
    Sphere handInBottle = Sphere(Point3D(-426.98, -186.18, -700.0), 39.1311, ColorRGB(1.0, 0.8039, 0.5804));
    handInBottle.setImTexture("./Texturas/poof-hand.ppm");
    Quadrilateral leftArm = Quadrilateral(Point3D(-88.93116, -59.13149, -1200.0), Point3D(-135.26087, -62.10503, -1200.0), Point3D(-139.0977, -135.964, -1200.0), Point3D(-74.83081, -135.964, -1200.0), ColorRGB(0.7569, 0.5843, 0.8941));

    Quadrilateral rightLeg = Quadrilateral(Point3D(-345.21, -221.07, -1000.0), Point3D(-300.0, -221.08, -1000.0), Point3D(-300.0, -161.08, -1000.0), Point3D(-345.54, -160.86, -1000.0), ColorRGB(0.7569, 0.5843, 0.8941));
    Sphere rightFoot = Sphere(Point3D(-322.55, -223.15, -1100.0), 23.0, ColorRGB(1.0, 1.0, 1.0));
    Quadrilateral leftLeg = Quadrilateral(Point3D(-244.04, -220.06, -1000.0), Point3D(-198.78, -220.21, -1000.0), Point3D(-198.73, -160.27, -1000.0), Point3D(-244.04, -159.77, -1000.0), ColorRGB(0.7569, 0.5843, 0.8941));
    Sphere leftFoot = Sphere(Point3D(-220.67, -222.72, -1100.0), 22.5, ColorRGB(1.0, 1.0, 1.0));

    Triangle faso = Triangle(Point3D(-67.25, 67.67, -800), Point3D(-266.4, -28.94, -800), Point3D(-55.78, 43.68, -800), ColorRGB(0.7529, 0.7333, 0.7176));
    faso.setImTexture("./Texturas/porrazo.ppm");

    //FOOP
    Quadrilateral FoopBodyUp = Quadrilateral(Point3D(30.0, 141.0, -1000.0), Point3D(72.0, -89.0, -1000.0), Point3D(332.0, -69.0, -1000.0), Point3D(315.0, 188.0, -1000.0), ColorRGB(0.2784, 0.5923, 0.8392));
    Quadrilateral FoopBodyDownLeft = Quadrilateral(Point3D(72.0, -89.0, -1000.0), Point3D(92.0, -194.0, -1000.0), Point3D(165.0, -187.0, -1000.0), Point3D(140.0, -83.0, -1000.0), ColorRGB(0.2274, 0.5019, 0.7059));
    Quadrilateral FoopBodyDownCenter = Quadrilateral(Point3D(140.0, -83.0, -1000.0), Point3D(165.0, -187.0, -1000.0), Point3D(258.0, -182.0, -1000.0), Point3D(273.0, -73.0, -1000.0), ColorRGB(0.4706, 0.7216, 0.9098));
    Quadrilateral FoopBodyDownRight = Quadrilateral(Point3D(273.0, -73.0, -1000.0), Point3D(258.0, -182.0, -1000.0), Point3D(340.0, -175.0, -1000.0), Point3D(332.0, -68.0, -1000.0), ColorRGB(0.2274, 0.5019, 0.7059));

    Quadrilateral FoopLateralBodyUp = Quadrilateral(Point3D(315.0, 188.0, -1200.0), Point3D(332.0, -69.0, -1200.0), Point3D(470.0, 9.0, -1200.0), Point3D(475.0, 162.0, -1200.0), ColorRGB(0.2039, 0.4627, 0.6666));
    Quadrilateral FoopLateralBodyDown = Quadrilateral(Point3D(332.0, -69.0, -1200.0), Point3D(340.0, -175.0, -1200.0), Point3D(459.0, -137.0, -1200.0), Point3D(470.0, 9.0, -1200.0), ColorRGB(0.1804, 0.3882, 0.5529));

    Quadrilateral FoopMouth = Quadrilateral(Point3D(168.0, -36.0, -900.0), Point3D(172.0, -57.0, -900.0), Point3D(259.0, -48.0, -900.0), Point3D(256.0, -27.0, -900.0), ColorRGB(0.0666, 0.2078, 0.3333));

    Triangle FoopToothLeft = Triangle(Point3D(195.0, -35.0, -850.0), Point3D(201.0, -46.0, -850.0), Point3D(206.0, -33.0, -850.0), ColorRGB(1.0, 1.0, 1.0));
    Triangle FoopToothRight = Triangle(Point3D(221.0, -31.0, -850.0), Point3D(228.0, -43.0, -850.0), Point3D(233.0, -30.0, -850.0), ColorRGB(1.0, 1.0, 1.0));

    Triangle FoopMoustacheLeft = Triangle(Point3D(164.0, -15.0, -900.0), Point3D(134.0, -45.0, -900.0), Point3D(164.0, -36.0, -900.0), ColorRGB(0.0, 0.0, 0.0));
    Triangle FoopMoustacheRight = Triangle(Point3D(259.0, -5.0, -900.0), Point3D(260.0, -25.0, -900.0), Point3D(290.0, -34.0, -900.0), ColorRGB(0.0, 0.0, 0.0));
    Triangle FoopMoustacheoDown = Triangle(Point3D(202.0, -69.0, -900.0), Point3D(203.0, -91.0, -900.0), Point3D(219.0, -69.0, -900.0), ColorRGB(0.0, 0.0, 0.0));

    Triangle FoopNose = Triangle(Point3D(177.0, 18.0, -900.0), Point3D(190.0, -6.0, -900.0), Point3D(200.0, 10.0, -900.0), ColorRGB(0.1451, 0.3059, 0.4314));

    Triangle FoopCrownOne = Triangle(Point3D(378.0, 272.0, -900.0), Point3D(369.0, 233.0, -900.0), Point3D(406.0, 225.0, -900.0), ColorRGB(1.0, 0.8745, 0.0));
    Triangle FoopCrownTwo = Triangle(Point3D(416.0, 262.0, -900.0), Point3D(391.0, 229.0, -900.0), Point3D(426.0, 222.0, -900.0), ColorRGB(1.0, 0.8745, 0.0));
    Triangle FoopCrownThree = Triangle(Point3D(457.0, 254.0, -900.0), Point3D(414.0, 224.0, -900.0), Point3D(450.0, 217.0, -900.0), ColorRGB(1.0, 0.8745, 0.0));

    Triangle FoopEar = Triangle(Point3D(419.0, 141.0, -900.0), Point3D(388.0, 81.0, -900.0), Point3D(430.0, 75.0, -900.0), ColorRGB(0.1451, 0.3059, 0.4314));

    Sphere FoopEyeLeft = Sphere(Point3D(120.61, 64.13, -900.0), 54.598, ColorRGB(1.0, 1.0, 1.0));
    Sphere FoopEyeRight = Sphere(Point3D(229.89, 83.3, -900.0), 54.598, ColorRGB(1.0, 1.0, 1.0));
    Sphere FoopEyeIrisLeft = Sphere(Point3D(90.33, 61.64, -850.0), 23.386, ColorRGB(0.6510, 0.4078, 0.8353));
    Sphere FoopEyeIrisRight = Sphere(Point3D(200.11, 79.01, -850.0), 23.386, ColorRGB(0.6510, 0.4078, 0.8353));
    Sphere FoopEyePupilLeft = Sphere(Point3D(79.11, 61.96, -800.0), 11.823, ColorRGB(0.0, 0.0, 0.0));
    Sphere FoopEyePupilRight = Sphere(Point3D(189.29, 78.36, -800.0), 11.823, ColorRGB(0.0, 0.0, 0.0));

    Quadrilateral FoopEyelashLeft = Quadrilateral(Point3D(75.42, 166.58, -900.0), Point3D(71.24, 151.81, -900.0), Point3D(167.09, 105.57, -900.0), Point3D(166.99, 115.08, -900.0), ColorRGB(0.0, 0.0, 0.0));
    Quadrilateral FoopEyelashRight = Quadrilateral(Point3D(172.25, 104.93, -900.0), Point3D(246.48, 180.21, -900.0), Point3D(245.75, 195.33, -900.0), Point3D(171.93, 114.67, -900.0), ColorRGB(0.0, 0.0, 0.0));

    Quadrilateral FoopArmLeft = Quadrilateral(Point3D(58.0, -79.0, -1100.0), Point3D(68.0, -122.0, -1100.0), Point3D(88.0, -119.0, -1100.0), Point3D(79.0, -77.0, -1100.0), ColorRGB(0.1255, 0.2745, 0.4112));
    Quadrilateral FoopArmRight = Quadrilateral(Point3D(388.0, -51.0, -900.0), Point3D(387.0, -103.0, -900.0), Point3D(481.0, -85.0, -900.0), Point3D(485.0, -35.0, -900.0), ColorRGB(0.1255, 0.2745, 0.4112));

    Quadrilateral FoopLegLeft = Quadrilateral(Point3D(175.0, -153.0, -1100.0), Point3D(153.0, -194.0, -1100.0), Point3D(207.0, -232.0, -1100.0), Point3D(228.0, -191.0, -1100.0), ColorRGB(0.1255, 0.2745, 0.4112));
    Quadrilateral FoopLegRight = Quadrilateral(Point3D(291.0, -140.0, -1100.0), Point3D(269.0, -182.0, -1100.0), Point3D(323.0, -220.0, -1100.0), Point3D(344.0, -178.0, -1100.0), ColorRGB(0.1255, 0.2745, 0.4112));

    Sphere FoopHandLeft = Sphere(Point3D(41.99, -105.95, -1200), 30.987, ColorRGB(0.3019, 0.6196, 0.8784));
    Sphere FoopHandRight = Sphere(Point3D(503.73, -59.48, -1200), 30.987, ColorRGB(0.3019, 0.6196, 0.8784));
    FoopHandRight.setImTexture("./Texturas/foop-right-hand.ppm");

    Sphere FoopFootLeft = Sphere(Point3D(227.76, -217.25, -1200), 26.089, ColorRGB(0.5215, 0.6980, 0.8510));
    Sphere FoopFootRight = Sphere(Point3D(345.19, -204.87, -1200), 26.089, ColorRGB(0.5215, 0.6980, 0.8510));

    //SCENE
    // scene.push_back(&body);
    // scene.push_back(&rightEye);
    // scene.push_back(&leftEye);
    // scene.push_back(&leftIris);
    // scene.push_back(&rightIris);
    // scene.push_back(&rightPupil);
    // scene.push_back(&leftPupil);
    // scene.push_back(&ear);
    // // scene.push_back(&faso);
    // scene.push_back(&eyelashOne);
    // scene.push_back(&eyelashTwo);
    // scene.push_back(&eyelashThree);
    // scene.push_back(&upperRightEyelash);
    // scene.push_back(&middleRightEyelash);
    // scene.push_back(&lowerRightEyelash);
    // scene.push_back(&leftCrownTriangle);
    // scene.push_back(&middleCrownTriangle);
    // scene.push_back(&rightCrownTriangle);
    // scene.push_back(&bottle);
    // scene.push_back(&bottleCap);
    // scene.push_back(&pacifier);
    // scene.push_back(&pacifierTop);
    // scene.push_back(&handInBottle);
    // scene.push_back(&rightArm);
    // scene.push_back(&leftHand);
    // scene.push_back(&leftArm);
    // scene.push_back(&rightLeg);
    // scene.push_back(&rightFoot);
    // scene.push_back(&leftLeg);
    // scene.push_back(&leftFoot);
    //FOOP
    scene.push_back(&FoopBodyUp);
    scene.push_back(&FoopBodyDownLeft);
    scene.push_back(&FoopBodyDownCenter);
    scene.push_back(&FoopBodyDownRight);
    scene.push_back(&FoopLateralBodyUp);
    scene.push_back(&FoopLateralBodyDown);
    scene.push_back(&FoopMouth);
    scene.push_back(&FoopToothLeft);
    scene.push_back(&FoopToothRight);
    scene.push_back(&FoopMoustacheLeft);
    scene.push_back(&FoopMoustacheRight);
    scene.push_back(&FoopMoustacheoDown);
    scene.push_back(&FoopNose);
    scene.push_back(&FoopCrownOne);
    scene.push_back(&FoopCrownTwo);
    scene.push_back(&FoopCrownThree);
    scene.push_back(&FoopEar);
    scene.push_back(&FoopEyeLeft);
    scene.push_back(&FoopEyeRight);
    scene.push_back(&FoopEyeIrisLeft);
    scene.push_back(&FoopEyeIrisRight);
    scene.push_back(&FoopEyePupilLeft);
    scene.push_back(&FoopEyePupilRight);
    scene.push_back(&FoopEyelashRight);
    scene.push_back(&FoopEyelashLeft);
    scene.push_back(&FoopArmLeft);
    scene.push_back(&FoopArmRight);
    scene.push_back(&FoopLegLeft);
    scene.push_back(&FoopLegRight);
    scene.push_back(&FoopHandLeft);
    scene.push_back(&FoopHandRight);
    scene.push_back(&FoopFootLeft);
    scene.push_back(&FoopFootRight);

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
    ColorRGB pixelColor;

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

            pixelColor = getPixelColor(ray, scene, spotlight, background);

            pixeles[rows * width + cols].red = pixelColor.red;
            pixeles[rows * width + cols].green = pixelColor.green;
            pixeles[rows * width + cols].blue = pixelColor.blue;
        }
    }
    savebmp("poof.bmp", width, height, dpi, pixeles);
    return 0;
}
