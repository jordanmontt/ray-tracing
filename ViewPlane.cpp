#include "ViewPlane.h"

ViewPlane::ViewPlane() : verticalResolution(400), horizontalResolution(600), squareSize(1.0) {}

ViewPlane::ViewPlane(int verticalResolution, int v_vrhorizontalResolutiones, double squareSize)
    : verticalResolution(verticalResolution), horizontalResolution(horizontalResolution),
      squareSize(squareSize) {}
