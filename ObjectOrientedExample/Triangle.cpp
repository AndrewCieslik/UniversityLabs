#include "Triangle.h"
#include "Square.h"

using namespace std;

Triangle::Triangle(double newSide, double newHeight) {
    setSide(newSide);
    setHeight(newHeight);
}

bool Triangle::setSide(double newSide) {
    return bool(side = (newSide > 0) ? newSide : 0);
}

bool Triangle::setHeight(double newHeight) {
    return bool(height = (newHeight > 0) ? newHeight : 0);
}

double Triangle::calcTriangleArea() {
    return 0.5 * side * height;
}
