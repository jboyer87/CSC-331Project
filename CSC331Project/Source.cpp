#include <iostream>
#include "Matrix.h"

int main() {

	// Initialize 2 Matrix objects. Using default constructor yields a 3x3, and using 
	// additional constructur with parameters to specify a 3x3 matrix.

	// First 3x3 matrix using default constructor
	Matrix matrix1;

	// Second 3x3 matrix using constructor with parameters for column/row
	Matrix matrix2 = Matrix(3, 3);

	// Testing get and set methods. First, get element, then set it to something new,
	// then get the same element again to show that it has changed.
	std::cout << "Testing get method..." << std::endl << std::endl;
	std::cout << "Initial value at [0,0]: " << matrix1.getElement(0, 0) << std::endl << std::endl;

	std::cout << "Testing set method..." << std::endl << std::endl;
	
	matrix1.setElement(0, 0, 11);

	std::cout << "New value at [0,0]: " << matrix1.getElement(0, 0) << std::endl << std::endl;

	std::cout << "Trying to retrieve out of range element..." << std::endl << std::endl;

	// Test exception handling on out of range elements for both get and set
	// Test get
	try
	{
		std::cout << matrix1.getElement(4, 4);
	}
	catch (const std::out_of_range &exception)
	{
		std::cout << exception.what() << std::endl << std::endl;
	}
	
	std::cout << "Trying to set out of range element..." << std::endl << std::endl;

	// Test set
	try
	{
		matrix1.setElement(4, 4, 11);
	}
	catch (const std::out_of_range &exception)
	{
		std::cout << exception.what() << std::endl << std::endl;
	}

	// Calling display via cout to display both matrixes
	std::cout << "Testing printing both matrices..." << std::endl << std::endl;

	std::cout << matrix1 << std::endl << std::endl;
	std::cout << matrix2 << std::endl << std::endl;

	std::cout << "Testing adding both matrices together..." << std::endl << std::endl;

	// Try to add two matrices together
	try
	{
		Matrix matrix3 = matrix1.add(matrix2);

		std::cout << matrix3;
	}
	catch (const std::invalid_argument &exception)
	{
		std::cout << exception.what() << std::endl << std::endl;
	}

	std::cout << "Testing multiplying both matrices together..." << std::endl << std::endl;

	// Try to multiply two matrices together
	try
	{
		std::cout << matrix1.multiply(matrix2);
	}
	catch (const std::invalid_argument &exception)
	{
		std::cout << exception.what() << std::endl << std::endl;
	}

	std::cout << "Done!" << std::endl << std::endl;

	return 0;
}