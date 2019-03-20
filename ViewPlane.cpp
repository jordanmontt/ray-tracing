#include "ViewPlane.h"

ViewPlane::ViewPlane() : verticalResolution(400), horizontalResolution(600), squareSize(1.0) {}

ViewPlane::ViewPlane(int horizontalResolution, int verticalResolution, double squareSize)
    : horizontalResolution(horizontalResolution), verticalResolution(verticalResolution),
      squareSize(squareSize) {}
