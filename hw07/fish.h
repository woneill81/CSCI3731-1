#ifndef FISH_H
#define FISH_H
#include "Angle.h"
#include <cstdlib>

class Population;

class Fish {
	
private:
	double x;
	double y;
	double speed;
	//A direction in which it is swimming, specified by an Angle
	Angle direction;
	//In each time, the direction will change by this Angle
	Angle turnRate;
	Population* p;

public:
	Fish(Population* pPointer);
	Fish(double givenX,double givenY, double givenSpeed,const Angle& givenDir,const Angle& givenTurnRate, Population* pPointer);
	virtual ~Fish();
	void swim();
	void setSpeed(double s);
	
	//getters
	double getX() const;
	double getY() const;
	
	//printable
	friend std::ostream& operator<<(std::ostream& out, const Fish* f);


};

#endif