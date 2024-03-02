#include <iostream>
#include <cmath>
using namespace std;
class Figure {
protected:
    double side;

public:
    Figure()
    {

    }
    Figure(double s) 
    {
        side = s; 
    }

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Square : public Figure {
public:
    Square()
    {

    }
    Square(double s)
    { 
        Figure::side = s; 
    }

    double area() const override 
    {
        return side * side;
    }

    double perimeter() const override 
    {
        return 4 * side;
    }
};

class Rectangle : public Figure {
protected:
    double width;

public:
    Rectangle(double l, double w) 
    {
        Figure::side = l;
        width = w;
    }

    double area() const override 
    {
        return side * width;
    }

    double perimeter() const override 
    {
        return 2 * (side + width);
    }
};

class Triangle : public Figure {
protected:
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3)
    {
        Figure::side = s1;
        side2 = s2;
        side3 = s3;
    }

    double area() const override 
    {
        double s = (side + side2 + side3) / 2;
        return sqrt(s * (s - side) * (s - side2) * (s - side3));
    }

    double perimeter() const override 
    {
        return side + side2 + side3;
    }
};

int main() {
    Square square(5);
    cout << "Площадь квадрата: " << square.area() << endl;
    cout << "Периметр квадрата: " << square.perimeter() << endl;

    Rectangle rectangle(4, 6);
    cout << "Площадь прямоугольника: " << rectangle.area() << endl;
    cout << "Периметр прямоугольника: " << rectangle.perimeter() << endl;

    Triangle triangle(3, 4, 5);
    cout << "Площадь треугольника: " << triangle.area() << endl;
    cout << "Периметр треугольника: " << triangle.perimeter() << endl;
}