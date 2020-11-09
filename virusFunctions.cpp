//
// Created by Luke on 04/11/2020.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Person.h"

using namespace std;

float RNG()
{
    return static_cast<float>(rand()) / RAND_MAX;
}

void meet(Person &A, Person &B)
{
    if (A.infected() && !B.infected())
    {
        if (RNG() < B.chanceToInfect())
        {
            B.infect();
        }
    }

    if (!A.infected() && B.infected())
    {
        if (RNG() < A.chanceToInfect())
        {
            A.infect();
        }
    }


}