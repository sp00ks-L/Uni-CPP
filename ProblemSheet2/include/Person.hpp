//
// Created by Luke on 18/11/2020.
//

#ifndef PERSON_HPP
#define PERSON_HPP

#include "status.hpp"

class Person
{
private:
    // 0, 1, 2, 3  <=> vulnerable, infected, immune, dead
    int state;
    float becomeInfected;
    float dying;
    float recovering;
public:
    // Default constructor - vulnerable person
    Person()
    {
        state = VULNERABLE;
        becomeInfected = 0.5;
        dying = 0.0;
        recovering = 0.0;
    }

    // Infected person constructor
    explicit Person(bool infected)
    {
        state = INFECTED;
        becomeInfected = 0.0;
        dying = 0.01;
        recovering = 0.12;
    }

    // Destructor
    virtual ~Person() = default;

    // Functions
    void infect();

    void recover();

    void die();

    bool infected();

    bool isAlive();

    float chanceToInfect();

    float chanceToRecover();

    float chanceToDie();

    int getState();

};

#endif //PERSON_HPP
