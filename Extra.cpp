#include "Header.h"
#include "Matrix.h"
#include "Vector2.h"
using namespace std;

int main() {

	Matrix m(3, 3);

	m.SetLine(0, new double[3] {1, 2, 3});
	m.SetLine(1, new double[3] {4, 10, 6});
	m.SetLine(2, new double[3] {7, 8, 9});

	cout << m.Determinant() << endl;

	return 0;
}