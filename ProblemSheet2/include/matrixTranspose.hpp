//
// Created by Luke on 02/11/2020.
// Matrix Transpose Header
//

#ifndef MATRIX_TRANSPOSE_HPP
#define MATRIX_TRANSPOSE_HPP

// Template function for swapping 2 variables of the same type
template<class T>
void swapr(T &x, T &y);

// Returns the matrix transpose in-place if the matrix is square
void squareTranspose(double matrix[][3], int size = 3);

// Formats the console output of a matrix
void printm(double matrix[][3], int size = 3);

#endif // MATRIX_TRANSPOSE_HPP
