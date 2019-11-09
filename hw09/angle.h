#ifndef ANGLE_H
#define ANGLE_H
#include <iostream>
#include <cmath>

class Angle {

private:
	double angle;
	mutable double sine;
	mutable bool haveSin;
	mutable double cosine;
	mutable bool haveCos;
	
public:
	Angle();
	Angle(double angle);
	~Angle();
	
	//checking for between 0-360
	const double checkAngle (const double theAngle) const;
	//setter
	void setAngle(double inputAngle);
	//getter
	double getAngle() const;
	//Overloaded Operators
	//+
	Angle operator+ (const Angle& a) const;
	//-
	Angle operator- (const Angle& a) const;
	//+=
	const Angle& operator+= (const Angle& a);
	//-=
	const Angle& operator-= (const Angle& a);
	//*
	Angle operator* (const double d) const;
	// /
	Angle operator/ (const double d) const;
	//*=
	const Angle& operator*= (const double d);
	// /=
	const Angle& operator/= (const double d);
	//=
	const Angle& operator= (const Angle& a);
	const Angle& operator= (double d);
	//==
	bool operator==(const Angle& a) const;
	
	//direction
	double getSin() const;
	double getCos() const;
	
	//printable
	friend std::ostream& operator<<(std::ostream& out, const Angle& a);
	
}; //End of class

#endif