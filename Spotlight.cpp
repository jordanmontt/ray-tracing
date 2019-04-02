#include "Spotlight.h"
Spotlight::Spotlight(double red, double green, double blue, double xCoordinates, double yCoordinates, double zCoordinates)
{
    this->color.red = red;
    this->color.green = green;
    this->color.blue = blue;
    this->position.x = xCoordinates;
    this->position.y = yCoordinates;
    this->position.z = zCoordinates;
}