#include <vector>
#include <memory>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>
#include <cmath>
using namespace std;

class Figure
{
public:
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

class Triangle:public Figure
{
public:
    Triangle(int sideOne, int sideTwo, int sideThree)
    :SIDEONE(sideOne), SIDETWO(sideTwo), SIDETHREE(sideThree)
    {}

    string Name() override
    {
        return "TRIANGLE";
    }

    double Perimeter() override
    {
        return static_cast<double>(SIDEONE+SIDETWO+SIDETHREE);
    }

    double Area() override
    {
        double HalfPerimeter = Perimeter()/2.0;
        return sqrt(
                HalfPerimeter*
                (HalfPerimeter - static_cast<double>(SIDEONE))*
                (HalfPerimeter - static_cast<double>(SIDETWO))*
                (HalfPerimeter - static_cast<double>(SIDETHREE))
                );
    }

private:
    int SIDEONE;
    int SIDETWO;
    int SIDETHREE;
};

class Rect:public Figure
{
public:
    Rect(int sideOne, int sideTwo)
            :SIDEONE(sideOne), SIDETWO(sideTwo)
    {}

    string Name() override
    {
        return "RECT";
    }

    double Perimeter() override
    {
        return static_cast<double>(2*SIDEONE + 2*SIDETWO);
    }

    double Area() override
    {
        return static_cast<double>(SIDEONE*SIDETWO);
    }

private:
    int SIDEONE;
    int SIDETWO;
};

class Circle:public Figure
{
public:
    Circle(int radius):RADIUS(radius)
    {}

    string Name() override
    {
        return "CIRCLE";
    }

    double Perimeter() override
    {
        return 2.0*3.14*static_cast<double>(RADIUS);
    }

    double Area() override
    {
        return 3.14*static_cast<double>(RADIUS)*static_cast<double>(RADIUS);
    }

private:
    int RADIUS;
};

shared_ptr<Figure> CreateFigure(istream& input_stream)
{
    string type;
    input_stream >> type;
    if (type == "RECT")
    {
        int width, height;
        input_stream >> width >> height;
        return make_shared<Rect>(width, height);
    }
    else if (type == "TRIANGLE")
    {
        int side_one, side_two, side_three;
        input_stream >> side_one >> side_two >> side_three;
        return make_shared<Triangle>(side_one, side_two, side_three);
    }
    else
    {
        int radius;
        input_stream >> radius;
        return make_shared<Circle>(radius);
    }
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}