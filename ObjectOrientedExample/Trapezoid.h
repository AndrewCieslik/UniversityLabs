//
// Created by Andrew on 04.06.2023.
//

#ifndef ORIENTEDCPP_TRAPEZOID_H
#define ORIENTEDCPP_TRAPEZOID_H


class Trapezoid {
private:
    double sideUp;
    double sideDown;
    double height;
public:
    Trapezoid(double sideUp = 0, double sideDown = 0, double height = 0);

    bool setSideUp(double newSideUp);

    bool setSideDown(double newSideDown);

    bool setHeight(double newHeight);

    double calcTrapezoidArea();
};


#endif //ORIENTEDCPP_TRAPEZOID_H
