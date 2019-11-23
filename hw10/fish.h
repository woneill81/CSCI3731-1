#ifndef FISH_H
#define FISH_H
#include "angle.h"
#include <cstdlib>
#include <vector>

class Fish {
	
private:
	double x;
	double y;
	double speed;
	//Each fish will have 100 stamina
	double stamina;
	//A direction in which it is swimming, specified by an Angle
	Angle<double> direction;
	//In each time, the direction will change by this Angle
	Angle<double> turnRate;
	std::vector<Fish*>* p;
	
public:
	Fish(double givenX,double givenY, double givenSpeed
		,const Angle<double>& givenDir, const Angle<double>& givenTurnRate, std::vector<Fish*>* pPointer);
	virtual ~Fish();
	/*each swim will consume stamina based on its speed
	*when a fish runs out of stamina it will die
	*however, each swim, a fish will be fed a random portion of food
	*	which recover its stamina based on the amount of portion
	*Each swim the fish will have random speed
	*/
	void swim();
	void setSpeed(double s);
	//getters
	double getStamina() const;
	double getX() const;
	double getY() const;
	//printable
	friend std::ostream& operator<<(std::ostream& out, const Fish* f);
};
#endif