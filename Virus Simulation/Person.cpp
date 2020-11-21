//
// Created by Luke on 21/11/2020.
//

#include "Person.hpp"

void Person::infect()
{
    state = INFECTED;
    becomeInfected = 0.0;
    dying = 0.01;
    recovering = 0.12;
}

void Person::recover()
{
    state = IMMUNE;
    becomeInfected = 0.0;
    dying = 0.0;
    recovering = 0.0;
}

void Person::die()
{
    state = DEAD;
    becomeInfected = 0.0;
    dying = 0.0;
    recovering = 0.0;
}

bool Person::infected() { return state == INFECTED; }
bool Person::isAlive() { return state != DEAD; }
float Person::chanceToInfect() { return becomeInfected; }
float Person::chanceToRecover() { return recovering; }
float Person::chanceToDie() { return dying; }
int Person::getState() { return state; }