//
// Created by Luke on 18/11/2020.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <utility>

#include "person.hpp"
#include "virusFunctions.hpp"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    // Setting up random number generator
    cout << "Simulation Running..." << endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::ofstream fileOut;

    int vulnerable = 19900;
    int infected = 100;
    int totalPopulation = vulnerable + infected;
    std::uniform_int_distribution<> dis(0, totalPopulation);
    // Create the population
    vector<Person> population = createPopulation(vulnerable, infected);

    // Initialise output file
    fileOut.open(R"(E:\Sussex Code\Python\CPP Coursework\Week 9\virus_sim.csv)");
    fileOut << "vulnerable,infected,immune,dead" << endl;
    fileOut << vulnerable << "," << infected << "," << 0 << "," << 0 << endl;

    for (int days = 0; days < 365; ++days)
    {
        daycheck(population);
        for (int meet = 0; meet < 50000; ++meet)
        {
            int ind1 = dis(gen);
            int ind2 = dis(gen);
            std::pair<int, int> pairMeet = selectRandomPair(population, totalPopulation);
            meeting(population[pairMeet.first], population[pairMeet.second]);
        }
        vector<int> report = populationReport(population, totalPopulation);
        fileOut << report[0] << "," << report[1] << "," << report[2] << "," << report[3] << endl;

    }
    cout << "Simulation Completed" << endl;
    fileOut.close();
    return 0;
}