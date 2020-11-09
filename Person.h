//
// Created by Luke on 04/11/2020.
//

#ifndef UNI_C___PERSON_H
#define UNI_C___PERSON_H

class Person
{
private:
    bool isInfected;
    bool hasRecovered;
    float becomeInfected;   // 50%
    float dying;            // 1%
    float recovering;       // 12%
public:
    // Default constructor - healthy person
    Person() { isInfected = false; hasRecovered = false; becomeInfected = 0.5; dying = 0.0; recovering = 0.0; }
    // Infected person constructor
    Person( bool infected )
    {
        isInfected=infected;
        hasRecovered = false;
        becomeInfected = 0.0;
        dying = 0.01;
        recovering = 0.12;
    }

    // Functions
    void infect() { isInfected = true; becomeInfected = 0.0; dying = 0.01; recovering = 0.12; }
    void recover() { isInfected = false; becomeInfected = 0.0; dying = 0.0; recovering = 0.0; }
    bool infected() { return isInfected; }
    float chanceToInfect() { return becomeInfected; }

};


#endif //UNI_C___PERSON2_H
