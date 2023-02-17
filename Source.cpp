#include "Lib.h"


using namespace SpecialFunctionsForLabs;
using namespace strf;
using namespace arrf;


int main() {
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");
	srand(time(NULL));

	cout << "|| Лабораторная работа №1 (сем. 2)\t||\n|| Вариант №20\t\t\t\t||\n|| Группа: ВПР12\t\t\t||\n|| Студент: Фомин Н. А.\t\t\t||\n\n";


	//                                              ЗАДАЧА №1
	//cout << "| Задача №1 |\n\n";

	//cout << "Для начала найдем граничные коды заданных областей:" << endl;
	//cout << "a-z: " << (int)'a' << " -- " << (int)'z' << endl;
	//cout << "а-я: " << (int)'а' << " -- " << (int)'я' << endl;
	//cout << "А-Я: " << (int)'А' << " -- " << (int)'Я' << endl << endl;

	//cout << "Введите строку: ";
	//string str;	getline(cin, str);
	//cout << "\n\n";
	//
	//// счетчик символов
	//unsigned int counter = 0;

	//for (int c : str)
	//	if ((97 <= c && c <= 122) || (-96 <= c && c <= -17) || (-128 <= c && c <= -97))
	//		counter++;

	//cout << "Количество символов по условию задачи: " << counter << "\n\n\n";

	//                                              ЗАДАЧА №2
	cout << "| Задача №1 |\n\n";
	
	int lines = input<int>("Введите кол-во строк текста: ", true);
	string text, line;

	cout << "Введите текст из (" << lines << ") строк:\n\n";
	for (int i = 0; i < lines; i++) {
		getline(cin, line);
		text += line + "\n";
	}
	cout << text;

	char separator = input<char>("Введите символ для удаления: ");

	// удаление символа(ов) из текста
	for (int i = text.size()-1; i > -1; i--) {
		if (text[i] == separator) {
			text.erase(i, 1);
		}
	}

	cout << "Сжатый текст:\n\n" << text << "\n\n\n";

	return 0;
}