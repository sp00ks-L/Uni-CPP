//
// Created by Luke on 02/11/2020.
//

#include <iostream>
#include <iomanip>

template<class T>
void swapr(T &x, T &y)
{
    T &tmp = x;
    x = y;
    y = tmp;
}

void transpose(double matrix[][3], int size)
{
    double output[3][3];
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            output[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            swapr(matrix[i][j], output[j][i]);
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
                std::cout << std::setprecision(1) << " " << matrix[i][j] << std::fixed << " ";
                continue;
            }
            std::cout << std::setprecision(1) << matrix[i][j] << std::fixed << " ";
        }
    }
}