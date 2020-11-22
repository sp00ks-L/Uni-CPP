//
// Created by Luke on 21/11/2020.
//

#ifndef UNI_CPP_VIRUSFUNCTIONS98_HPP
#define UNI_CPP_VIRUSFUNCTIONS98_HPP

#include <iterator>
#include <vector>
#include "person98.hpp"

/*
 * Returns a random float in the interval [0, 1]
 */
float RNG();

/*
 * Allows dynamic creation of the simulated population as a vector
 */
std::vector<person98> createPopulation(int &healthy, int &infected);

/*
 * Completes the daily check to see if an infected person dies or survives
 */
void daycheck(std::vector<person98> &population);

/*
 * Selects a suitable pair randomly by index and ensures they are alive and unique
 */
std::pair<int, int> selectRandomPair(std::vector<person98> &population, int &popSize);

/*
 * Performs the meeting between the 2 people selected using the 'selectRandomPair' function
 */
void meeting(person98 &A, person98 &B);

/*
 * Reports on the current 'health' of the population
 * Updates a vector in the form of [numVulnerable, numInfected, numImmune, numDead]
 */
void populationReport(std::vector<person98> &population, std::vector<int> &report, int &popSize);

/*
 * Returns an index to choose a person from the population
 * This is my C++98 alternative to using <random> and mt19937
 */
int choose(int &popSize);

#endif //UNI_CPP_VIRUSFUNCTIONS98_HPP
