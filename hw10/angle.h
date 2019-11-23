#ifndef ANGLE_H
#define ANGLE_H
#include <iostream>
#include <cmath>

template<class T> class Angle {

private:
	T angle;
	mutable T sine;
	mutable bool haveSin;
	mutable T cosine;
	mutable bool haveCos;
	
public:
	//checking for between 0-360
	const T checkAngle (T theAngle) const{
		while(theAngle >= 360) theAngle -= 360;
		while(theAngle < 0) theAngle += 360;
		return theAngle;
	}
	//Constructor
	Angle(T angle){
		this->haveCos = false;
		this->haveSin = false;
		this->angle = checkAngle(angle);
	}
	//Destructor
	virtual ~Angle(){}
	const Angle& operator+= (const Angle& a){
		this->haveCos = false;
		this->haveSin = false;
	
		this->angle += a.angle;
	
		this->angle = checkAngle(this->angle);
	
		return *this;
	}
	const Angle& operator-= (const Angle& a){
		this->haveCos = false;
		this->haveSin = false;
	
		this->angle -= a.angle;
	
		this->angle = checkAngle(this->angle);
	
		return *this;
	}
	//direction
	double getSin() const{
		if(!haveSin){
			this->sine = sin ((this->angle*M_PI)/(180.0));
			haveSin = true;
		}
	
		return this->sine;
	}
	double getCos() const{
		if(!haveCos){
			this->cosine = cos ((this->angle*M_PI)/(180.0));
			haveCos = true;
		}
	
		return this->cosine;
	}
	//printable
	friend std::ostream& operator<<(std::ostream& out, const Angle& a){
		out << a.angle;
		return out;
	}
}; //End of class
#endif