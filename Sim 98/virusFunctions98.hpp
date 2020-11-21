//
// Created by Luke on 21/11/2020.
//

#ifndef UNI_CPP_VIRUSFUNCTIONS98_HPP
#define UNI_CPP_VIRUSFUNCTIONS98_HPP

#include <iterator>
#include <vector>
#include "person98.hpp"

float RNG();

std::vector<person98> createPopulation(int &healthy, int &infected);

void daycheck(std::vector<person98> &population);

std::pair<int, int> selectRandomPair(std::vector<person98> &population, int &popSize);

void meeting(person98 &A, person98 &B);

std::vector<int> populationReport(std::vector<person98> &population, int &popSize);

int choose(int &popSize);

#endif //UNI_CPP_VIRUSFUNCTIONS98_HPP
