#include "Header.h"
#include "Matrix.h"
using namespace std;

int main() {
	
	Matrix m(Point(3, 3));
	m.SetCol(1, new double[3] {2, 3, 4});

	cout << m << endl;

	return 0;
}