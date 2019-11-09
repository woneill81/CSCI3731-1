#ifndef DRUNKENFISH_H
#define DRUNKENFISH_H
#include "fish.h"

class DrunkenFish : public Fish{
	
	public:
		DrunkenFish(double givenX, double givenY, double givenSpeed, Population* pPointer);
		~DrunkenFish();		
		void swim();
	
};
#endif