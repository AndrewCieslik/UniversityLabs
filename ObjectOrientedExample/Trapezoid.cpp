#include "Trapezoid.h"

using namespace std;

Trapezoid::Trapezoid(double newSideUp, double newSideDown, double newHeight) {
    setSideUp(newSideUp);
    setSideDown(newSideDown);
    setHeight(newHeight);
}

bool Trapezoid::setSideUp(double newSideUp) {
    return bool(sideUp = (newSideUp > 0) ? newSideUp : 0);
}

bool Trapezoid::setSideDown(double newSideDown) {
    return bool(sideDown = (newSideDown > 0) ? newSideDown : 0);
}

bool Trapezoid::setHeight(double newHeight) {
    return bool(height = (newHeight > 0) ? newHeight : 0);
}

double Trapezoid::calcTrapezoidArea() {
    return (sideUp + sideDown) * height / 2;
}