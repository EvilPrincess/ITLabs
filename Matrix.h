#pragma once

#include "Point.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <random>
using namespace std;

class Matrix
{
private:
	double** table;
	Point size;

	void Generate(Point _size);
public:
	Matrix();
	Matrix(Point _size);
	Point Size();
	double** GetTable();
	double* GetElem(Point _pos);
	void SetElem(Point _pos, double _value);
	void SetLine(unsigned int _line, double* _values);
	void SetCol(unsigned int _col, double* _values);
	double Determinant();

	friend ostream& operator << (ostream& os, Matrix& _Matrix);
	void operator += (Matrix& _Other);
	void operator += (Matrix _Other);
	void operator -= (Matrix& _Other);
	void operator -= (Matrix _Other);
};

