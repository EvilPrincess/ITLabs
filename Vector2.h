#pragma once

#include "Angle.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <random>
using namespace std;

class Vector2
{
private:
	bool isValid;

	void Invalidate();
	void Validate();
public:
	double x, y;
	double length;

	// Конструктор без значений
	Vector2();

	// Конструктор со значениями
	Vector2(double _x, double _y);

	// Вычисление длины
	double Len();

	// Векторное умножение
	static Vector2 MultiplyVector(const Vector2& _Left, const Vector2& _Right, const Angle& _Angle);

	// Угол между векторами
	static Angle FindAngle(const Vector2& _Left, const Vector2& _Right);

	// Очень много перегрузок операторов
	friend ostream& operator << (ostream& os, const Vector2& _Vec);
	friend ostream& operator << (ostream& os, const Vector2 _Vec);
	Vector2& operator += (const Vector2 _Other);
	Vector2& operator -= (const Vector2& _Other);
	void operator = (const Vector2& _Other);

	// Готовые направления
	static Vector2 ZERO;
	static Vector2 RIGHT;
	static Vector2 UP;
	static Vector2 LEFT;
	static Vector2 DOWN;
};

Vector2 operator + (const Vector2& _Left, const Vector2& _Right);
Vector2 operator - (const Vector2& _Left, const Vector2& _Right);
double operator * (const Vector2& _Left, const Vector2& _Right);	// это будет скалярное произведение

