#include "Lib.h"

using namespace strf;
using namespace SpecialFunctionsForLabs;
using namespace arrf;

unsigned int strf::len(string str) 
{
	return (unsigned int)str.length();
}
vector<string> strf::split(string str, char separator) 
{
	
	vector<string> vec = { };

	string substr = "";

	for (unsigned int i = 0; i < len(str); i++) {
		if (str[i] == separator)
			if (substr == "") continue;
			else {
				vec.push_back(substr);
				substr = "";
				continue;
			}
		else if (i == len(str) - 1) {
			substr += str[i];
			vec.push_back(substr);
			continue;
		}
		substr += str[i];
	}

	return vec;
}

float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));

	return y;
}
int randi(int low, int high)
{
	return (low == NULL && high == NULL ? rand()-16383 : low + rand() % (high - low + 1));
}
double randf(double low, double high, int precision) {
	double value = rand() % (int)pow(10, precision);
	return (low==NULL && high == NULL? value / pow(10, precision) + rand() - 16383 : low + (value / pow(10, precision)) * (high - low));
}

bool SpecialFunctionsForLabs::is_int(string str)
{
	char availables[]{'-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	if (count(str.begin(), str.end(), '-') > 0 && str[0] != '-') return false;
	if (count(str.begin(), str.end(), '-') > 1) return false;

	for (char c : str) {
		if (find(begin(availables), end(availables), c) == end(availables)) return false;
	}

	return true;
}
bool SpecialFunctionsForLabs::is_float(string str)
{
	char availables[]{ '-', '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	if (count(str.begin(), str.end(), '-') > 0 && str[0] != '-') return false;
	if (count(str.begin(), str.end(), '-') > 1) return false;

	if (count(str.begin(), str.end(), '.') > 1) return false;
	if (count(str.begin(), str.end(), '.') > 0 && (str[0] == '.' || str[0] == '-' && str[1] == '.' || str.back() == '.')) return false;

	for (char c : str) {
		if (find(begin(availables), end(availables), c) == end(availables)) return false;
	}

	return true;
}
bool SpecialFunctionsForLabs::is_natural(string str)
{
	char availables[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	if (!is_int(str) || stoi(str) < 1) return false;

	return true;
}
double SpecialFunctionsForLabs::round(double value, unsigned int precision)
{
	double k = pow(10, precision);
	return (int)(value * k + 0.5) / k;
}
bool SpecialFunctionsForLabs::is_char(string str)
{
	if (len(str) == 1) return true;
	return false;
}


// Описание методов класса Angle
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


// Описание методов класса Vector2
Vector2 Vector2::ZERO = Vector2();
Vector2 Vector2::RIGHT = Vector2(1, 0);
Vector2 Vector2::UP = Vector2(0, -1);
Vector2 Vector2::LEFT = Vector2(-1, 0);
Vector2 Vector2::DOWN = Vector2(0, 1);
Vector2::Vector2()
{
	x = 0;
	y = 0;
	Invalidate();
	this->Len();
}
Vector2::Vector2(double _x, double _y)
{
	x = _x;
	y = _y;
	Invalidate();
	this->Len();
}
double Vector2::Len()
{
	if (!this->isValid) {
		length = sqrt(x*x + y*y);
		this->Validate();
	}
	return length;
}
void Vector2::Invalidate()
{
	isValid = false;
}
void Vector2::Validate()
{
	isValid = true;
}
Angle Vector2::FindAngle(Vector2 _Left, Vector2 _Right)
{
	return Angle(acos((_Left.x * _Right.x + _Left.y * _Right.y) / (_Left.Len() * _Right.Len())), ARAD);
}
Angle Vector2::FindAngle(Vector2 _Left, Vector2& _Right)
{
	return Angle(acos((_Left.x * _Right.x + _Left.y * _Right.y) / (_Left.Len() * _Right.Len())), ARAD);
}
Angle Vector2::FindAngle(Vector2& _Left, Vector2 _Right)
{
	return Angle(acos((_Left.x * _Right.x + _Left.y * _Right.y) / (_Left.Len() * _Right.Len())), ARAD);
}
Angle Vector2::FindAngle(Vector2& _Left, Vector2& _Right)
{
	return Angle(acos((_Left.x * _Right.x + _Left.y * _Right.y) / (_Left.Len() * _Right.Len())), ARAD);
}


// Описание перегрузок операторов для Vector2
ostream& operator << (ostream& os, Vector2& _Vec)
{
	cout << "(" << _Vec.x << "; " << _Vec.y << ")";
	return os;
}
ostream& operator << (ostream& os, Vector2 _Vec)
{
	cout << "(" << _Vec.x << "; " << _Vec.y << ")";
	return os;
}
Vector2 operator + (Vector2& _Left, Vector2& _Right)
{
	return Vector2(_Left.x + _Right.x, _Left.y + _Right.y);
}
Vector2 operator + (Vector2 _Left, Vector2 _Right)
{
	return Vector2(_Left.x + _Right.x, _Left.y + _Right.y);
}
Vector2& Vector2::operator += (Vector2 _Other)
{
	this->x += _Other.x;
	this->y += _Other.y;
	return *this;
}
Vector2 operator - (Vector2& _Left, Vector2& _Right)
{
	return Vector2(_Left.x - _Right.x, _Left.y - _Right.y);
}
Vector2 operator - (Vector2 _Left, Vector2 _Right)
{
	return Vector2(_Left.x - _Right.x, _Left.y - _Right.y);
}
Vector2& Vector2::operator -= (Vector2& _Other)
{
	this->x -= _Other.x;
	this->y -= _Other.y;
	return *this;
}
double operator * (Vector2& _Left, Vector2& _Right)
{
	return (_Left.x * _Right.x + _Left.y * _Right.y);
}
double operator * (Vector2 _Left, Vector2 _Right)
{
	return (_Left.x * _Right.x + _Left.y * _Right.y);
}
