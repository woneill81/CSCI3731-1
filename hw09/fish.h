#ifndef FISH_H
#define FISH_H
#include "angle.h"
#include <cstdlib>

class Population;

class Fish {
	
private:
	Population* p;
	
protected:
	double x;
	double y;
	double speed;

public:
	Fish(Population* pPointer);
	Fish(double givenX,double givenY, double givenSpeed, Population* pPointer);
	virtual ~Fish();
	virtual void swim() = 0;
	void setSpeed(double s);
	
	//getters
	double getX() const;
	double getY() const;
	
	//printable
	friend std::ostream& operator<<(std::ostream& out, const Fish* f);


};

#endif