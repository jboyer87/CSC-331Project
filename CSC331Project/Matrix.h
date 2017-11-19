#pragma once
#include <iostream>

class Matrix {
public:
	Matrix();

	Matrix(int columns, int rows);

	virtual ~Matrix();

	Matrix::Matrix(const Matrix& matrix);

	int Matrix::getRows()
	{
		return _rows;
	}

	int Matrix::getColumns()
	{
		return _columns;
	}

	const int Matrix::getElement(int rowPosition, int columnPosition);

	void Matrix::setElement(int rowPosition, int columnPosition, int newValue);

	void Matrix::display();

	Matrix add(Matrix matrix);
	Matrix multiply(Matrix matrix);

	friend std::ostream& operator<<(std::ostream& outputStream, Matrix& matrix);
	friend std::istream& operator>>(std::istream& inputStream, Matrix& matrix);

	Matrix Matrix::operator+(Matrix right);

private:
	int _columns;
	int _rows;

	int* _data;

	void Matrix::initializeMatrixData();
};