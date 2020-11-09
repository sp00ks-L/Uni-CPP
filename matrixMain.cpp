//
// Created by Luke on 02/11/2020.
//

#include <iostream>

#include "matrixTranspose.h"

using namespace std;

int main()
{

    double matrix[3][3] =
    {
            { 0.36, 0.48, -0.8 },
            { -0.8, 0.6, 0.0 },
            { 0.48, 0.64, 0.6 }
    };

    printm(matrix);
    cout << endl;
    transpose(matrix);
    printm(matrix);




    return 0;
}