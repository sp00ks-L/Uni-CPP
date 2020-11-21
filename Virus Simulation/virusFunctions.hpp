//
// Created by Luke on 18/11/2020.
//

#ifndef UNI_CPP_VIRUSFUNCTIONS_HPP
#define UNI_CPP_VIRUSFUNCTIONS_HPP

#include <iterator>
#include <vector>

#include "person.hpp"

float RNG();

std::vector<Person> createPopulation(int &healthy, int &infected);

void daycheck(std::vector<Person> &population);

std::pair<int, int> selectRandomPair(std::vector<Person> &population, int &popSize);

void meeting(Person &A, Person &B);

std::vector<int> populationReport(std::vector<Person> &population, int &popSize);

#endif //UNI_CPP_VIRUSFUNCTIONS_HPP
