#include "Utilitarios.h"
#include <iostream>
#include "Vector3D.h"
#include "Point3D.h"

using namespace std;

bool isInTheMiddleCoordinates(int x, int length)
{
  return (x > (length / 4) && x < length / 4 * 3);
}

int main()
{
  /*int dpi = 72;
  int width = 640;
  int height = 480;
  int n = width * height;
  ColorRGB *pixeles = new ColorRGB[n];
  for (int x = 0; x < width; x++)
  {
    for (int y = 0; y < height; y++)
    {
      if (isInTheMiddleCoordinates(y, height) && isInTheMiddleCoordinates(x, width))
      {
        pixeles[y * width + x].red = 0.0;
        pixeles[y * width + x].green = 0.0;
        pixeles[y * width + x].blue = 0.0;
      }
      else
      {
        pixeles[y * width + x].red = 1.0;
        pixeles[y * width + x].green = 0.0;
        pixeles[y * width + x].blue = 0.0;
      }
    }
  }

  savebmp("img.bmp", width, height, dpi, pixeles);*/

  // //ejercicio 1
  // int c = 6;
  // Vector3D v = Vector3D(6, 9, 6);
  // (v * c).show();

  // //ejercicio 2
  // Vector3D a = Vector3D(1, 1, 1);
  // Vector3D b = Vector3D(2, 3, 4);
  // cout << a * b << endl;

  // //ejercicio 3
  // Vector3D vec = Vector3D(6, 6, 6);
  // int n = 3;
  // (vec / n).show();

  // //ejercicio 4
  // Vector3D v1 = Vector3D(1, 1, 1);
  // Vector3D v2 = Vector3D(2, 2, 2);
  // (v1 + v2).show();
  // (v1 - v2).show();

  // //ejercicio 5
  // Point3D p = Point3D(1, 2, 3);
  // Vector3D vector = Vector3D(3, 3, 3);
  // (p - v).show();

  // //ejercicio 6
  // Point3D p1 = Point3D(5, 4, 3);
  // Point3D p2 = Point3D(2, 2, 2);
  // (p1 - p2).show();

  // //ejercicio 7
  // Vector3D va = Vector3D(1, 1, 1);
  // Vector3D vb = Vector3D(2, 3, 4);
  // (a ^ b).show();

  // //ejercicio 8
  // Vector3D vec1 = Vector3D(1, 2, 3);
  // Point3D pun1 = Point3D(1, 2, 3);
  // (pun1 + vec1).show();

  Point3D pun1 = Point3D(1, 2, 3);
  Point3D pun2 = Point3D(1, 2, 3);
  (pun1 + pun2).show();
  return 0;
}