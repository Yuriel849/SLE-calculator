/*
Author	 : Myungjun Kim & Mario Ivanov
Version  : 25.08.2020.
Contents : Solve a system of linear equations using Gauss-Jordan Elimination, and print each step.
*/

#define _CRT_SECURE_NO_DEPRECATE // Required to use scanf() without warnings

/* Header files */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
int getSizeOfSystem(void);
double** createSystem(int);
void getValuesOfSystem(double** system, int size);
void printMatrix(double** system, int size);
void getRrefForm(double** m, int size);
void arrangeRows(double** m, int size);
int findNonNull(double** m, int size, int possition);
void rowExchange(double** m, int r1, int r2);
void freeMemory(double** m, int size);
void rowMultiplication(double** system, int size, int target, double multiplier);
void rowReduction(double** m, int size, int standard, int target);
extern double** getTestSystem(void);

/* Main function */
int main(void)
{
	/*
	int size = getSizeOfSystem();		  // Get size of the system of linear equations from the user.
	double** system = createSystem(size); // Create a 2D array for the system of linear equations
	*/

	int size = 4;
	double** system = getTestSystem();

	getValuesOfSystem(system, size);	  // Get the equation coefficients and solutions from the user.
	printMatrix(system, size);			  // Print the matrix for the first time.

	getRrefForm(system, size);
	printMatrix(system, size);

	freeMemory(system, size);			  // Free memory before termination.
	return 0;
}

/* Designate size of system (user input) */
int getSizeOfSystem(void)
{
	int equations = 0, scanResult = 0;

	while (1)
	{
		printf("Type the number of equations: ");
		scanResult = scanf("%d", &equations);

		if (!(equations <= 0 || scanResult != 1))
			break;

		printf("That entry is invalid. Enter the number of equations: ");

		while (getchar() != '\n') { // Clear the char buffer
			continue;
		}
	}

	return equations;
}

/* Create the system of linear equations */
double** createSystem(int size)
{
	double** system;

	if ((system = (double**)malloc(size * sizeof(double*))) == NULL)
	{
		free(system);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size; i++) {
		if ((system[i] = (double*)malloc((size + 1) * sizeof(double))) == NULL)
		{
			free(system);
			exit(EXIT_FAILURE);
		}
	}

	return system;
}

/* Enter coefficients and solution values (user input) */
void getValuesOfSystem(double** system, int size)
{
	printf("Please enter the coefficients of each equation, followed by the solution, one at a time and hit Enter.\n");
	for (int i = 0; i < size; i++)
	{
		for (int y = 0; y <= size; y++) {
			int b = scanf("%lf", &system[i][y]);
			while (getchar() != '\n') {
				continue;
			}
		}
	}
}

/* Print extended coefficient matrix */
void printMatrix(double** system, int size)
{
	for (char a = 'a'; a < 'a' + size; a++) {
		printf("|%c  ", a);
	}

	printf("\b|answer|\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= size; j++) {
			printf("%3.0lf", system[i][j]);
		}
		printf("\n");
	}
}

/* Find rref form of extended coefficient matrix */
void getRrefForm(double** m, int size)
{
	for (int i = 0; i < size; i++) {
		if (m[i][i] == 0) { // Ensure the first column has a valid non-zero value
			int temp = findNonNull(m, size, i);
			if (temp != -999) {
				rowExchange(m, i, temp);
			}
		}
		for (int j = i; j < size; j++) { // Ensure the first columns of all rows except the first row are zeros
			double colVal = m[j][i];

			if (colVal == 0) {
				continue;
			}
			else if (colVal != 1.0) {
				rowMultiplication(m, size, j, (double)1 / colVal);
			}

			if (j != i) {
				rowReduction(m, size, i, j);
			}
		}
	}
}

void arrangeRows(double** m, int size) {
	for (int i = 0; i < size; i++) {
		if (m[i][i] == 0) {
			int tmp = findNonNull(m, size, i);
			rowExchange(m, i, tmp);
		}
	}
}

/* Finds a row where the value in the designated position is not zero */
int findNonNull(double** m, int size, int position)
{
	for (int i = 0; i < size; i++) {
		if (m[i][position] != 0 && i > position) {
			return i;
		}
	}

	return -999;
}

/* Row exchange function */
void rowExchange(double** m, int r1, int r2)
{
	double* temp;
	temp = m[r2];
	m[r2] = m[r1];
	m[r1] = temp;
}

/* Row multiplication with scalar (pointers) */
void rowMultiplication(double** system, int size, int target, double multiplier)
{
	for (int i = 0; i <= size; i++)
	{
		system[target][i] *= multiplier;
	}
}

/* Row addition (pointers) *//*
void rowAddition(double** system, int size, int firstRowStart, int secondRowStart)
{

	for (int i =0; i<= size; i++)
	{
		system[firstRowStart][i] += system[secondRowStart][i];
	}
}
*/


/* Frees the memory of the given two-dimensional array */
void freeMemory(double** m, int size)
{
	for (int i = 0; i < size; i++) {
		free(m[i]);
	}
	free(m);
}

void rowReduction(double** m, int size, int standard, int target)
{
	for (int i = 0; i <= size; i++) {
		m[target][i] = m[standard][i] - m[target][i];
	}
	printMatrix(m, size);
}