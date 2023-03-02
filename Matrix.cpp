#include "Matrix.h"

Matrix::Matrix()
{
	Generate(Point(1, 1));
}
Matrix::Matrix(Point _size)
{
	Generate(_size);
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
void Matrix::SetElem(Point _pos, double _value)
{
	table[(int)_pos.y][(int)_pos.x] = _value;
}
void Matrix::SetLine(unsigned int _line, double* _values)
{
	for (int _i = 0; _i < size.x; _i++)
	{
		SetElem(Point(_line, _i), _values[_i]);
	}
}
void Matrix::SetCol(unsigned int _col, double* _values)
{
	for (int _i = 0; _i < Size().y; _i++)
	{
		SetElem(Point(_i, _col), _values[_i]);
	}
}
double Matrix::Determinant()
{

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
