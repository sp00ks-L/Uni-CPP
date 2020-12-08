//
// Created by Luke on 18/11/2020.
//


#ifndef UNI_CPP_VIRUSFUNCTIONS_HPP
#define UNI_CPP_VIRUSFUNCTIONS_HPP

#include <iterator>
#include <vector>

#include "person.hpp"

// Returns a random float in the interval [0, 1]
float RNG();

// Allows dynamic creation of the simulated population as a vector
std::vector<Person> createPopulation(int &healthy, int &infected);

// Completes the daily check to see if an infected person dies or survives
void daycheck(std::vector<Person> &population);

// Selects a suitable pair randomly by index and ensures they are alive and unique
std::pair<int, int> selectRandomPair(std::vector<Person> &population, int &popSize);

// Performs the meeting between the 2 people selected using the 'selectRandomPair' function
void meeting(Person &A, Person &B);

/*
 * Reports on the current 'health' of the population
 * Updates a vector in the form of [numVulnerable, numInfected, numImmune, numDead]
 */
void populationReport(std::vector<Person> &population, std::vector<int> &report, int &popSize);

#endif //UNI_CPP_VIRUSFUNCTIONS_HPP
