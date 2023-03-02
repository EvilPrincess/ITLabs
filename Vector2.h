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
	double length;
	bool isValid;

	void Invalidate();
	void Validate();
public:
	double x, y;

	// ����������� ��� ��������
	Vector2();

	// ����������� �� ����������
	Vector2(double _x, double _y);

	// ���������� �����
	double Len();

	// ��������� ���������
	static Vector2 MultiplyVector(Vector2 _Left, Vector2 _Right, Angle _Angle);
	static Vector2 MultiplyVector(Vector2 _Left, Vector2 _Right, Angle& _Angle);
	static Vector2 MultiplyVector(Vector2 _Left, Vector2& _Right, Angle _Angle);
	static Vector2 MultiplyVector(Vector2 _Left, Vector2& _Right, Angle& _Angle);
	static Vector2 MultiplyVector(Vector2& _Left, Vector2 _Right, Angle _Angle);
	static Vector2 MultiplyVector(Vector2& _Left, Vector2 _Right, Angle& _Angle);
	static Vector2 MultiplyVector(Vector2& _Left, Vector2& _Right, Angle _Angle);
	static Vector2 MultiplyVector(Vector2& _Left, Vector2& _Right, Angle& _Angle);

	// ���� ����� ���������
	static Angle FindAngle(Vector2 _Left, Vector2 _Right);
	static Angle FindAngle(Vector2 _Left, Vector2& _Right);
	static Angle FindAngle(Vector2& _Left, Vector2 _Right);
	static Angle FindAngle(Vector2& _Left, Vector2& _Right);

	// ����� ����� ���������� ����������
	friend ostream& operator << (ostream& os, const Vector2& _Vec);
	friend ostream& operator << (ostream& os, Vector2 _Vec);
	friend istream& operator >> (istream& is, Vector2& _Vec);
	Vector2& operator += (Vector2 _Other);
	Vector2& operator -= (Vector2& _Other);
	void operator = (Vector2& _Other);

	/* ��� �������� ��������� ��������� ��� ������ � ������� � ����� Lib.cpp */

	// ������� �����������
	static Vector2 ZERO;
	static Vector2 RIGHT;
	static Vector2 UP;
	static Vector2 LEFT;
	static Vector2 DOWN;
};

Vector2 operator + (Vector2& _Left, Vector2& _Right);
Vector2 operator + (Vector2 _Left, Vector2 _Right);
Vector2 operator - (Vector2& _Left, Vector2& _Right);
Vector2 operator - (Vector2 _Left, Vector2 _Right);
double operator * (Vector2& _Left, Vector2& _Right);	// ��� ����� ��������� ������������
double operator * (Vector2 _Left, Vector2 _Right);		// ��� ����� ��������� ������������

