#include <iostream>
#include <cctype>
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Trapezoid.h"

using namespace std;

void displayMenu() {
    cout << "Calculate area:" << endl;
    cout << "1- Square" << endl;
    cout << "2- Rectangle" << endl;
    cout << "3- Triangle" << endl;
    cout << "4- Circle" << endl;
    cout << "5- Trapezoid" << endl;
}

void calculateArea(char shapeChoice) {
    switch (shapeChoice) {
        double input;
        case '1': {
            Square square;
            do {

                cout << "Enter the side length of the square: " << endl;
                cin >> input;
            } while (!square.setSide(input));

            cout << "Square area: " << square.calcSquareArea() << endl;
            break;
        }
        case '2': {
            Rectangle rectangle;
            do {
                cout << "Enter the side length of the rectangle: " << endl;
                cin >> input;
            } while (!rectangle.setSide(input));
            do {
                cout << "Enter the side height of the rectangle: " << endl;
                cin >> input;
            } while (!rectangle.setHeight(input));

            cout << "Rectangle area: " << rectangle.calcRectangleArea() << endl;
            break;
        }
        case '3': {
            Triangle triangle;
            do {
                cout << "Enter the side length of the triangle: " << endl;
                cin >> input;
            } while (!triangle.setSide(input));
            do {
                cout << "Enter the side height of the triangle: " << endl;
                cin >> input;
            } while (!triangle.setHeight(input));

            cout << "Triangle area: " << triangle.calcTriangleArea() << endl;
            break;
        }
        case '4': {
            Circle circle;
            do {
                cout << "Enter the radius of the circle: " << endl;
                cin >> input;
            } while (!circle.setRadius(input));
            cout << "Circle area: " << circle.calcCircleArea() << endl;
            break;
        }
        case '5': {
            Trapezoid trapezoid;
            do {
                cout << "Enter the upper side of the trapezoid " << endl;
                cin >> input;
            } while (!trapezoid.setSideUp(input));
            do {
                cout << "Enter the lower side of the trapezoid " << endl;
                cin >> input;
            } while (!trapezoid.setSideDown(input));
            do {
                cout << "Enter the height of the trapezoid " << endl;
                cin >> input;
            } while (!trapezoid.setHeight(input));

            cout << "Trapezoid area: " << trapezoid.calcTrapezoidArea() << endl;
            break;
        }
    }
}

int main() {
    char choiceToContinue;

    do {
        char shapeChoice;
        do {
            displayMenu();
            std::cout << "Choose a shape: ";
            std::cin >> shapeChoice;
        } while (!isdigit(shapeChoice));

        calculateArea(shapeChoice);

        std::cout << "Calculate again? Enter choice (T/t): ";
        std::cin >> choiceToContinue;
    } while (tolower(choiceToContinue) == 't');

    return 0;
}
