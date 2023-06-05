#include "Circle.h"
#include <cmath>

using namespace std;

Circle::Circle(double newRadius) {
    setRadius(newRadius);
}

bool Circle::setRadius(double newRadius) {
    return bool(radius = (newRadius > 0) ? newRadius : 0);
}

double Circle::calcCircleArea() {
    return M_PI * radius * radius;
}