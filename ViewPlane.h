#ifndef VIEW_PLANE_H
#define VIEW_PLANE_H

class ViewPlane
{
public:
  float squareSize;
  int horizontalResolution;
  int verticalResolution;

public:
  ViewPlane();
  ViewPlane(int horizontalResolution, int verticalResolution, double squareSize);
};
#endif