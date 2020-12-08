//
// Created by Luke on 02/12/2020.
//

#ifndef UNI_CPP_CONE_HPP
#define UNI_CPP_CONE_HPP

#include <cmath>

class Cone
{
public:
    // Constructor
    Cone(double d = 0, double h = 0, double rho = 0)
    {
        diameter = d;
        height = h;
        density = rho;
    };
    Cone() {};
    double GetMass();
    double GetArea();
private:
    double diameter;
    double height;
    double density;
    double GetVolume();
};

double Cone::GetArea()
{
    double radius = diameter / 2;
    return (PI * radius) * (radius + (pow(pow(height, 2) + pow(radius, 2), 0.5)));
}

double Cone::GetMass()
{
    return GetVolume() * density;
}

double Cone::GetVolume()
{
    double radius = diameter / 2;
    return PI * (radius * radius) * (height / 3.0);
}

#endif //UNI_CPP_CONE_HPP
