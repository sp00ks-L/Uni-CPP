//
// Created by 229538 on 16/01/2021.
//

#include <iostream>
#include <vector>
#include <fstream>

#include "include/mandelbrotSet.hpp"
#include "include/mandelTransform.hpp"

int main()
{
    // Start and end points for coordinate range
    double xstart = -2.2;
    double xend = 1.0;
    double ystart = -1.2;
    double yend = 1.2;
    std::ofstream fileOut;

    // Create X and Y values
    std::vector<double> X = createSet(xstart, xend);
    std::vector<double> Y = createSet(ystart, yend);


    // Initialise output file
    fileOut.open("output/mandelbrot.txt");

    // Altering the order of this loop changes the orientation
    // Put Y first for horizontal fractal. X first for vertical
    // I used unsigned ints because the -Wall -Wextra and -ggdb tags threw a warning about this comparison
    for (unsigned int i = 0; i <= Y.size(); ++i) {
        for (unsigned int j = 0; j <= X.size(); ++j) {
            // stableSolver returns bool: 1 if point XY stable when N=100 else 0
            if (stableSolver(X[j], Y[i])) {
                fileOut << 'o';
            } else {
                fileOut << '-';
            }
        }
        fileOut << "\n";
    }
    fileOut.close();
    std::cout << "Fractal Generated" << std::endl;
    return 0;
};


