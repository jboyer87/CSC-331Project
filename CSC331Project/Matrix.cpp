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

// Displays the matrix in row/column form
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

// Adds one matrix to another and returns the result
Matrix Matrix::add(Matrix &inputMatrix)
{
	// Make sure they are the same size and throw an exception if not
	if (_rows != inputMatrix._rows || _columns != inputMatrix._columns)
	{
		throw std::invalid_argument("The number of rows and columns between matrix objects must be equal.");
	}

	Matrix *temp = new Matrix(_columns, _rows);

	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			// Add the two integers and stuff it into the matrix at the correct position
			temp->setElement(i, j, (this->getElement(i, j)+inputMatrix.getElement(i, j)));
		}
	}

	return *temp;
}

// Multiplies one matrix by another and returns the result
Matrix Matrix::multiply(Matrix &inputMatrix)
{
	// Make sure they are able to be multiplied and throw an exception if not
	if (_columns != inputMatrix._rows)
	{
		throw std::invalid_argument("The number of columns in the first matrix must match the number of rows in the second matrix.");
	}

	// Final matrix will be rows = rows of the first and columns = columns of the second
	Matrix *temp = new Matrix(inputMatrix._columns, this->_rows);

	for (int i = 0; i < this->_rows; i++)
	{
		for (int j = 0; j < inputMatrix._columns; j++)
		{
			int sum = 0;

			for (int k = 0; k < inputMatrix._rows; k++)
			{
				sum += this->getElement(i,k) * inputMatrix.getElement(k, j);
			}

			temp->setElement(i, j, (sum));
		}
	}

	return *temp;
}

// Displays a matrix in row/column form
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

// Takes a matrix object as input
std::istream& operator>>(std::istream& inputStream, Matrix& matrix)
{
	for (int i = 0; i < matrix._rows * matrix._columns; ++i)
	{
		inputStream >> matrix._data[i];
	}
	
	return inputStream;
}