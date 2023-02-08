#include "Lib.h"


//#define SHOW_ARRAYS 1


using namespace SpecialFunctionsForLabs;
using namespace strf;
using namespace arrf;


int main() {
	setlocale(0, "");
	setlocale(LC_NUMERIC, "C");
	srand(time(NULL));

	cout << "|| Лабораторная работа №1 (сем. 2)\t||\n|| Вариант №20\t\t\t\t||\n|| Группа: ВПР12\t\t\t||\n|| Студент: Фомин Н. А.\t\t\t||\n\n";
	cout << "| Задача №1 |\n\n";

	//                                              ЗАДАЧА №1

	bool SHOW_ARRAYS = 0;  // если потребуется выводить все значения массивов
	typedef float MT;  // MarkType - если потребуется изменить тип значений самих оценок
	unsigned int precision = 2;  // знаков после запятой в вычислениях

	size_t n = input<int>("Введите кол-во учащихся: ", true);

	cout << endl;

	MT* A = new MT[n] {}; fill_random<MT>(A, n, 2, 5);
	MT* G = new MT[n] {}; fill_random<MT>(G, n, 2, 5);
	MT* F = new MT[n] {}; fill_random<MT>(F, n, 2, 5);


	double average[]{ 
		(double)sum<MT>(A, n)/(double)n, 
		(double)sum<MT>(G, n)/(double)n, 
		(double)sum<MT>(F, n)/(double)n
	};

	cout << "Алгебра: " << round(*(average), precision); if (SHOW_ARRAYS) { cout << "\t:\t"; arrf::print<MT>(A, n); } else cout << endl;
	cout << "Геометрия: " << round(*(average+1), precision); if (SHOW_ARRAYS) { cout << "\t:\t"; arrf::print<MT>(G, n); } else cout << endl;
	cout << "Физика: " << round(*(average+2), precision); if (SHOW_ARRAYS) { cout << "\t:\t"; arrf::print<MT>(F, n); } else cout << endl;

	cout << endl << "Лучшая успеваемость - по " << (average == max_element(average, average + 3) ? "алгебре" : average + 1 == max_element(average, average + 3) ? "геометрии" : "физике") << "  (" << round(*max_element(average, average + 3), precision) << ")\n\n\n\n\n\n\n";


	cout << "| Задача №2 |\n\n";

	//                                              ЗАДАЧА №2

	typedef float MT1;  // при случайных значениях типа float вероятость получить 0 крайне маленькая, так что может таки int?

	n = input<int>("Введите размер массива: ", true);

	MT1* O = new MT1[n]; fill_random<MT1>(O, n);

	unsigned int counter = 0;
	for (int i = 0; i < n; i++) {
		if (*(O + i) == 0) counter++;
	}

	cout << "\nНулей в массиве:  " << counter << "\n\n\n\n\n\n\n\n\n\n\n";

	return 0;
}