#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <exception>

// Default constructor - Initializes row and column variables to 3 and 3. Initializes the
// matrix elements to random numbers between 1 and 10.
Matrix::Matrix() : _rows(3), _columns(3)
{
	_data = new int[_rows * _columns];

	this->initializeMatrixData();
}

// Constructor with parameters, also initializes the matrix elements to random numbers.
Matrix::Matrix(int columns, int rows)
{
	_rows = rows;
	_columns = columns;
	_data = new int[columns * rows];

	this->initializeMatrixData();
};

// Destructor that deletes the array data correctly.
Matrix::~Matrix()
{
	delete[] _data;
};

Matrix::Matrix(const Matrix& matrix) 
{
	_rows = matrix._rows;
	_columns = matrix._columns;
	_data = matrix._data;
}

// Function to initialize the matrix data with random integers between 0 and 10.
void Matrix::initializeMatrixData()
{
	const int matrixSize = _rows * _columns;

	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			_data[i * _columns + j] = std::rand() % 10 + 1;
		}
	}
};

// Returns element value for a given row/column.
const int Matrix::getElement(int rowPosition, int columnPosition)
{
	if (rowPosition > _rows || columnPosition > _columns)
	{
		throw std::out_of_range("The row and column position entered is out of range.");
	}

	int position = rowPosition * _columns + columnPosition;
	int data = _data[position];
	return data;
}

// Sets the element at the given row/column position to the new value
void Matrix::setElement(int rowPosition, int columnPosition, int newValue)
{
	if (rowPosition > _rows || columnPosition > _columns)
	{
		throw std::out_of_range("The row and column position entered is out of range.");
	}

	int position = rowPosition * _columns + columnPosition;

	_data[position] = newValue;
};

// Displays the matrix object in grid form
void Matrix::display()
{
	for (int i = 0; i <= _rows - 1; i++)
	{
		for (int j = 0; j <= _columns - 1; j++)
		{
			if (j == 0)
			{
				std::cout << "[";
			}
			
			std::cout << std::setw(2) << this->getElement(i, j);
			
			if (j == _columns - 1)
			{
				std::cout << "]" << std::endl;
			}
			else
			{
				std::cout << ", ";
			}
		}
	}
}

// TODO Implement
Matrix Matrix::add(Matrix &inputMatrix)
{
	// Make sure they are the same size and throw an exception if not
	if (_rows != inputMatrix._rows || _columns != inputMatrix._columns)
	{
		throw std::invalid_argument("The number of rows and columns between matrix objects must be equal.");
	}

	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			// Add the two integers and stuff it into the matrix at the correct position
			this->setElement(i, j, (this->getElement(i, j)+inputMatrix.getElement(i, j)));
		}
	}

	return *this;
}

// TODO Implement
Matrix Matrix::multiply(Matrix matrix)
{
	Matrix matrixToReturn;
	return matrixToReturn;
}

std::ostream& operator<<(std::ostream& outputStream, Matrix& matrix)
{
	outputStream << "";

	for (int i = 0; i <= matrix.getRows() - 1; i++)
	{
		for (int j = 0; j <= matrix.getColumns() - 1; j++)
		{
			if (j == 0)
			{
				outputStream << "[";
			}

			outputStream << std::setw(2) << matrix.getElement(i, j);

			if (j == matrix.getColumns() - 1)
			{
				outputStream << "]" << std::endl;
			}
			else
			{
				outputStream << ", ";
			}
		}
	}

	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Matrix& matrix)
{
	return inputStream;
}