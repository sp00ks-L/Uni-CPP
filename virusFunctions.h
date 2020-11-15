//
// Created by Luke on 04/11/2020.
//

#ifndef UNI_C___VIRUSFUNCTIONS_H
#define UNI_C___VIRUSFUNCTIONS_H

#include <vector>
#include <map>
#include "Person.h"

using namespace std;

float RNG();

int randomShuffler(int i);

vector<Person> createPopulation(int &healthy, int &infected);

void meet(Person &A, Person &B);

void dayCheck(vector<Person> &population);

vector<int> populationHealth(vector<Person> &population, int &initialPopCount);

map<int, Person> createPop(int &healthy, int &infected, int &initialPopCount);

void dayCheck2(map<int, Person> &population);

vector<int> populationHealthMap(map<int, Person> &population, int &initialPopCount);


#endif //UNI_C___VIRUSFUNCTIONS_H
