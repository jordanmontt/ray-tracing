#include "Utilitarios.h"
#include "Ray.h"
#include "Point3D.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;
void savebmp(const char *filename, int w, int h, int dpi, ColorRGB *data)
{
	FILE *f;
	int k = w * h;
	int s = 4 * k;
	int filesize = 54 + s;
	double factor = 39.375;
	int m = static_cast<int>(factor);
	int ppm = dpi * m;

	unsigned char bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
	unsigned char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w >> 8);
	bmpinfoheader[6] = (unsigned char)(w >> 16);
	bmpinfoheader[7] = (unsigned char)(w >> 24);

	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h >> 8);
	bmpinfoheader[10] = (unsigned char)(h >> 16);
	bmpinfoheader[11] = (unsigned char)(h >> 24);

	bmpinfoheader[21] = (unsigned char)(s);
	bmpinfoheader[22] = (unsigned char)(s >> 8);
	bmpinfoheader[23] = (unsigned char)(s >> 16);
	bmpinfoheader[24] = (unsigned char)(s >> 24);

	bmpinfoheader[25] = (unsigned char)(ppm);
	bmpinfoheader[26] = (unsigned char)(ppm >> 8);
	bmpinfoheader[27] = (unsigned char)(ppm >> 16);
	bmpinfoheader[28] = (unsigned char)(ppm >> 24);

	bmpinfoheader[29] = (unsigned char)(ppm);
	bmpinfoheader[30] = (unsigned char)(ppm >> 8);
	bmpinfoheader[31] = (unsigned char)(ppm >> 16);
	bmpinfoheader[32] = (unsigned char)(ppm >> 24);

	f = fopen(filename, "wb");

	// int res = fopen(&f, filename, "wb");
	// if (res != 0) {
	// 	/* Handle error */
	// }

	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);
	for (int i = 0; i < k; i++)
	{
		ColorRGB rgb = data[i];
		double red = (data[i].red > 1.0 ? 1.0 : data[i].red) * 255;
		double green = (data[i].green > 1.0 ? 1.0 : data[i].green) * 255;
		double blue = (data[i].blue > 1.0 ? 1.0 : data[i].blue) * 255;
		unsigned char color[3] = {(int)floor(blue), (int)floor(green), (int)floor(red)};
		fwrite(color, 1, 3, f);
	}
	fclose(f);
}

