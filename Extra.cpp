#include "Header.h"
#include "Matrix.h"
#include "Vector2.h"
using namespace std;

int main() {

	cout << Vector2::FindAngle(Vector2::RIGHT, Vector2(2, 2)).GetValue(ADEG) << endl;

	return 0;
}