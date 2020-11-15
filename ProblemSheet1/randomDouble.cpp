#include <cstdlib>

/*
 * Returns a double in the interval [0, 1)
 */

double randDouble()
{
  return static_cast<double>(rand()) / RAND_MAX;
}
