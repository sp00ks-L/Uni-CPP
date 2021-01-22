//
// Created by 229538 on 16/01/2021.
//

#include <vector>
#include <cmath>

#include "include/mandelbrotSet.hpp"

std::vector<double> createSet(double &start, double &end)
{
    // This spacing var controls how detailed the fractal will be
    // Smaller = Higher granularity (default = 0.02)
    double spacing = 0.02;
    double vectorSize = (fabs(start) + end) / spacing;
    std::vector<double> output(vectorSize);
    double current_val = start;
    for (unsigned long i = 0; i <= output.size(); ++i) {
        output[i] = current_val;
        current_val += spacing;
    }

    return output;
}

