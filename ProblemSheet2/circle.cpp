//
// Created by Luke Jones  on 02/11//2020
//

#include <iostream>

#include "include/Circle.hpp"

using std::cout;
using std::endl;

int main()
{
    Circle A(3.0, 2.0, 1.0);
    Circle B(4.0, 5.0, 6.0);
    Circle C = A + B;
    cout << "Circle A" << endl;
    cout << A << endl;
    cout << "Circle B" << endl;
    cout << B << endl;
    cout << "Circle C" << endl;
    cout << C << endl;

    // Bool Radius Test
    if (C > A) { cout << "Circle C is bigger than Circle A\n" << endl; }


    // Equal Boolean Expression
    bool equalAB = !(A > B) && !(B > A);
    // Copy Constructor
    Circle D(A);
    bool equalAD = !(A > D) && !(D > A);
    if (equalAD) { cout << "Circles A and D are equal" << endl; }

    return 0;
}
