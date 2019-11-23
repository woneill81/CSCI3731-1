#include <iostream>
#include <stdlib.h>
#include "fish.h"
#include "angle.h"
#include <vector>

int main(int argc, char** argv) {
	std::vector<Fish*> p;
	
	std::cout << "initial population " << p.size() << std::endl << std::endl;
	srand(time(0));
	
	for(int i = 0; i < 4; ++i){
		Angle<double> angle1(rand() % 360);
		std::cout << "Starting angle for Fish " << (i+1) << ": " << angle1 << std::endl;
		
		Angle<double> angle2(rand() % 90); 
		std::cout << "Turnrate angle for Fish " << (i+1) << ": " << angle2 << std::endl;
		
		std::cout << "~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
		
		new Fish(0.0, 0.0, (1 + (rand() % 10)), angle1, angle2, &p);
	}
	
	while(p.size() > 0){
		Fish* a = NULL;
		for(int i = 0; i < p.size(); i++){
			a = p[i];
			a->swim();
			std::cout << "Fish " << (i+1) << a << std::endl;
			if(a->getStamina() <= 0){
				delete a;
				a = NULL;
			}
		}
		std::cout << "Fish left: " << p.size() << std::endl << std::endl;
	}
}