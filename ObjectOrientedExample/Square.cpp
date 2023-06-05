#include <istream>
#include "Square.h"

using namespace std;

Square::Square(double newSide) {
    setSide(newSide);
}

double Square::getSide() {
    return side;
}

bool Square::setSide(double newSide) {
    return bool(side = (newSide > 0) ? newSide : 0);
}

double Square::calcSquareArea() {
    return side * side;
}
