#ifndef RAYO_H
#define RAYO_H
#include "Punto3D.h"
#include "Vector3D.h"

class Rayo
{
  public:
    Punto3D o;
    Vector3D d;
  public:
    Rayo();
    Rayo(const Punto3D &origen, const Vector3D &direccion);
    ~Rayo();
};
#endif