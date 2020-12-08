//
// Created by Luke on 02/12/2020.
//

#ifndef UNI_CPP_SPHERE_HPP
#define UNI_CPP_SPHERE_HPP

const double PI = 3.14159265359;

class Sphere
{
public:
    // Constructor
    Sphere(double d = 0, double rho = 0)
    {
        diameter = d;
        density = rho;
    };
    Sphere() {};
    double GetMass();
    double GetArea();

private:
    double diameter;
    double density;
    double GetVolume();
};

double Sphere::GetArea()
{
    double radius = diameter / 2;
    return 4 * PI * (radius * radius);
}

double Sphere::GetMass()
{
    return GetVolume() * density;
}

double Sphere::GetVolume() {
    double radius = diameter / 2;
    return (4.0 / 3.0) * (PI * (radius * radius * radius));
}
#endif //UNI_CPP_SPHERE_HPP
