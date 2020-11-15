#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <utility>

#include "include/rollingDice.h"

using namespace std;

/**
 * N iterations of the game craps
 * Example Output
 * 1,13    win : 13 throws
 * 0,7     loss : 7 throws
 */

int main() 
{
  srand(time(NULL));
  const int numGames = 10000;
  int score = 0;
  int point = 0;
  pair <int, int> outcome (0, 0);
  int throwNum = 0;
  ofstream outdata;


  outdata.open("Programme Output/games_of_craps.csv");
  outdata << "outcome,throws" << endl;
  for (int i = 1; i <= numGames; ++i) {
    throwNum = 0;
    score = 0;
    point = -1;

    while (true)
      {
      score = rollTwoDice();
      throwNum += 1;

      // Immediate Win
      if (throwNum == 1 && (score == 7 || score == 11)) 
	{
	  outdata << "1," << throwNum << endl;
	  outcome.first += 1;
	  break;
	}

      // Immediate Loss
      else if (throwNum == 1 && (score == 2 || score == 3 || score == 12)) 
	{
	  outdata << "0," << throwNum << endl;
	  outcome.second += 1;
	  break;
	}

      // Set the point
      else if (throwNum == 1 && (score != 7 || score != 11 || score != 2 || score != 3 || score != 12)) 
	{
	  point = score;
	}

      // 7 Throw Loss
      else if (throwNum > 1 && score == 7) {
	outdata << "0," << throwNum << endl;
	outcome.second += 1;
	break;
      }

      // Point Win
      else if (throwNum > 1 && score == point) 
	{
	  outdata << "1," << throwNum << endl;
	  outcome.first += 1;
	  break;
	}
      }
  }
  cout << "\n\nWins:\t\t\t" << outcome.first << endl;
  cout << "Losses:\t\t\t" << outcome.second << endl;
  cout << "Number of Games:\t" << outcome.first + outcome.second << endl;
  outdata << "1," << outcome.first << endl;
  outdata << "0," << outcome.second << endl;
  cout << "\nProgramme Output/games_of_craps.csv created...\n\n";
  outdata.close();
  return 0;
}

