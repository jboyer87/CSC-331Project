#pragma once
#include <iostream>

class Matrix {
public:
	Matrix();

	Matrix(int columns, int rows);

	virtual ~Matrix();

	const int Matrix::getElement(int rowPosition, int columnPosition);

	void Matrix::setElement(int rowPosition, int columnPosition, int newValue);

	void Matrix::display();

	Matrix add(Matrix matrix);
	Matrix multiply(Matrix matrix);

	friend std::ostream& operator<<(std::ostream& outputStream, Matrix matrix);

private:
	int _columns;
	int _rows;

	int* _data;

	void Matrix::initializeMatrixData();
};