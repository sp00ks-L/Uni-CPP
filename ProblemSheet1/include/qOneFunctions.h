#ifndef qOneFunctions
#define qOneFunctions

/**
 * Functions used in Question 1, Using Random Numbers
 * Generates vector of size n
 * Calculates mean and variance of vector<double>
 * Standardises print to console format
 */

std::vector<double> generateRandom(int &n);
double mean(std::vector<double> &vec);
double variance(std::vector<double> &vec);
void pprint(int &n, double &var);

#endif
