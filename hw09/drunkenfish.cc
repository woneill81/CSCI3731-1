#include "drunkenfish.h"
#include "fish.h"
#include "angle.h"
#include "population.h"
#include <cstdlib>
#include <iostream>

DrunkenFish::DrunkenFish(double givenX, double givenY, double givenSpeed, Population* pPointer)
			: Fish(givenX, givenY, givenSpeed, pPointer){
}				

DrunkenFish::~DrunkenFish(){
}

void DrunkenFish::swim(){
	int num = rand() % 4;
	if( num == 0) x += speed;
	else if(num == 1) y += speed;
	else if(num == 2) x -= speed;
	else y -= speed;
} 
	