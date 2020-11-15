#include <cstdlib>
#include <cstdio>
#include <numeric>
#include <vector>

#include "include/randomDouble.h"

/*
 * Function to generate a vector of doubles with size n
 * Functions to calculate mean and variance of vector<double>
 * Function to standardise console output
 */

std::vector<double> generateRandom(int &n)
{
  std::vector<double> randVec(n);
  for (int i = 0; i < n; ++i)
    {
      randVec[i] = randDouble();
    }

  return randVec;
}

double mean(std::vector<double> &vec)
{
  return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}

double variance(std::vector<double> &vec)
{
  int n = vec.size();
  double var = 0.0;
  double average = mean(vec);
    for (int i = 0; i < n; ++i)
      {
	var += (vec[i] - average) * (vec[i] - average);
      }
  var /= (n - 1);
  return var;
}



void pprint(int &n, double &var)
{
  printf("\nSample Size: %d\n", n);
  printf("Variance: %.5f\n----------------------", var);
}
