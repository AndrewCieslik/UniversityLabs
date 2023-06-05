#ifndef SQUARE_H
#define SQUARE_H

class Square {
private:
    double side;

public:
    Square(double side = 0);

    double getSide();

    bool setSide(double newSide);

    double calcSquareArea();

};

#endif
