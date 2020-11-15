#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

#include "include/ARG_CHECK.h"
#include "include/qOneFunctions.h"

using namespace std;

/**
 * Generates a vector of random doubles between 0 - 1 of size n
 * and calculates the samples mean and variance
 */

int main(int argc, char *argv[])
{

  argChecker(argc);

  srand(time(NULL));
  int n = atoi(argv[1]);
  vector<double> sample = generateRandom(n);
  double average = mean(sample);
  double var = variance(sample);
  printf("\nSample Size: %d", n);
  printf("\nMean: %.5f", average);
  printf("\nVariance: %.5f\n\n", var);


  /** 
   * Show distribution by calculating variance for increase n
   * if the data has a uniform distribution, it should converge
   * toward 1/12 ~ 0.08333
   */

  printf("Target Variance: 1 / 12 = %.5f\n", 1.0 / 12.0);
  int ns[6] = { 10, 100, 1000, 10000, 100000, 1000000 };
  for (int i = 0; i < 6; ++i)
    {
      vector<double> local_sample = generateRandom(ns[i]);
      double local_var = variance(local_sample);
      pprint(ns[i], local_var);
    }

  return 0;
}
