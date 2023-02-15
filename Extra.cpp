#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int lmain() {
	srand(time(NULL));
	string sss;
	int n;
	char av[] = { '-','0','1','2','3','4','5','6','7','8','9' };
	cout << "Vvedite kolichestvo elementov massiva: " << endl;
	while (true) {
		cin >> sss;
		bool isINT = true;

		for (int i = 0; i < sss.length(); i++) {

			bool isFound = false;
			for (int j = 0; j < 11; j++) {
				if (sss[i] == av[j]) {
					isFound = true;
					break;
				}
			}

			if (isFound) continue;
			else {
				isINT = false;
				break;
			}
		}
		if (isINT) {
			n = stoi(sss);
			break;
		}

}

int* jk = new int[n];
for (int i = 0; i < n; i++)
{
	*(jk + i) = (rand() % 177) - 77;
}
cout << "Generated array: " << endl;
*(jk + 1) = 0;
for (int i = 0; i < n; i++)
{
	cout << * (jk + i) << endl;
}
int summa = 0;
for (int i = n - 1; i >= 0; i--)
{
	if (*(jk + i) == 0) break;
	{
		summa += *(jk + i);
	}
}
cout << "Poluchennaya summa = " << summa << endl;
return 0;
}