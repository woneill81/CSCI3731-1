#include "Fish.h"
#include <cstdlib>
#include <iostream>
#include "Angle.h"
#include "Population.h"


Fish::Fish(Population* pPointer)
	:	direction(0.0),
		turnRate(0.0){
	this->x = 0.0;
	this->y = 0.0;
	this->speed = 1.0;
	this->p = pPointer;
	pPointer->add(this);
	
} //end of no argument constructor

Fish::Fish(double givenX,double givenY, double givenSpeed,const Angle& givenDir,const Angle& givenTurnRate, Population* pPointer)
	:	direction(givenDir),
		turnRate(givenTurnRate) {
	this->x = givenX;
	this->y = givenY;
	this->speed = givenSpeed;
	this->p = pPointer;
	
	pPointer->add(this);
}

Fish::~Fish() {
	p->remove(this);
}

void Fish::setSpeed(double s){
	this->speed = s;
}

void Fish::swim(){
	int choice = rand() % 3;
	
	if(choice == 0) this->direction -= turnRate;
	else if (choice == 2) this->direction += turnRate;
	
	this->x += this->speed * direction.getCos();
	this->y -= this->speed * direction.getSin();
}

double Fish::getX()const{
	return this->x;
}

double Fish::getY() const{
	return this->y;
}

/*
*	printable
*/
std::ostream& operator<<(std::ostream& out, const Fish* f){
	out << "Fish is at: (" << f->x << "," << f->y << ")";
	return out;
}