#pragma once
#include <iostream>
#include <iomanip>
#include <exception>

template<typename T>
class Matrix {
public:
	Matrix();

	Matrix(int columns, int rows);

	virtual ~Matrix();

	int Matrix::getRows()
	{
		return _rows;
	}

	int Matrix::getColumns()
	{
		return _columns;
	}

	const T Matrix::getElement(int rowPosition, int columnPosition);

	void Matrix::setElement(int rowPosition, int columnPosition, T newValue);

	void Matrix::display();

	Matrix<T> add(Matrix &matrix);
	Matrix<T> multiply(Matrix &matrix);

	template <typename T>
	friend std::ostream& operator<<(std::ostream& outputStream, Matrix<T>& matrix);
	template <typename T>
	friend std::istream& operator>>(std::istream& inputStream, Matrix<T>& matrix);

private:
	int _columns;
	int _rows;

	T* _data;

	void Matrix::initializeMatrixData();
};

//
// Definitions follow below - was unable to place in Matrix.cpp due to linker errors on compilation.
//

// Default constructor - Initializes row and column variables to 3 and 3. Initializes the
// matrix elements to random numbers between 1 and 10.
template<typename T>
Matrix<T>::Matrix() : _rows(3), _columns(3)
{
	_data = new T[_rows * _columns];

	this->initializeMatrixData();
}

// Constructor with parameters, also initializes the matrix elements to random numbers.
template<typename T>
Matrix<T>::Matrix(int columns, int rows)
{
	_rows = rows;
	_columns = columns;
	_data = new T[columns * rows];

	this->initializeMatrixData();
};

// Destructor that deletes the array data correctly.
template<typename T>
Matrix<T>::~Matrix()
{
	delete[] _data;
};

// Function to initialize the matrix data with random integers between 0 and 10.
template<typename T>
void Matrix<T>::initializeMatrixData()
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
template<typename T>
const T Matrix<T>::getElement(int rowPosition, int columnPosition)
{
	if (rowPosition > _rows || columnPosition > _columns)
	{
		throw std::out_of_range("The row and column position entered is out of range.");
	}

	int position = rowPosition * _columns + columnPosition;
	T data = _data[position];
	return data;
}

// Sets the element at the given row/column position to the new value
template<typename T>
void Matrix<T>::setElement(int rowPosition, int columnPosition, T newValue)
{
	if (rowPosition > _rows || columnPosition > _columns)
	{
		throw std::out_of_range("The row and column position entered is out of range.");
	}

	int position = rowPosition * _columns + columnPosition;

	_data[position] = newValue;
};

// Displays the matrix in row/column form
template<typename T>
void Matrix<T>::display()
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
template<typename T>
Matrix<T> Matrix<T>::add(Matrix &inputMatrix)
{
	// Make sure they are the same size and throw an exception if not
	if (_rows != inputMatrix._rows || _columns != inputMatrix._columns)
	{
		throw std::invalid_argument("The number of rows and columns between matrix objects must be equal.");
	}

	Matrix<T> *temp = new Matrix<T>(_columns, _rows);

	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			// Add the two integers and stuff it into the matrix at the correct position
			temp->setElement(i, j, (this->getElement(i, j) + inputMatrix.getElement(i, j)));
		}
	}

	return *temp;
}

// Multiplies one matrix by another and returns the result
template<typename T>
Matrix<T> Matrix<T>::multiply(Matrix &inputMatrix)
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
				sum += this->getElement(i, k) * inputMatrix.getElement(k, j);
			}

			temp->setElement(i, j, (sum));
		}
	}

	return *temp;
}

// Displays a matrix in row/column form
template<typename T>
std::ostream& operator<<(std::ostream& outputStream, Matrix<T>& matrix)
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
template<typename T>
std::istream& operator>>(std::istream& inputStream, Matrix<T>& matrix)
{
	for (int i = 0; i < matrix._rows * matrix._columns; ++i)
	{
		inputStream >> matrix._data[i];
	}
	
	return inputStream;
}