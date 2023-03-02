#pragma once

#define _USE_MATH_DEFINES

#define ARAD 0
#define ADEG 1

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <random>
using namespace std;


class Angle
{
private:
	double radians, degrees;
public:

	// �����������
	Angle();

	// ����������� �� ��������� (���� type == ARAD, �� ���������, ��� �������� �������� � ��������, ���� ADEG - ��������)
	Angle(double _value, bool _type = ADEG);

	// ��������� ��������
	double GetValue(bool _type = ADEG);

	// ����� ����� ���������� ����������
	friend ostream& operator << (ostream& os, Angle& _Angle);
	friend istream& operator >> (istream& is, Angle& _Angle);
	Angle operator + (Angle& _Other);
	Angle operator + (double _deg);
	Angle operator - (Angle& _Other);
	Angle operator - (double _deg);
	void operator += (Angle& _Other);
	void operator += (double _deg);
	void operator -= (Angle& _Other);
	void operator -= (double _deg);
};

