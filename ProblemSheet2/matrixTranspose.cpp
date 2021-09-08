//
// Created by Luke on 02/11/2020.
// Matrix Transpose Functions
//

#include <iostream>
#include <iomanip>

template<class T>
void swapr(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

void squareTranspose(double matrix[][3], int size)
{
    for (int a = 1; a < size; a++)
    {
        for (int b = 0; b < a; b++)
        {
            swapr(matrix[a][b], matrix[b][a]);
        }
    }
}

void printm(double matrix[][3], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << std::endl;
        for (int j = 0; j < size; ++j)
        {
            // Nicer formatting for non-negative numbers
            if (matrix[i][j] >= 0.0)
            {
                std::cout << std::setprecision(2) << " " << matrix[i][j] << std::fixed << " ";
                continue;
            }
            std::cout << std::setprecision(2) << matrix[i][j] << std::fixed << " ";
        }
    }
}
