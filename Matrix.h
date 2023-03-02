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
	Matrix(int _lines, int _cols);
	Point Size();
	double** GetTable();
	double* GetElem(Point _pos);
	double* GetElem(int _line, int _col);
	void SetElem(Point _pos, double _value);
	void SetLine(unsigned int _line, double* _values);
	void SetCol(unsigned int _col, double* _values);
	double Determinant();

	friend ostream& operator << (ostream& os, Matrix& _Matrix);
	void operator += (Matrix& _Other);
	void operator -= (Matrix& _Other);
};

Matrix operator + (Matrix& _Left, Matrix& _Right);
Matrix operator - (Matrix& _Left, Matrix& _Right);
Matrix operator * (Matrix& _Left, Matrix& _Right);

