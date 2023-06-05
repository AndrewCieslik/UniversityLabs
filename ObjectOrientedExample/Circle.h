//
// Created by Andrew on 04.06.2023.
//

#ifndef ORIENTEDCPP_CIRCLE_H
#define ORIENTEDCPP_CIRCLE_H


class Circle {
private:
    double radius;
public:
    Circle(double radius = 0);

    bool setRadius(double newRadius);

    double calcCircleArea();
};


#endif //ORIENTEDCPP_CIRCLE_H
