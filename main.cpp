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

  return 0;
}