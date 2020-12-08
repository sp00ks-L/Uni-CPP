//
// Created by Luke on 02/11/2020.
//

#ifndef UNI_CPP_MATRIXTRANSPOSE_H
#define UNI_CPP_MATRIXTRANSPOSE_H

// Template function for swapping 2 variables of the same type
template<class T>
void swapr(T &x, T &y);

// Returns the matrix transpose of a double matrix of size 3
void transpose(double matrix[][3], int size = 3);

// Formats the console output of a matrix
void printm(double matrix[][3], int size = 3);

// Returns the matrix transpose in-place if the matrix is square
void squareTranspose(double matrix[][3], int size = 3);

#endif //UNI_CPP_MATRIXTRANSPOSE_H
