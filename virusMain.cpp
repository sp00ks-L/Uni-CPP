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
    srand(time(NULL));
    Person A;
    Person B(true);

    return 0;
}