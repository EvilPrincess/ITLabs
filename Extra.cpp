#include <iostream>
#include <ctime>
using namespace std;

int lmain() {
	srand(time(NULL));
	int n = 0;
	int i;
	cout << "Vvedite kolichestvo elementov massiva: " << endl;
	cin >> n;

	int* jk = new int[n];
	for (int i = 0; i < n; i++)
	{
		jk[i] = (rand() % 177) - 77;
	}
	cout << "Generated array: " << endl;
	*(jk + 1) = 0;
	for (int i = 0; i < n; i++)
	{
		cout << jk[i] << endl;
	}
	int summa = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (*(jk + i) == 0) break;
		summa += *(jk + i);

	}
	cout << "Poluchennaya summa = " << summa << endl;
	return 0;
}