ColorRGB getPixelColor(const Ray &ray, vector<GeometricObject *> geometricObjects, Spotlight spotlight)
{
	ColorRGB color;
	color.red = 0.3765;
	color.green = 0.3765;
	color.blue = 0.3765;
	double equationRoot, minEquationRoot = 2000000, maxOfLambertianEquation, maxOfPhongEquation, phongCoeficient;
	Vector3D normal, H, L;
	Point3D pointOfImpact;
	ColorRGB geometricObjectColor;
	for (int i = 0; i < geometricObjects.size(); i++)
	{
		if (geometricObjects[i]->isImpact(ray, equationRoot, normal, pointOfImpact) && equationRoot < minEquationRoot)
		{
			/* Lambertian equation  
			pixelColor = surfaceColor * spotlightColor * max(0.0, normal * L) 
			where L is the vector from the spotlight to the surface */
			/* Phong
			coeficienteEspecularSuperficie(color de la superficie) * spotlightColor * (max(0.0, normal * H) )^phongCoeficient
			where H = V + L
			where V = vector distance from the pixel to the surface */
			L = spotlight.position - pointOfImpact;
			L = L.hat();
			H = ((-1 * ray.direction) + L);
			H = H.hat();
			maxOfLambertianEquation = max(0.0, normal * L);
			maxOfPhongEquation = max(0.0, normal * H);
			phongCoeficient = 100000;
			geometricObjectColor = geometricObjects[i]->getColor();
			// Spotlight ambientLight = Spotlight(0.6953, 0.6118, 0.5176, 0.0, 0.0, -30.0);
			Spotlight ambientLight = Spotlight(0.5, 0.5, 0.5, 0.0, 0.0, -30.0);
			// ColorRGB c = randomColor();
			// Spotlight ambientLight = Spotlight(c.red, c.green, c.blue, 0.0, 0.0, -30.0);

			if (geometricObjects[i]->hasShadow)
			{
				//Phong + Lambertian + Ambient light
				color.red = geometricObjectColor.red * ambientLight.color.red + geometricObjectColor.red * spotlight.color.red * maxOfLambertianEquation + geometricObjectColor.red * spotlight.color.red * pow(maxOfPhongEquation, phongCoeficient);
				color.green = geometricObjectColor.green * ambientLight.color.green + geometricObjectColor.green * spotlight.color.green * maxOfLambertianEquation + geometricObjectColor.green * spotlight.color.green * pow(maxOfPhongEquation, phongCoeficient);
				color.blue = geometricObjectColor.blue * ambientLight.color.blue + geometricObjectColor.blue * spotlight.color.blue * maxOfLambertianEquation + geometricObjectColor.blue * spotlight.color.blue * pow(maxOfPhongEquation, phongCoeficient);
			}
			else
			{
				//Lambertian
				color.red = geometricObjectColor.red * spotlight.color.red * maxOfLambertianEquation;
				color.green = geometricObjectColor.green * spotlight.color.green * maxOfLambertianEquation;
				color.blue = geometricObjectColor.blue * spotlight.color.blue * maxOfLambertianEquation;
			}

			/*//Phong + Lambertian
			color.red = geometricObjectColor.red * spotlight.color.red * maxOfLambertianEquation + geometricObjectColor.red * spotlight.color.red * pow(maxOfPhongEquation, phongCoeficient);
			color.green = geometricObjectColor.green * spotlight.color.green * maxOfLambertianEquation + geometricObjectColor.green * spotlight.color.green * pow(maxOfPhongEquation, phongCoeficient);
			color.blue = geometricObjectColor.blue * spotlight.color.blue * maxOfLambertianEquation + geometricObjectColor.blue * spotlight.color.blue * pow(maxOfPhongEquation, phongCoeficient); */

			// color.red = geometricObjects[i]->getColor().red * spotlight.color.red * std::max(0.0, normal * (spotlight.position - pointOfImpact).hat()) + geometricObjects[i]->getColor().red * spotlight.color.red * pow(std::max(0.0, normal * ((-1) * ray.direction + (spotlight.position - pointOfImpact).hat()).hat()), 10000);
			// color.green = geometricObjects[i]->getColor().green * spotlight.color.green * std::max(0.0, normal * (spotlight.position - pointOfImpact).hat()) + geometricObjects[i]->getColor().green * spotlight.color.green * pow(std::max(0.0, normal * ((-1) * ray.direction + (spotlight.position - pointOfImpact).hat()).hat()), 10000);
			// color.blue = geometricObjects[i]->getColor().blue * spotlight.color.blue * std::max(0.0, normal * (spotlight.position - pointOfImpact).hat()) + geometricObjects[i]->getColor().blue * spotlight.color.blue * pow(std::max(0.0, normal * ((-1) * ray.direction + (spotlight.position - pointOfImpact).hat()).hat()), 10000);

			//Lambertian
			// color.red = geometricObjectColor.red * spotlight.color.red * maxOfLambertianEquation;
			// color.green = geometricObjectColor.green * spotlight.color.green * maxOfLambertianEquation;
			// color.blue = geometricObjectColor.blue * spotlight.color.blue * maxOfLambertianEquation;

			/*color.red = geometricObjects[i]->getColor().red;
			color.green = geometricObjects[i]->getColor().green;
			color.blue = geometricObjects[i]->getColor().blue; */
			minEquationRoot = equationRoot;
		}
	}
	return color;
}

Point3D randomPoint()
{
	double x = (rand() % 748 + 1) - 374;
	double y = (rand() % 548 + 1) - 274;
	double z = (rand() % 391) + 10;
	z = -z;
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
