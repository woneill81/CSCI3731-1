#include "angle.h"
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "population.h"
#include "fish.h"
#include "drunkenfish.h"
#include "flippyfish.h"

double callDistance(const double x,const double y){
	return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

int main(int argc, char** argv){
	
	Population* popPointer = new Population(8);
	
	Angle a1(30.0);
	Angle t1(10.0);
	Angle a2(30.0);
	Angle t2(10.0);
	Angle a3(30.0);
	Angle t3(10.0);
	Angle a4(30.0);
	Angle t4(10.0);
	
	
	Angle& angle1 = a1;
	Angle& angle2 = t1;
	Angle& angle3 = a2;
	Angle& angle4 = t2;
	Angle& angle5 = a3;
	Angle& angle6 = t3;
	Angle& angle7 = a4;
	Angle& angle8 = t4;
	
	Fish* f1 = new FlippyFish(0.0, 0.0, 2.2, angle1, angle2, popPointer);
	Fish* f2 = new FlippyFish(0.0, 0.0, 3.5, angle3, angle4, popPointer);
	Fish* f3 = new FlippyFish(0.0, 0.0, 1.5, angle5, angle6, popPointer);
	Fish* f4 = new FlippyFish(0.0, 0.0, 1.2, angle7, angle8, popPointer);

	Fish* f5 = new DrunkenFish(0.0, 0.0, 2.2, popPointer);
	Fish* f6 = new DrunkenFish(0.0, 0.0, 3.5, popPointer);
	Fish* f7 = new DrunkenFish(0.0, 0.0, 1.5, popPointer);
	Fish* f8 = new DrunkenFish(0.0, 0.0, 1.2, popPointer);	
	
	std::cout << "Initial Population: " << popPointer->size() << std::endl;
	
	while(popPointer->size() > 0){
		Fish* a = NULL;
		for(int i = 0; i < popPointer->size(); i++){
			a = popPointer->get(i);
			a->swim();
			
			std::cout << a;
			
			FlippyFish* f = dynamic_cast<FlippyFish*>(a);
			
			if(f != NULL)
				std::cout << " FlippyFish" << std::endl;
			else
				std::cout << " DrunkenFish" << std::endl;
			
			if(callDistance(a->getX(), a->getY()) > 100){
				delete a;
				a = NULL;
			}
		}
		
		std::cout << "Fish left:" << popPointer->size() << std::endl;
	}	
	
	delete popPointer;
	popPointer = NULL;
}