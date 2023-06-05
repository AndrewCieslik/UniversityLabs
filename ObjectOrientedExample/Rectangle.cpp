#include "Rectangle.h"
#include "Square.h"

using namespace std;

Rectangle::Rectangle(double newSide, double newHeight) {
    setSide(newSide);
    setHeight(newHeight);
}

Rectangle::Rectangle(Square & someSquare){
    setSide(someSquare.getSide());
    setSide(someSquare.getSide());
}

bool Rectangle::setSide(double newSide) {
    return bool(side = (newSide > 0) ? newSide : 0);
}

bool Rectangle::setHeight(double newHeight) {
    return bool(height = (newHeight > 0) ? newHeight : 0);
}

double Rectangle::calcRectangleArea() {
    return side * height;
}
