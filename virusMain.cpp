//
// Created by Luke on 04/11/2020.
//

#include <iostream>
#include <cstdlib>
#include "Person.h"
#include "virusFunctions.h"

using namespace std;

int main()
{
    // Check if srand is a suitable level of randomness for this number of events
    // 50k * 365 = 18.25 million
    srand((int)time(0));
    Person population[200];
    for (int i = 0; i < 190; ++i)
    {
        population[i] = Person();
    }
    for (int i = 190; i < 201; ++i)
    {
        population[i] = Person(true);
    }

    for (int meetings = 0; meetings < 50000; ++meetings)
    {
        int person1 = (rand() % 200) + 1;
        int person2 = (rand() % 200) + 1;

        meet(population[person1], population[person2]);
    }
    int inf_num = 0;
    int rec_num = 0;
    for (int i = 0; i < 201; ++i)
    {
        if (population[i].infected()) { inf_num += 1; }
        if (population[i].recovered()) { rec_num += 1; }
    }
    cout << inf_num << endl;
    cout << rec_num << endl;

    return 0;
}