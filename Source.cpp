#include "Lib.h"

using namespace SpecialFunctionsForLabs;
using namespace strf;

template <int size>
void fill_random(int* arr, size_t size, int low, int high) {
	for (int i = 0; i < size; i++) {
		*(arr + i) = randint(low, high);
	}
}

template <int size>
int sum(int* arr, size_t size) {
	int s = 0;
	for (int i = 0; i < size; i++) {
		s += *(arr + i);
	}
	return s;
}

int main() {
	setlocale(0, "");
	setlocale(LC_NUMERIC, "C");
	srand(time(NULL));

	size_t n = input<int>("Введите кол-во учащихся: ", true);

	int* A = new int[n] {}; fill_random(A, n, 2, 5);
	int* G = new int[n] {}; fill_random(G, n, 2, 5);
	int* F = new int[n] {}; fill_random(F, n, 2, 5);

	int mids[]{sum(A, n)/n, sum(G, n)/n, sum(F, n)/n};

	cout << "Алгебра: " << *(mids) << endl << "Геометрия: " << *(mids + 1) << endl << "Физика: " << *(mids + 2) << endl << endl;

	return 0;
}