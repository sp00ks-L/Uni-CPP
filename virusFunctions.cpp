//
// Created by Luke on 04/11/2020.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <random>
#include "Person.h"

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0, 1);


float RNG() {
//    return static_cast<float>(rand()) / RAND_MAX;
    return ((1.0 - 0.0) * ((float) rand() / RAND_MAX)) + 0.0;
}

float superRNG() { return dis(gen); }

int randomShuffler(int i) { return rand() % i; }

vector<Person> createPopulation(int &healthy, int &infected) {
    vector<Person> population(healthy, Person());
    for (int j = 0; j < infected; ++j) { population.push_back(Person(true)); }
    random_shuffle(population.begin(), population.end(), randomShuffler);
    return population;
}

map<int, Person> createPop(int &healthy, int &infected, int &initialPopCount) {
    map<int, Person> pop;
    for (int i = 0; i < healthy; ++i) { pop.insert({i, Person()}); }
    for (int j = healthy; j < initialPopCount; ++j) { pop.insert( {j, Person()}); }
    return pop;
}

void dayCheck2(map<int, Person> &population) {
    for (auto const& person : population) {
        float roll = superRNG();
        if (roll <= population[person.first].chanceToDie()) {
            population.erase(person.first);
            break;
        }
        else if (roll <= population[person.first].chanceToRecover()) {
            population[person.first].recover();
            break;
        }
    }
}


void meet(Person &A, Person &B) {
    float roll = superRNG();
    if (A.infected() && !B.infected()) {
        if (roll <= B.chanceToInfect()) { B.infect(); }
    }

    if (!A.infected() && B.infected()) {
        if (roll <= A.chanceToInfect()) { A.infect(); }
    }

}

void dayCheck(vector<Person> &population) {
    int n = population.size();
    vector<int> toDie;
    // For every person in the population
    for (int person = 0; person < n; ++person) {
        if (population[person].infected()) {
            float roll = superRNG();
            if (roll <= population[person].chanceToDie()) {
                toDie.push_back(person);
//                population.erase(population.begin() + person);
                continue;
            }
            else if (roll <= population[person].chanceToRecover()) {
                population[person].recover();
                continue;
            }
        }
    }

    for(auto index: toDie) {
        population.erase(population.begin() + index);
    }
}


vector<int> populationHealthMap(map<int, Person> &population, int &initialPopCount) {

    // populationStats [healthy, immune, infected, dead]
    vector<int> populationStats(4, 0);
    populationStats[3] = initialPopCount - population.size();
    for (auto const& person : population) {
        if (!population[person.first].infected()) {
            populationStats[0] += 1;
            break;
        }
        else if (population[person.first].recovered()) {
            populationStats[1] += 1;
            continue;
        }
        else if (population[person.first].infected()) {
            populationStats[2] += 1;
            break;
        }
    }
    return populationStats;
}


vector<int> populationHealth(vector<Person> &population, int &initialPopCount) {

    // populationStats [healthy, immune, infected, dead]
    vector<int> populationStats(4, 0);
    populationStats[3] = initialPopCount - population.size();
    int n = population.size();
    for (int i = 0; i < n; ++i) {
        if (population[i].recovered()) {
            populationStats[1] += 1;
            continue;
        } else if (population[i].infected()) {
            populationStats[2] += 1;
            continue;
        } else if (!population[i].infected()) {
            populationStats[0] += 1;
            continue;
        }
    }
    return populationStats;
}



