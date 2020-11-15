#include "include/randomDouble.h"

/*
 * Functions to roll 2, 6-sided dice and sum the face values
 */

int dice()
{
  return randDouble() * 6 + 1;
}

int rollTwoDice()
{
  int dice1 = dice();
  int dice2 = dice();
  return dice1 + dice2;
}
