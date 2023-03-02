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


// Random
int randi(int low=NULL, int high=NULL);	// Возвращает случайное число между low и high включительно
double randf(double low=NULL, double high=NULL, int precision=2); // Возвращает случайное число между low и high с точностью precision


// Функции для строк
namespace strf {
	vector<string> split(string str, char separator = ' ');
	unsigned int len(string str);
}

// Функции для массивов
namespace arrf {
	template <typename T>
	void print(T* arr, size_t size) {
		cout << "[  ";
		for (unsigned int i = 0; i < size; i++) {
			cout << *(arr + i) << (i != size - 1? "  " : "");
		}
		cout << "\t]\n";
	}
	
	template <typename T>
	void fill_random(T* arr, size_t size, int low=NULL, int high=NULL) {
		if (is_same<T, int>::value)
			for (int i = 0; i < size; i++) {
				*(arr + i) = randi(low, high);
			}
		else
			for (int i = 0; i < size; i++) {
				*(arr + i) = randf(low, high);
			}
	}

	template <typename T>
	int sum(T* arr, size_t size) {
		int s = 0;
		for (int i = 0; i < size; i++) {
			s += *(arr + i);
		}
		return s;
	}
}

// Специальные невероятные лучшие гениальнейшие функции для лабораторных работ :3
namespace SpecialFunctionsForLabs {
	bool is_int(string str);
	bool is_float(string str);
	bool is_char(string str);
	bool is_natural(string str);

	template<typename T>
	T input(string message = "", bool natural = 0)
	{
		cout << message;
		string input;
		cin >> input;

		if (is_same<T, int>::value) {
			while ((natural && !is_natural(input)) || !is_int(input)) {
				cout << "Ошибка ввода! Повторите ввод: ";
				cin >> input;
			}
			cin.ignore(1);
			return stoi(input);
		}
		else if (is_same<T, float>::value) {
			while (!is_float(input)) {
				cout << "Ошибка ввода! Повторите ввод: ";
				cin >> input;
			}
			cin.ignore(1);
			return stof(input);  // для setlocale(LC_NUMERIC, "C")
		}
		else if (is_same<T, char>::value) {
			while (!is_char(input)) {
				cout << "Ошибка ввода! Повторите ввод: ";
				cin >> input;
			}
			cin.ignore(1);
			return input[0];
		}

		return NULL;
	}

	double round(double value, unsigned int precision);
}

// Просто крутой алгоритм для крайне быстрого вычисления 1 / sqrt(x)
float Q_rsqrt(float number);


// Класс матрицы???
class Matrix
{
private:
	double** table;
	Vector2 size;
public:
	Matrix();
	Matrix(Vector2 _size);
	void generate(Vector2 _size);
	Vector2 Size();
	double** GetTable();
	double* GetElem(Vector2 _pos);
	void SetElem(Vector2 _pos, double _value);
	void SetLine(unsigned int _line, double* _values);
	void SetCol(unsigned int _col, double* _values);
	double Determinant();

	friend ostream& operator << (ostream& os, Matrix& _Matrix);
	friend ostream& operator << (ostream& os, Matrix _Matrix);
	void operator += (Matrix& _Other);
	void operator += (Matrix _Other);
	void operator -= (Matrix& _Other);
	void operator -= (Matrix _Other);
};

//	Класс угла..?
class Angle
{
private:
	double radians, degrees;
public:
	
	// Конструктор
	Angle();

	// Конструктор со значением (если type == ARAD, то считается, что значение задается в радианах, если ADEG - наоборот)
	Angle(double _value, bool _type = ADEG);

	// Получение значения
	double GetValue(bool _type = ADEG);

	// Очень много перегрузок операторов
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

// Класс вектора2
class Vector2
{
private:
	double length;
	bool isValid;

	void Invalidate();
	void Validate();
public:
	double x, y;

	// Конструктор без значений
	Vector2();

	// Конструктор со значениями
	Vector2(double _x, double _y);

	// Вычисление длины
	double Len();

	// Векторное умножение
	static Vector2 MultiplyVector(Vector2 _Left, Vector2 _Right, Angle _Angle);
	static Vector2 MultiplyVector(Vector2 _Left, Vector2 _Right, Angle& _Angle);
	static Vector2 MultiplyVector(Vector2 _Left, Vector2& _Right, Angle _Angle);
	static Vector2 MultiplyVector(Vector2 _Left, Vector2& _Right, Angle& _Angle);
	static Vector2 MultiplyVector(Vector2& _Left, Vector2 _Right, Angle _Angle);
	static Vector2 MultiplyVector(Vector2& _Left, Vector2 _Right, Angle& _Angle);
	static Vector2 MultiplyVector(Vector2& _Left, Vector2& _Right, Angle _Angle);
	static Vector2 MultiplyVector(Vector2& _Left, Vector2& _Right, Angle& _Angle);

	// Угол между векторами
	static Angle FindAngle(Vector2 _Left, Vector2 _Right);
	static Angle FindAngle(Vector2 _Left, Vector2& _Right);
	static Angle FindAngle(Vector2& _Left, Vector2 _Right);
	static Angle FindAngle(Vector2& _Left, Vector2& _Right);

	// Очень много перегрузок операторов
	friend ostream& operator << (ostream& os, Vector2& _Vec);
	friend ostream& operator << (ostream& os, Vector2 _Vec);
	friend istream& operator >> (istream& is, Vector2& _Vec);
	Vector2& operator += (Vector2 _Other);
	Vector2& operator -= (Vector2& _Other);

	/* Все бинарные операторы объявлены вне класса и описаны в файле Lib.cpp */

	// Готовые направления
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
double operator * (Vector2& _Left, Vector2& _Right);	// это будет скалярное произведение
double operator * (Vector2 _Left, Vector2 _Right);		// это будет скалярное произведение


// Класс вектора3
class Vector3
{

};

