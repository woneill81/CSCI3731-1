#include "flippyfish.h"
#include "fish.h"
#include "angle.h"
#include "population.h"
#include <cstdlib>
#include <iostream>

FlippyFish::FlippyFish(double givenX,double givenY, double givenSpeed,const Angle& givenDir,const Angle& givenTurnRate, Population* pPointer)
			:	Fish(givenX, givenY, givenSpeed, pPointer),
				direction(givenDir),
				turnRate(givenTurnRate){
}

FlippyFish::~FlippyFish(){
}

void FlippyFish::swim(){
	int num = rand()%3;
	
	if(num==0) this->direction -= turnRate;
	else if(num==2) this->direction += turnRate;
	
	this->x += speed * direction.getCos();
	this->y += speed * direction.getSin();
}