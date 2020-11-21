//
// Created by Luke on 18/11/2020.
//

#ifndef UNI_C___PERSON_HPP
#define UNI_C___PERSON_HPP

class Person {
private:
	// 0, 1, 2, 3  :: vulnerable, infected, immune, dead
	enum status { VULNERABLE, INFECTED, IMMUNE, DEAD };
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
	void infect()
	{
		state = INFECTED;
		becomeInfected = 0.0;
		dying = 0.01;
		recovering = 0.12;
	}

	void recover()
	{
		state = IMMUNE;
		becomeInfected = 0.0;
		dying = 0.0;
		recovering = 0.0;
	}

	void die()
	{
		state = DEAD;
		becomeInfected = 0.0;
		dying = 0.0;
		recovering = 0.0;
	}

	bool infected() { return state; }

	bool vulnerable() { return state == VULNERABLE; }

	bool recovered() { return state == IMMUNE; }

	bool isAlive() { return state != DEAD; }

	float chanceToInfect() { return becomeInfected; }

	float chanceToRecover() { return recovering; }

	float chanceToDie() { return dying; }

	int getState() { return state; }

};

#endif //UNI_C___PERSON_HPP
