//
// Created by Luke on 02/12/2020.
//

#ifndef UNI_CPP_CYLINDER_HPP
#define UNI_CPP_CYLINDER_HPP

class Cylinder
{
public:
    // Constructor
    Cylinder(double d = 0, double h = 0, double rho = 0)
    {
        diameter = d;
        height = h;
        density = rho;
    };
    Cylinder() {};
    double GetMass();
    double GetArea();
private:
    double diameter;
    double height;
    double density;
    double GetVolume();
};

double Cylinder::GetArea()
{
    double radius = diameter / 2;
    return (2 * PI * radius * height) + (2 * PI * (radius * radius));
}

double Cylinder::GetMass()
{
    return GetVolume() * density;
}

double Cylinder::GetVolume()
{
    double radius = diameter / 2;
    return PI * (radius * radius) * height;
}

#endif //UNI_CPP_CYLINDER_HPP
