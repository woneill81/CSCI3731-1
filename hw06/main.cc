#include <cstdio>
#include <iostream>
#include "Angle.h"
int main(int argc, char** argv) {
    
	Angle angle0(45.0);
	Angle angle1(125.0);
	Angle angle2(60.0);
	Angle angle4(220.0);
	Angle angle5(120.0);
	
	
	//Addition
	Angle angle3=angle1+angle2;
	angle3.toString();
	
	Angle angle6=angle2+angle5;
	angle6.toString();
	
	//Subtraction
	Angle angle7=angle1-angle2;
	angle7.toString();
	
	//Multiplication
	Angle angle8=angle1*4.0;
	angle8.toString();
	
	//Division
	Angle angle9=angle4/3.0;
	angle9.toString();
	
	//+=, -=, *=, /=
	angle0+=angle1;
	angle0.toString();
	
	angle1-=angle2;
	angle1.toString();
	
	angle2*=3;
	angle2.toString();
	
	angle4/=6;
	angle4.toString();
	
	//=
	Angle angle12=angle0;
	angle12.toString();
	
}