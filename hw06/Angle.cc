#include "Angle.h"
#include <cstdio>
#include <iostream>
//Constructor
Angle::Angle(double x){
	this->x=x;	
}
//Destructor
Angle::~Angle() {    
    //printf("destructing %lf\n", x);
}
//Get methods
double Angle::getX() const {    
    return x;    
} 
//Setter
void Angle::set(double x) {    
    this->x = x;
}
//Operator overloaders: +, -, *, /
Angle Angle::operator+(const Angle& angle) const{	
	double a=x+angle.getX();
	while(a>=360) a-=360;
	while(a<0) a+=360;	
	return Angle(a);
}
Angle Angle::operator-(const Angle& angle) const{
	double a=x-angle.getX();
	while(a>=360) a-=360;
	while(a<0) a+=360;	
	return Angle(a);
}
Angle Angle::operator*(const double angle) const{	
	double a=x*angle;
	while(a>=360) a-=360;
	while(a<0) a+=360;	
	return Angle(a);
}
Angle Angle::operator/(const double angle) const{	
	double a=x/angle;
	while(a>=360) a-=360;
	while(a<0) a+=360;	
	return Angle(a);
}
//Operator overloaders +=, -=, *=, /=
const Angle& Angle::operator+=(const Angle& a){
	this->x+=a.x;	
	while(this->x>=360) this->x-=360;
	while(this->x<0) this->x+=360;	
	return *this;
}
const Angle& Angle::operator-=(const Angle& a){
	this->x-=a.x;	
	while(this->x>=360) this->x-=360;
	while(this->x<0) this->x+=360;
	return *this;
}
const Angle& Angle::operator*=(const Angle& a){
	this->x*=a.x;	
	while(this->x>=360) this->x-=360;
	while(this->x<0) this->x+=360;	
	return *this;
}
const Angle& Angle::operator/=(const Angle& a){
	this->x/=a.x;	
	while(this->x>=360) this->x-=360;
	while(this->x<0) this->x+=360;	
	return *this;
}
//Operator overloader: =, ==
const Angle& Angle::operator=(const Angle& a){
	this->x=a.x;	
	while(this->x>=360) this->x-=360;
	while(this->x<0) this->x+=360;	
	return *this;
}
bool Angle::operator==(const Angle& a)const{	
	return this->x==a.x;
}

void Angle:: toString() const{
		std::cout <<"The angle is: "<< this->x <<std::endl;
}