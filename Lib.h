#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// ������� ��� �����
namespace strf {
	vector<string> split(string str, char separator = ' ');
	unsigned int len(string str);
}

// ����������� ����������� ������ ������������� ������� ��� ������������ ����� :3
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
				cout << "������ �����! ��������� ����: ";
				cin >> input;
			}
			return stoi(input);
		}
		else if (is_same<T, float>::value) {
			while (!is_float(input)) {
				cout << "������ �����! ��������� ����: ";
				cin >> input;
			}
			return stof(input);  // ��� setlocale(LC_NUMERIC, "C")
		}
		else if (is_same<T, char>::value) {
			while (!is_char(input)) {
				cout << "������ �����! ��������� ����: ";
				cin >> input;
			}
			return input[0];
		}

		return NULL;
	}
}

// ������ ������ �������� ��� ������ �������� ���������� 1 / sqrt(x)
float Q_rsqrt(float number);

