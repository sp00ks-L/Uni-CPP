//
// Created by Luke on 21/11/2020.
//

//
// Created by Luke on 18/11/2020.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstdlib>

#include "person98.hpp"
#include "virusFunctions98.hpp"

using namespace std;

int main()
{
    // Setting up random number generator
    cout << "Simulation Running..." << endl;
    srand(time(NULL));
    ofstream fileOut;

    int vulnerable = 19900;
    int infected = 100;
    int totalPopulation = vulnerable + infected;
    // Create the population
    vector<person98> population = createPopulation(vulnerable, infected);

    // Initialise output file
    fileOut.open("E:\\Sussex Code\\Python\\CPP Coursework\\Week 9\\virus_sim.txt");
    fileOut << "vulnerable,infected,immune,dead" << endl;
    fileOut << vulnerable << "," << infected << "," << 0 << "," << 0 << endl;

    for (int days = 0; days < 365; ++days)
        {
        // Do the Day check for survival / recovery
        daycheck(population);
        for (int meet = 0; meet < 50000; ++meet)
            {
            // Meet x times per day
            int ind1 = choose(totalPopulation);
            int ind2 = choose(totalPopulation);
            pair<int, int> pairMeet = selectRandomPair(population, totalPopulation);
            meeting(population[pairMeet.first], population[pairMeet.second]);
            }
        vector<int> report = populationReport(population, totalPopulation);
        fileOut << report[0] << "," << report[1] << "," << report[2] << "," << report[3] << endl;

        }
    cout << "Simulation Completed" << endl;
    fileOut.close();
    return 0;
}