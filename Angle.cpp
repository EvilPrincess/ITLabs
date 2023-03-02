#include "Angle.h"

using namespace std;

Angle::Angle()
{
	radians = 0;
	degrees = 0;
}
Angle::Angle(double _value, bool _type)
{
	if (_type == ARAD) {
		radians = _value;
		degrees = _value * 180 / (double)M_PI;
	}
	else {
		degrees = _value;
		radians = _value * M_PI / 180.0;
	}
}
double Angle::GetValue(bool _type)
{
	if (_type == ADEG) return degrees;
	else return radians;
}

ostream& operator << (ostream& os, Angle& _Angle)
{
	cout << _Angle.GetValue(ADEG);
	return os;
}