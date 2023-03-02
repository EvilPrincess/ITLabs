#include "Header.h"
#include "Matrix.h"
#include "Vector2.h"
using namespace std;

int main() {

	Matrix m(4, 4);

	m.SetLine(0, new double[4] {1, 2, 3, 8});
	m.SetLine(1, new double[4] {4, 10, 6, 4});
	m.SetLine(2, new double[4] {7, 8, 9, 1});
	m.SetLine(2, new double[4] {4, 5, 1, 0});

	cout << m.Determinant() << endl;

	return 0;
}