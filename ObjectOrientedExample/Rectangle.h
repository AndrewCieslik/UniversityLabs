#ifndef ORIENTEDCPP_RECTANGLE_H
#define ORIENTEDCPP_RECTANGLE_H

#include "Square.h"

class Rectangle {
private:
    double side;
    double height;
public:
    Rectangle(double side = 0, double height = 0);

    Rectangle(Square &);

    bool setSide(double newSide);

    bool setHeight(double newHeight);

    double calcRectangleArea();
};

#endif //ORIENTEDCPP_RECTANGLE_H
