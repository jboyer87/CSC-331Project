#include <iostream>
#include "Matrix.h"

int main() {

	// Initialize 2 Matrix objects. Using default constructor yields a 3x3, and using 
	// additional constructur with parameters to specify a 3x3 matrix.
	Matrix matrix1;

	Matrix matrix2 = Matrix(3, 3);

	// Testing get and set methods. First, get element, then set it to something new,
	// then get the same element again to show that it has changed.
	std::cout << "Initial value at [0,0]: " << matrix1.getElement(0, 0) << std::endl;

	matrix1.setElement(0, 0, 11);

	std::cout << "New value at [0,0]: " << matrix1.getElement(0, 0) << std::endl;

	// Test exception handling on out of range elements for both get and set
	try
	{
		std::cout << matrix1.getElement(4, 4);
	}
	catch (const std::out_of_range &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	try
	{
		matrix1.setElement(4, 4, 11);
	}
	catch (const std::out_of_range &exception)
	{
		std::cout << exception.what() << std::endl;
	}


	std::cout << matrix1 << std::endl;
	std::cout << matrix2 << std::endl;

	// Try to add two matrices together
	try
	{
		Matrix sumOfTwo = matrix1.add(matrix2);
		std::cout << sumOfTwo;
	}
	catch (const std::invalid_argument &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	// matrix1.display();

	// Using the overloaded << operator to print both matrices.
	std::cout << matrix1 << std::endl;
	std::cout << matrix2;

	// Add matrix1 and matrix2 and show the result.
	//std::cout << matrix1.add(matrix2);

	// Multiply matrix1 and matrix2 and show the result.
	//std::cout << matrix1.multiply(matrix2);

	return 0;
}