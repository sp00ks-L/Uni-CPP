//
// Created by Luke on 02/11/2020.
//

#include <iostream>

#include "circle.hpp"

using std::cout;
using std::endl;

int main()
{
    Circle A(3.0, 2.0, 1.0);
    Circle B(4.0, 5.0, 6.0);
    Circle C = A + B;
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
    bool equal = !(A > B) && !(B > A);
    // Using copy constructor
    Circle D(A);
    bool equal2 = !(A > D) && !(D > A);
    cout << equal << endl;
    cout << equal2 << endl;

    return 0;
}
