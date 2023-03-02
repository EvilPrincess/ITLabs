#include "Matrix.h"

Matrix::Matrix()
{
	Generate(Point(1, 1));
}
Matrix::Matrix(Point _size)
{
	Generate(_size);
}
Matrix::Matrix(int _lines, int _cols)
{
	Generate(Point(_cols, _lines));
}
void Matrix::Generate(Point _size)
{
	size.x = _size.x;
	size.y = _size.y;
	table = new double* [_size.x];
	for (int _i = 0; _i < _size.y; _i++)
		table[_i] = new double[_size.x];
	for (int _i = 0; _i < _size.y; _i++) {
		for (int _j = 0; _j < _size.x; _j++)
			table[_i][_j] = 0;
	}
}
Point Matrix::Size()
{
	return size;
}
double** Matrix::GetTable()
{
	return table;
}
double* Matrix::GetElem(Point _pos)
{
	return &table[(int)_pos.y][(int)_pos.x];
}
double* Matrix::GetElem(int _line, int _col)
{
	return &table[_line][_col];
}
void Matrix::SetElem(Point _pos, double _value)
{
	table[(int)_pos.y][(int)_pos.x] = _value;
}
void Matrix::SetLine(unsigned int _line, double* _values)
{
	for (int _i = 0; _i < size.x; _i++)
	{
		SetElem(Point(_i, _line), _values[_i]);
	}
}
void Matrix::SetCol(unsigned int _col, double* _values)
{
	for (int _i = 0; _i < Size().y; _i++)
	{
		SetElem(Point(_col, _i), _values[_i]);
	}
}
double Matrix::Determinant()
{
	if (this->size.x != this->size.y) {
		cout << "Чёт размер не подходит" << endl;
		return NULL;
	}
	if (this->size == Point(1, 1)) return *GetElem(0, 0);
	if (this->size == Point(2, 2)) return *GetElem(0, 0) * *GetElem(1, 1) - *GetElem(0, 1) * *GetElem(1, 0);

	double dt = 0;
	for (int block = 0; block < size.x; block++) {
		Matrix new_matrix(size.x - 1, size.x - 1);
		for (int y = 1; y < size.y; y++) {
			bool flag = false;
			for (int x = 0; x < size.x; x++) {
				if (x == block) { flag = true; continue; }
				new_matrix.SetElem(Point((flag ? x - 1 : x), y-1), *GetElem(y, x));
			}
		}
		dt += (block % 2 != 0 ? -1 : 1) * *GetElem(0, block) * new_matrix.Determinant();
	}
	return dt;
}
ostream& operator << (ostream& os, Matrix& _Matrix)
{
	for (int _line = 0; _line < _Matrix.Size().y; _line++)
	{
		cout << "( ";
		for (int _col = 0; _col < _Matrix.Size().x; _col++)
			cout << *_Matrix.GetElem(Point(_col, _line)) << (_col == _Matrix.Size().x - 1 ? " " : "\t");
		cout << ")\n";
	}
	return os;
}
