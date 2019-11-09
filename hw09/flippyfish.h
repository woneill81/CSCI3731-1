#ifndef FLIPPYFISH_H
#define FLIPPYFISH_H
#include "fish.h"

class FlippyFish : public Fish {

private: 
	Angle direction;
	Angle turnRate;

public:
	FlippyFish(double givenX, double givenY, double givenSpeed, const Angle& givenDir, const Angle& givenTurnRate, Population* pPointer);	
	~FlippyFish();
	void swim();
};

#endif