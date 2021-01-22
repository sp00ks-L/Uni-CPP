//
// Created by 229538 on 16/01/2021.
//

#ifndef UNI_CPP_MANDELTRANSFORM_HPP
#define UNI_CPP_MANDELTRANSFORM_HPP

/*
 * Given 2 coordinates, returns whether the point is a stable mandelbrot solution
 * That is, does it remain within a circle with radius 2 where x^2 + y^2 < r^2 is satisfied
 */
bool stableSolver(double &x, double &y);

#endif //UNI_CPP_MANDELTRANSFORM_HPP
