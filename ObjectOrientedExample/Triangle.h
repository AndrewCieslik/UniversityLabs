#ifndef ORIENTEDCPP_TRIANGLE_H
#define ORIENTEDCPP_TRIANGLE_H

class Triangle {
private:
    double side;
    double height;
public:
    Triangle(double newSide = 0, double height = 0);

    bool setSide(double newSide);

    bool setHeight(double newHeight);

    double calcTriangleArea();
};

#endif //ORIENTEDCPP_TRIANGLE_H
