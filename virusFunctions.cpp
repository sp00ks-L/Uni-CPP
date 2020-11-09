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
    float roll = RNG();
    if (A.infected() && !B.infected())
    {

        if (roll < B.chanceToInfect()) { B.infect(); }
        if (roll < A.chanceToRecover()) { A.recover(); }

    }

    if (!A.infected() && B.infected())
    {
        if (roll < A.chanceToInfect()) { A.infect(); }
        if (roll < B.chanceToRecover()) { B.recover(); }

    }

    if (A.infected() && B.infected()) {}


}

