#include <iostream>
#include "Matrix.h"

int main() {

	// Initialize 2 Matrix objects. Using default constructor yields a 3x3, and using 
	// additional constructur with parameters to specify a 3x3 matrix.

	// First 3x3 matrix using default constructor
	Matrix<int> matrix1;

	// Second 3x3 matrix using constructor with parameters for column/row
	Matrix<int> matrix2 = Matrix<int>(3, 3);
	
	// Testing float/doubles
	Matrix<double> doubleMatrix;
	Matrix<float> floatMatrix;

	// Testing get and set methods. First, get element, then set it to something new,
	// then get the same element again to show that it has changed.
	std::cout << "Testing get method..." << std::endl << std::endl;
	std::cout << "\tInitial value at [0,0]: " << matrix1.getElement(0, 0) << std::endl << std::endl;

	std::cout << "Testing set method..." << std::endl << std::endl;
	
	matrix1.setElement(0, 0, 11);

	std::cout << "\tNew value at [0,0]: " << matrix1.getElement(0, 0) << std::endl << std::endl;

	std::cout << "Trying to retrieve out of range element..." << std::endl << std::endl;

	// Test exception handling on out of range elements for both get and set
	// Test get
	try
	{
		std::cout << matrix1.getElement(4, 4);
	}
	catch (const std::out_of_range &exception)
	{
		std::cout << "\t" << exception.what() << std::endl << std::endl;
	}
	
	std::cout << "Trying to set out of range element..." << std::endl << std::endl;

	// Test set
	try
	{
		matrix1.setElement(4, 4, 11);
	}
	catch (const std::out_of_range &exception)
	{
		std::cout << "\t" << exception.what() << std::endl << std::endl;
	}

	// Calling overloaded cout to display both matrixes in row/column form. Program also includes a display() method
	// that can be called with matrix1.display()
	std::cout << "Testing printing both matrices..." << std::endl << std::endl;

	std::cout << matrix1 << std::endl;
	std::cout << matrix2 << std::endl;

	std::cout << "Testing adding both matrices together..." << std::endl << std::endl;

	// Try to add two matrices together
	try
	{
		std::cout << matrix1.addAgain(matrix2) << std::endl;
	}
	catch (const std::invalid_argument &exception)
	{
		std::cout << "\t" << exception.what() << std::endl << std::endl;
	}

	Matrix<int> matrix3 = Matrix<int>(3, 3);
	Matrix<int> matrix4 = Matrix<int>(3, 3);

	// Calling overloaded cout to display both matrixes in row/column form. Program also includes a display() method
	// that can be called with matrix1.display()
	std::cout << "Setting up two new matrices to multiply..." << std::endl << std::endl;

	std::cout << matrix3 << std::endl;
	std::cout << matrix4 << std::endl;

	std::cout << "Testing multiplying two matrices together..." << std::endl << std::endl;

	// Try to multiply two matrices together
	try
	{
		std::cout << matrix3.multiply(matrix4) << std::endl;
	}
	catch (const std::invalid_argument &exception)
	{
		std::cout << "\t" << exception.what() << std::endl << std::endl;
	}


	// Create a matrix from user input
	std::cout << "Now let's create a matrix." << std::endl << std::endl;

	int columns = 0;
	int rows = 0;

	// Take the number of columns
	std::cout << "Enter the number of columns: ";
	std::cin >> columns;

	// Take the number of rows
	std::cout << "Enter the number of rows: ";
	std::cin >> rows;

	std::cout << std::endl;

	// Print columns/rows back to user to verify
	std::cout << "You entered " << columns << " column(s) and " << rows << " row(s)." << std::endl;

	// Create a new matrix with specified columns/rows
	Matrix<int> matrix5 = Matrix<int>(columns, rows);

	// Prompt the user for matrix values, will prompt rows*columns times
	std::cout << "Enter the matrix values separated by line breaks (press ENTER after each value): " << std::endl;
	std::cout << "**values will fill rows from left to right, and columns from top to bottom**" << std::endl;

	// Error checking for input values (makes sure values are integers)
	bool valid = false;

	while (!valid)
	{
		valid = true;

		std::cout << "Enter an integer value: " << std::endl;
		// Take in the matrix values
		std::cin >> matrix5;

		// If cin.fail(), that means the user did not enter an integer. Try to gather the values over again
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter integer values only. Please start again from the beginning." << std::endl;
			valid = false;
		}
	}

	std::cout << std::endl;

	// Print the matrix back to the user in row/column form
	std::cout << "The matrix you entered:" << std::endl;

	std::cout << matrix5 << std::endl;
	
	// Finished!
	std::cout << "Done!";

	return 0;
}