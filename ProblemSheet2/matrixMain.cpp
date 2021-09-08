//
// Created by Luke on 02/11/2020.
// Matrix Transpose Main
//

#include <iostream>

#include "include/matrixTranspose.hpp"

using std::cout;
using std::endl;

int main()
{

    double matrix[3][3] =
            {
                    {0.36, 0.48, -0.8},
                    {-0.8, 0.6, 0.0},
                    {0.48, 0.64, 0.6}
            };

    cout << "\nOriginal Matrix";
    printm(matrix);
    cout << endl;
    cout << "\nMatrix.T";
    squareTranspose(matrix);
    printm(matrix);
    cout << endl;
    return 0;
}
