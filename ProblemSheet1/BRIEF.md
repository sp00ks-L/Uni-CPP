## Problem Sheet 1
#### Question 1. Using Random Numbers
Generate a set of random floats in the interval [0,1] using the rand() function. Write a programme that generates a random sample of a give size N (from the command line) and computes the mean and variance of the sample. Use the programme to empirically show the distribution is uniform

#### Question 2. Simulating Dice Throws
Write a programme that simulates the rolling of two dice. Your programme should consist of:
- A 'rnd' function that returns a uniformly distributed random number beweet 0 and 1 as a double
- A 'dice' function that uses 'rnd' and retuns and int from 1 to 6
- A 'two_dice' function that simulates throwing 2 dice and summing their face values as an int
- A main function that simulates a certain number of trials (num of trials recieved from command line)
  - Keep a tally of the scores in a vector. Print out the score frequency
  
#### Question 3. The Game of Craps
Write a programme that simulates a game of craps. Use functions from part 1 as part of your solution. The game proceeds as follows:
- Two dice are thrown and the sum is calculated
- A score of 2, 3 or 12 immediately loses
- A score of 7 or 11 immediately wins
- Any other score becomes the 'point'
- The player keeps throwing two dice until:
  - The player hits the point value again which wins
  - A 7 is thrown which loses
  
Simulate 10,000 games and keep a tallk of wins and losses as well as the number of throws needed before winning / losing
