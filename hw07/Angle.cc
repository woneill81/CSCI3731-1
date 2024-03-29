#include "angle.h"
#include <iostream>
#include <cmath>

Angle:: Angle() {
	this->haveCos = false;
	this->haveSin = false;
	
	this->angle = 0.0;
	
}

Angle::~Angle() {

}

/*
*	checking will make sure everything is between 0 and 360 degrees
*/
const double Angle::checkAngle (double theAngle) const{
	while(theAngle >= 360) theAngle -= 360;
	while(theAngle < 0) theAngle += 360;
	
	return theAngle;
}

//1 argument constructor
Angle:: Angle(double angle) {
	this->haveCos = false;
	this->haveSin = false;
	this->angle = Angle::checkAngle(angle);
	
}

/*
*	getter
*/
double Angle::getAngle() const{
	return this->angle;
}

/*
*	setter
*/
void Angle::setAngle(double inputAngle){
	this->angle = Angle::checkAngle(inputAngle);
	haveSin = false;
	haveCos = false;
}

/*
*	+
*/
Angle Angle::operator+ (const Angle& a) const{
	double newAngle = this->angle + a.angle;
	
	// while(newAngle >= 360) newAngle -= 360;
	// while(newAngle < 0) newAngle += 360;
	
	newAngle = Angle::checkAngle(newAngle);
	
	return Angle(newAngle);
}

/*
*	-
*/
Angle Angle::operator- (const Angle& a) const{
	double newAngle = this->angle - a.angle;

	newAngle = Angle::checkAngle(newAngle);
	
	return Angle(newAngle);
}

/*
*	*
*/
Angle Angle::operator* (const double d) const{
	double newAngle = this->angle * d;
	
	newAngle = Angle::checkAngle(newAngle);
	
	return Angle(newAngle);
}

/*
*	/
*/
Angle Angle::operator/ (const double d) const{
	double newAngle = this->angle;
	if(d == 0) std::cout << " Cannot divided by 0 " <<std::endl;
	else newAngle = this->angle / d;
	
	newAngle = Angle::checkAngle(newAngle);
	
	return Angle(newAngle);
}

/*
*	+=
*/
const Angle& Angle::operator+= (const Angle& a){
	this->haveCos = false;
	this->haveSin = false;
	
	this->angle += a.angle;
	
	this->angle = Angle::checkAngle(this->angle);
	
	return *this;
}

/*
*	/=
*/
const Angle& Angle::operator-= (const Angle& a){
	this->haveCos = false;
	this->haveSin = false;
	
	this->angle -= a.angle;
	
	this->angle = Angle::checkAngle(this->angle);
	
	return *this;
}


/*
*	= for an Angle object
*/
const Angle& Angle::operator= (const Angle& a){
	this->angle = a.angle;
	
	this->angle = Angle::checkAngle(this->angle);
	
	return *this;
}

/*
*	= for a double
*/
const Angle& Angle::operator= (double d){
	this->haveCos = false;
	this->haveSin = false;
	
	d = Angle::checkAngle(d);
	
	this->angle = d;
	
	return *this;
}

/*
*	==
*/
bool Angle::operator==(const Angle& a) const{
	const double newAngle = a.getAngle();
	return this->angle == newAngle;
}

/*
*	getSin
*/
double Angle::getSin() const{
	if(!haveSin){
		this->sine = sin ((this->angle*M_PI)/(180.0));
		haveSin = true;
	}
	
	return this->sine;
}

/*
*	getCos
*/
double Angle::getCos() const{
	if(!haveCos){
		this->cosine = cos ((this->angle*M_PI)/(180.0));
		haveCos = true;
	}
	
	return this->cosine;
}



/*
*	printable
*/
std::ostream& operator<<(std::ostream& out, const Angle& a){
	out << "The angle is " << a.angle;
	return out;
}