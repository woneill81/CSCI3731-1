#include "fish.h"
#include <cstdlib>
#include <iostream>
#include "angle.h"
#include "population.h"

//no arg constructor
Fish::Fish(Population* pPointer){
	this->x = 0.0;
	this->y = 0.0;
	this->speed = 1.0;
	this->p = pPointer;
	pPointer->add(this);
	
}

Fish::Fish(double givenX,double givenY, double givenSpeed, Population* pPointer){
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

double Fish::getX()const{
	return this->x;
}

double Fish::getY() const{
	return this->y;
}

std::ostream& operator<<(std::ostream& out, const Fish* f){
	out << "Fish is at: (" << f->x << "," << f->y << ")";
	return out;
}