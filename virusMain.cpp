//
// Created by Luke on 04/11/2020.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <random>
#include "Person.h"
#include "virusFunctions.h"

using namespace std;

/*
 * TODO
 * Think about encoding state into integers 0, 1, 2, 3 (healthy, infected, immune, dead)
 * Think about how to 'exclude' dead if we keep them in the population
 */

int main() {
    // Check if srand is a suitable level of randomness for this number of events
    // 50k * 365 = 18.25 million
//    srand(time(NULL));
    random_device rd;
    mt19937 gen(rd());
    ofstream fileOut;


    int healthy = 199900;
    int infected = 100;
    int popCount = healthy + infected;
    uniform_int_distribution<> dis(0, popCount);
    vector<Person> population = createPopulation(healthy, infected);

    // to plot in python
    fileOut.open("E:\\Sussex Code\\Python\\CPP Coursework\\Week 9\\virus_sum.csv");
//    fileOut.open("E:\\GitHub\\Uni-CPP\\progOut\\virus_sum.csv");

    // CSV Col Headers and prepping file with init conditions
    fileOut << "healthy,immune,infected,dead" << endl;
    fileOut << healthy << "," << 0 << "," << infected << "," << 0 << endl;
    for (int days = 0; days < 100; ++days) {
        cout << "Entered day " << days << endl;
        // Do the day checking for recovery / death
//        dayCheck(population);
        cout << "Checked day " << days << endl;
        // Do the 50,000 meetings per day
        for (int meetings = 0; meetings < 50000; ++meetings) {
            int person1 = (rand() % popCount) + 1;
            int person2 = (rand() % popCount) + 1;
            meet(population[dis(gen)], population[dis(gen)]);
        }
        cout << "Performed all meetings" << endl;
//        vector<int> currentPopulation = populationHealth(population, popCount);
//        fileOut << currentPopulation[0] << "," << currentPopulation[1] << "," << currentPopulation[2] << ","
//                << currentPopulation[3] << endl;
//        cout << days << endl;
    }
//    fileOut.close();
    return 0;
}