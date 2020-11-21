//
// Created by Luke on 18/11/2020.
//

#ifndef UNI_C___VIRUSFUNCTIONS_HPP
#define UNI_C___VIRUSFUNCTIONS_HPP

#include <iterator>

#include "Person.hpp"

float RNG();

std::vector<Person> createPopulation(int& healthy, int& infected);

void daycheck(std::vector<Person>& pop);

std::pair<int, int> selectRandomPair(std::vector<Person>& pop, int& popSize);

void meeting(Person& A, Person& B);

std::vector<int> populationReport(std::vector<Person>& pop, int& popSize);

#endif //UNI_C___VIRUSFUNCTIONS_HPP
