//
// Created by Luke on 21/11/2020.
//

#include "person98.hpp"

void person98::infect()
{
    state = INFECTED;
    becomeInfected = 0.0;
    dying = 0.01;
    recovering = 0.12;
}

void person98::recover()
{
    state = IMMUNE;
    becomeInfected = 0.0;
    dying = 0.0;
    recovering = 0.0;
}

void person98::die()
{
    state = DEAD;
    becomeInfected = 0.0;
    dying = 0.0;
    recovering = 0.0;
}

bool person98::infected() { return state == INFECTED; }
bool person98::isAlive() { return state != DEAD; }
float person98::chanceToInfect() { return becomeInfected; }
float person98::chanceToRecover() { return recovering; }
float person98::chanceToDie() { return dying; }
int person98::getState() { return state; }
person98::~person98()
{

}
