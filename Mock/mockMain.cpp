//
// Created by Luke on 02/12/2020.
//


#include <iostream>

#include "sphere.hpp"
#include "cube.hpp"
#include "cylinder.hpp"
#include "cone.hpp"
#include "surfaceMassRatio.hpp"

using std::cout;
using std::endl;

const int length = 2;
const float density = 7.874;

int main()
{
    Sphere A = Sphere(length, density);
    Cube B = Cube(length, density);
    Cylinder C = Cylinder(length, length, density);
    Cone D = Cone(length, length, density);

    cout << "Sphere:\t\t" << surfaceMassRatio(A.GetArea(), A.GetMass()) << endl;
    cout << "Cube:\t\t" << surfaceMassRatio(B.GetArea(), B.GetMass()) << endl;
    cout << "Cylinder:\t" << surfaceMassRatio(C.GetArea(), C.GetMass()) << endl;
    cout << "Cone:\t\t" << surfaceMassRatio(D.GetArea(), D.GetMass()) << endl;

    return 0;
}