#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "include/ARG_CHECK.h"
#include "include/rollingDice.h"

using namespace std;

/**
 * Rolls 2 dice n times and sums the face values to create a score distribution
 */

int main(int argc, char *argv[])
{
  
  argChecker(argc);

  srand(time(NULL));
  int n = atoi(argv[1]);
  vector<int> scores(n, 0);

  for (int i = 0; i < n; ++i)
    {
      int score = rollTwoDice();
      scores[i] = score;
    }

  stringstream ss;
  ss << n;
  string str = ss.str();
  string output = "Programme Output/dice_" + str + ".dat";
  ofstream outdata;
  outdata.open(output.c_str());

  outdata << "Score\t" << "Count" << endl;
  cout << "\nScore\t\t" << "Count" << endl;
  for (int i = 2; i < 13; ++i)
    {
      cout << i << "\t\t" << count(scores.begin(), scores.end(), i) << endl;
      outdata << i << "\t\t" << count(scores.begin(), scores.end(), i) << endl;
    }
  outdata.close();
  cout << "\n" << output << " has been created...\n\n";
  return 0;
}
