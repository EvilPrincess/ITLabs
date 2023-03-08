#include "Header.h"
#include "Matrix.h"
#include "Vector2.h"

#define TRUE 1

using namespace std;
using namespace SpecialFunctionsForLabs;

int main() {
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");
	system("chcp 1251");

	unsigned int N;
	string line;
	getline(cin, line);

	N = input<unsigned int>();     // твоя реализация ввода натурального целого

	if (N != line.length())
	{
		if (N < line.length())
			line = line.substr(line.length() - N);
		else
		{
			int ls = line.length();
			for (int i = 0; i < N - ls; i++)
				line = '*' + line;
		}
	}

	cout << line << endl;

	return 0;
}