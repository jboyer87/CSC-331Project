# CSC-331 Matrix Project

## Synopsis
In this project, I define a template matrix class in C++ and equip the class with a few matrix operations.

## Project specifications
__The Matrix class must have the following private data members at least:__
1. [x] A variable to represent rows for the number of rows of the matrix
2. [x] A variable column for the number of columns of the matrix
3. [x] A pointer variable data to point to the matrix data.

__The Matrix class must also have the following member functions:__
1. [x] A default constructor – this constructor initializes the row and column of the matrix to 3, then dynamically allocates memory for the elements of the matrix. The constructor also initializes the Matrix elements to random integers between 0 and 10.
2. [x] A constructor with parameters - The parameters to the constructor are used to initialize the row and column variables. This constructor dynamically allocates memory for the elements of the matrix. The constructor also initializes the Matrix elements to random integers between 0 and 10.
3. [x] A correct destructor.
4. [x] A method called display() that displays the matrix in proper row/column form.
5. [x] The method getElement(int i, int j) that will return the (i,j) element in the matrix. Include exception handling with object out_of_range for the case when i or j or both are out of bounds
6. [x] The method setElement ( int i, int j, int value) that set the (i,j) element of the matrix to the value. Include exception handling with object out_of_range for the case when i or j or both are out of bounds.
7. [x] The method for the addition of one matrix object to another add(Matrix a) that receives a Matrix object a and adds it to the implicit object and returns another Matrix object. Include exceptions if matrices cannot be added ( e.g. in the case of incompatible types or dimensions)
8. [x] The method multiply( Matrix a) that receives a Matrix object and multiplies it to the implicit object and returns another Matrix object. Include exceptions if matrices cannot be multiplies (incompatible dimensions). An algorithm for matrix multiplication is given on page 205 of your textbook.
9. [x] Overload the out stream operator “<<” for the Matrix class to display a Matrix Object
10. [ ] Overload the in stream operator “>>” for the Matrix class to receive elements for a Matrix object.
11. [x] Make proper use of const and references.

__Write a main(…) method to text the Matrix class. The main(…) method must include:__
1. [x] Declare two 3x3 matrices.
2. [x] Test setElement() and getElement() methods
3. [x] Test the exceptions by using invalid parameters
4. [x] Use the operator “<<”to print both matrices.
5. [ ] Use the operator “>>” change the values of one of the matrices. Print the new matrix.
6. [x] Call the add method and display the result.
7. [x] Call the multiply method and display the result.