#include "Angle.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Population.h"
#include "Fish.h"
#include <cmath>

double calDistance(const double x,const double y){
	return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

int main(int argc, char** argv){
	
	Population* pointerToPop = new Population(4);
	
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
	
	Fish* f1 = new Fish(0.0, 0.0, 2.2, angle1, angle2, pointerToPop);
	Fish* f2 = new Fish(0.0, 0.0, 3.5, angle3, angle4, pointerToPop);
	Fish* f3 = new Fish(0.0, 0.0, 1.5, angle5, angle6, pointerToPop);
	Fish* f4 = new Fish(0.0, 0.0, 1.2, angle7, angle8, pointerToPop);	
	
	while(pointerToPop->size() > 0){
		Fish* a = NULL;
		for(int i = 0; i < pointerToPop->size(); i++){
			a = pointerToPop->get(i);
			a->swim();
			
			std::cout << a << std::endl;
			
			if(calDistance(a->getX(), a->getY()) > 100){
				delete a;
				a = NULL;
			}
		}
			
		std::cout << "Fish left: " << pointerToPop->size() << std::endl;
	}
	
	delete pointerToPop;
	pointerToPop = NULL;
}