//
// Created by 229538 on 16/01/2021.
//
#include <vector>

#include "include/mandelTransform.hpp"

bool stableSolver(double &x, double &y)
{
    int radius = 4;
    // Pre-allocate because we know size
    std::vector<double> xPoints(100);
    std::vector<double> yPoints(100);
    xPoints[0] = x;
    yPoints[0] = y;

    // Iteration limit
    int N = 100;
    int iterations = 0;
    for (int i = 0; i < N; ++i) {
        // Do 100 iterations of XY transform
        if ((xPoints[i] * xPoints[i]) + (yPoints[i] * yPoints[i]) < radius) {
            // If we are within the circle, perform transform
            xPoints[i + 1] = ((xPoints[i] * xPoints[i]) - (yPoints[i] * yPoints[i])) + xPoints[0];
            yPoints[i + 1] = (2 * xPoints[i] * yPoints[i]) + yPoints[0];
            iterations++;
        } else {
            break;
        }
    }
    if (iterations == N) {
        return true;
    } else {
        return false;
    }

}