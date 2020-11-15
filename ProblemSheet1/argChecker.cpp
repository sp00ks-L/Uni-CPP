#include <iostream>
#include <cstdlib>
#include <cstdio>

/*
 * Function to check if the number of supplied arguments == 1
 * Does not perform type checking
 */

void argChecker(int &argc)
{
  if (argc < 2)
    { 
      printf( "\nYou must enter a command line argument for n - the sample size\n\n");
      exit(0);
    }
  else if (argc > 2)
    {
      printf( "\nYou have entered too many command line arguments (%d). Please enter a single value for n - the sample size\n\n", (argc - 1) );
      exit(0);
    }
}
