// struct ColorRGB
// {
//     double red;
//     double green;
//     double blue;
// };
#ifndef COLORRGB_H
#define COLORRGB_H
class ColorRGB
{
  public:
    double red;
    double green;
    double blue;

  public:
    ColorRGB();
    ColorRGB(double red, double green, double blue);
    ~ColorRGB();
};
#endif