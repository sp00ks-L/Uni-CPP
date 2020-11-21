//
// Created by Luke on 18/11/2020.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <random>
#include <utility>

#include "Person.hpp"
#include "virusFunctions.hpp"

using namespace std;


int main()
{
	// Setting up random number generator
	cout << "Simulation Running..." << endl;
	random_device rd;
	mt19937 gen(rd());
	ofstream fileOut;

	int vulnerable = 19900;
	int infected = 100;
//    int vulnerable = 190;
//    int infected = 10;
	int totalPopulation = vulnerable + infected;
	uniform_int_distribution<> dis(0, totalPopulation);
	// Create the population
	vector<Person> population = createPopulation(vulnerable, infected);

	// Initialise output file
	fileOut.open(R"(E:\Sussex Code\Python\CPP Coursework\Week 9\virus_sum.csv)");
	fileOut << "vulnerable,infected,immune,dead" << endl;
	fileOut << vulnerable << "," << infected << "," << 0 << "," << 0 << endl;

	for (int days = 0; days < 365; ++ days)
		{
		// Do the Day check for survival / recovery
		daycheck(population);
		for (int meet = 0; meet < 50000; ++ meet)
			{
			// Meet x times per day
			int ind1 = dis(gen);
			int ind2 = dis(gen);
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