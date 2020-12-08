//
// Created by Luke on 21/11/2020.
//

#ifndef UNI_CPP_PERSON98_HPP
#define UNI_CPP_PERSON98_HPP

#include "status98.hpp"

class person98
{
private:
    int state;
    float becomeInfected;
    float dying;
    float recovering;
public:
    // Default constructor - vulnerable person
    person98()
    {
        state = VULNERABLE;
        becomeInfected = 0.5;
        dying = 0.0;
        recovering = 0.0;
    }

    // Infected person constructor
    explicit person98(bool infected)
    {
        state = INFECTED;
        becomeInfected = 0.0;
        dying = 0.01;
        recovering = 0.12;
    }

    // Destructor
    virtual ~person98();

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

#endif //UNI_CPP_PERSON98_HPP
