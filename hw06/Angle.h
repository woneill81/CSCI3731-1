#ifndef ANGLE_H
#define ANGLE_H

class Angle {

private:
    double x;
	
public:
    Angle(double x);
    virtual ~Angle();
	
	double getX() const;
	
	void set(double x);
    
	Angle operator+(const Angle& angle) const;
	
	Angle operator-(const Angle& angle) const;
	
	Angle operator*(const double angle) const;
	
	Angle operator/(const double angle) const;
	
	const Angle& operator+=(const Angle& a);
	
	const Angle& operator-=(const Angle& a);
	
	const Angle& operator*=(const Angle& a);
	
	const Angle& operator/=(const Angle& a);
	
	const Angle& operator=(const Angle& a);
	
	bool operator==(const Angle& a)const;
	
	void toString() const;
	
}; //end of Angle class

#endif