#include "Vector2.h"

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
		length = sqrt(x * x + y * y);
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
ostream& operator << (ostream& os, const Vector2& _Vec)
{
	cout << "(" << _Vec.x << "; " << _Vec.y << ")";
	return os;
}
ostream& operator << (ostream& os, Vector2 _Vec)
{
	cout << "(" << _Vec.x << "; " << _Vec.y << ")";
	return os;
}
Vector2 operator + (const Vector2& _Left, const Vector2& _Right)
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
void Vector2::operator = (Vector2& _Other)
{
	this->x = _Other.x;
	this->y = _Other.y;
	this->Invalidate();
}
