#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <random>
using namespace std;

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
			return stoi(input);
		}
		else if (is_same<T, float>::value) {
			while (!is_float(input)) {
				cout << "Ошибка ввода! Повторите ввод: ";
				cin >> input;
			}
			return stof(input);  // для setlocale(LC_NUMERIC, "C")
		}
		else if (is_same<T, char>::value) {
			while (!is_char(input)) {
				cout << "Ошибка ввода! Повторите ввод: ";
				cin >> input;
			}
			return input[0];
		}

		return NULL;
	}
}

// Просто крутой алгоритм для крайне быстрого вычисления 1 / sqrt(x)
float Q_rsqrt(float number);

// Random
int randint(int low, int high);	// Возвращает случайное число между low и high включительно
double randf(double low, double high, int precision); // Возвращает случайное число между low и high с точностью precision

