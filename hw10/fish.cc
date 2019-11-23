#include "fish.h"
#include <cstdlib>
#include <iostream>
#include "angle.h"
#include <vector>

Fish::Fish(double givenX,double givenY, double givenSpeed,const Angle<double>& givenDir,const Angle<double>& givenTurnRate, std::vector<Fish*>* pPointer)
	:	direction(givenDir),
		turnRate(givenTurnRate) {
	this->x = givenX;
	this->y = givenY;
	this->speed = givenSpeed;
	this->stamina = 100;
	this->p = pPointer;
	pPointer->push_back(this);
}
Fish::~Fish() {
	for(int i = 0; i < p->size(); ++i){
		if ((*p)[i] == this){
			p->erase(p->begin() + i);
			std::cout << "This fish ran out of stamina." << std::endl;
			break;
		}
	}
}
void Fish::setSpeed(double s){
	this->speed = s;
}
void Fish::swim(){
	this->stamina -= this->speed;
	if(this->stamina > 0){
		int choice = rand() % 3;
		int eat = rand() % 5;
	
		this->stamina += eat;
	
		if(choice == 0) this->direction -= turnRate;
		else if (choice == 2) this->direction += turnRate;
	
		this->x += this->speed * direction.getCos();
		this->y -= this->speed * direction.getSin();
	
		this->speed = (rand() % 10) + ((rand() % 10)*0.1);
	}
}
double Fish::getStamina()const{
	return this->stamina;
}
double Fish::getX()const{
	return this->x;
}
double Fish::getY() const{
	return this->y;
}

std::ostream& operator<<(std::ostream& out, const Fish* f){
	out << " is at (" << f->x << "," << f->y << ")";
	return out;
}