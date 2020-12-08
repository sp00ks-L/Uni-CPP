//
// Created by Luke on 02/12/2020.
//

#ifndef UNI_CPP_CUBE_HPP
#define UNI_CPP_CUBE_HPP

class Cube
{
public:
    // Constructor
    Cube(double l = 0, double rho = 0)
    {
        length = l;
        density = rho;
    };
    Cube() {};
    double GetMass();
    double GetArea();
private:
    double length;
    double density;
    double GetVolume();
};

double Cube::GetArea()
{
    return 6 * (length * length);
}

double Cube::GetMass()
{
    return GetVolume() * density;
}

double Cube::GetVolume()
{
    return (length * length * length);
}

#endif //UNI_CPP_CUBE_HPP
