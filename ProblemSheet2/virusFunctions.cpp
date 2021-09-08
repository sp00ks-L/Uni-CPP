//
// Created by Luke on 18/11/2020.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <utility>

#include "include/virusFunctions.hpp"
#include "include/status.hpp"

using std::vector;
using std::pair;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(0, 1);

float RNG()
{
    return dis(gen);
}

vector<Person> createPopulation(int &vulnerable, int &infected)
{
    vector<Person> population(vulnerable, Person());
    for (int person = 0; person < infected; ++person)
    {
        population.emplace_back(Person(true));
    }
    random_shuffle(population.begin(), population.end());
    return population;
}

void daycheck(vector<Person> &population)
{
    for (auto &person : population)
    {
        if (person.infected())
        {
            float roll = RNG();
            if (roll <= person.chanceToDie())
            {
                person.die();
                continue;
            }
            else if (roll <= person.chanceToRecover())
            {
                person.recover();
                continue;
            }
        }
    }
}

pair<int, int> selectRandomPair(vector<Person> &population, int &popSize)
{
    std::uniform_real_distribution<> select(0, popSize);
    int index1 = select(gen);
    int index2 = select(gen);
    // If person is dead
    while (!population[index1].isAlive()) { index1 = select(gen); }
    while (!population[index2].isAlive() && index2 == index1) { index2 = select(gen); }
    return pair<int, int>{index1, index2};

}

void meeting(Person &A, Person &B)
{
    float roll = RNG();
    if (A.infected() && !B.infected())
    {
        if (roll <= B.chanceToInfect()) { B.infect(); }
    }
    else if (!A.infected() && B.infected())
    {
        if (roll <= A.chanceToInfect()) { A.infect(); }
    }
}

void populationReport(vector<Person> &population, vector<int> &report, int &popSize)
{
    // Effectively clears the vector for re-counting
    report.assign(4, 0);
    for (auto &person : population)
    {
        switch (person.getState())
        {
        case VULNERABLE: report[0]++;
            break;
        case INFECTED: report[1]++;
            break;
        case IMMUNE: report[2]++;
            break;
        case DEAD: report[3]++;
            break;
        }
    }
}
