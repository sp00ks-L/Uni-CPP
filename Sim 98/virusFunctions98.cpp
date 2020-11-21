//
// Created by Luke on 21/11/2020.
//


#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

#include "virusFunctions98.hpp"

using namespace std;

float RNG()
{
    return static_cast<float>(rand()) / RAND_MAX ;
}

vector<person98> createPopulation(int &vulnerable, int &infected)
{
    vector<person98> population(vulnerable, person98());
    for (int person = 0; person < infected; ++person)
        {
        population.push_back(person98(true));
        }
    random_shuffle(population.begin(), population.end());
    return population;
}

void daycheck(vector<person98> &population)
{
    for (vector<person98>::iterator person = population.begin(); person != population.end(); ++person)
        {
        if (person->infected())
            {
            float roll = RNG();
            if (roll <= person->chanceToDie())
                {
                person->die();
                continue;
                }
            else if (roll <= person->chanceToRecover())
                {
                person->recover();
                continue;
                }
            }
        }
}

int choose(int &popSize)
{
    return roundf(RNG() * popSize);
}

pair<int, int> selectRandomPair(vector<person98> &population, int &popSize)
{
    int index1 = choose(popSize);
    int index2 = choose(popSize);
    // If person is dead
    while (!population[index1].isAlive())
        { index1 = choose(popSize); }
    while (!population[index2].isAlive() && index2 == index1)
        { index2 = choose(popSize); }
    return pair<int, int>(index1, index2);

}

void meeting(person98 &A, person98 &B)
{
    float roll = RNG();
    if (A.infected() && !B.infected())
        {
        if (roll <= B.chanceToInfect())
            { B.infect(); }
        }
    else if (!A.infected() && B.infected())
        {
        if (roll <= A.chanceToInfect())
            { A.infect(); }
        }
}

vector<int> populationReport(vector<person98> &population, int &popSize)
{
    enum status
    {
        VULNERABLE, INFECTED, IMMUNE, DEAD
    };
    vector<int> report(4, 0);
    // vulnerable, infected, immune, dead
    for (vector<person98>::iterator person = population.begin(); person != population.end(); ++person)
        {
        switch (person->getState())
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
    return report;
}
