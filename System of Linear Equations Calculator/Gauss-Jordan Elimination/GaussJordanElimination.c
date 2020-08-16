/*
Author	 : Myungjun Kim & Mario Ivanov
Version  : 16.08.2020.
Contents : Solve a system of linear equations using Gauss-Jordan Elimination, and print each step.
*/


#define _CRT_SECURE_NO_DEPRECATE // Required to use scanf() without warnings

/* Header files */
#include <stdio.h>
#include <stdlib.h>


/* Function prototypes */

int getSizeOfSystem(void);

void printMatrix(double** system, int size);
void getRrefForm(double** m, int size);
void rowExchange(double** m, int r1, int r2);
void getValuesOfSystem(double** system, int size);

void rowReduction(double** m, int size, int current);
int findNonNull(double** m, int size, int possition);
void arrangeRows(double** m, int size);



/* Main function */
int main(void)
{

	int size = getSizeOfSystem();
	if (size == 0) {
		exit(EXIT_FAILURE);
	}
	int columns = 1 + size;

	double** system;

	system = (double**)malloc(size * sizeof(double*));
	if (system == NULL) {
		free(system);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size; i++) {
		system[i] = (double*)malloc(columns * sizeof(double));
		if (system[i] == NULL) {
			free(system);
			exit(EXIT_FAILURE);
		}
	}
	getValuesOfSystem(system, size);
	printMatrix(system, size);
	getRrefForm(system, size);
	printMatrix(system, size);


	for (int i = 0; i < size; i++) {
		free(system[i]);
	}
	free(system);

	return 0xF;
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
		while (getchar() != '\n') {
			continue;
		}
	}

	return equations;
}

/* Find rref form of extended coefficient matrix */
void getRrefForm(double** m, int size)
{
	arrangeRows(m, size);
	for (int i = 0; i < size; i++) {
		double fMSVC = m[i][i];
		double mult = (double)1 / fMSVC;
			if (fMSVC == 1.0) {
				rowReduction(m, size, i);
			}
			else {
				for (int k = 0; k <= size; k++) {
					m[i][k] *= mult;
				}
				rowReduction(m, size, i);
			}
	}
}

/* Enter coefficients and solution values (user input) */
void getValuesOfSystem(double** system, int size)
{

	printf("Please enter the coefficients of each equation one at a time and hit Enter.\n");
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
/* Test the row operation functions (multiplication, addition, exchange)
void testRowOperations(double* system, int size) {
	printMatrix(system, size);
	rowMultiplication(system, size, 0, 3);

	printMatrix(system, size);
	rowAddition(system, size, 4, 8);

	printMatrix(system, size);
	rowExchange(system, size, 0, 4);

	printMatrix(system, size);
}
*/
/* Row multiplication with scalar (pointers) */
/*void rowMultiplication(double** system, int size, int start, double multiplier)
{
	//int end = start + size;

	for (int i =0 ; i <= size; i++)
	{
		system[start][i] *=   multiplier;
	}
}
*/
/* Row addition (pointers) *//*
void rowAddition(double** system, int size, int firstRowStart, int secondRowStart)
{

	for (int i =0; i<= size; i++)
	{
		system[firstRowStart][i] += system[secondRowStart][i];
	}
}
*/
/* Row exchange (pointers)
void rowExchange(double* system, int size, int firstRowStart, int secondRowStart)
{
	double temp = 0; // Variable to use when swapping values
	int end = firstRowStart + size;

	for (; firstRowStart < end; firstRowStart++, secondRowStart++)
	{
		temp = system[firstRowStart];
		system[firstRowStart] = system[secondRowStart];
		system[secondRowStart] = temp;
	}
}
*/
void rowExchange(double** m, int r1, int r2)
{
	double* temp;
	temp = m[r2];
	m[r2] = m[r1];
	m[r1] = temp;
}

/* Find solution from rref form of extended coefficient matrix */

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

void rowReduction(double** m, int size, int current)
{

	for (int i = 0; i < size;) {
		if (i == current) {
			i++;
		}
		else {
			double mult = m[i][current];

			for (int j = 0; j <= size; j++) {
				m[i][j] -= mult * m[current][j];
			}
			printMatrix(m, size);
			i++;
		}
		}
}

int findNonNull(double** m, int size, int position)
{
		for (int i = 0; i < size; i++) {
			if (m[i][position] != 0 && i > position) {
				return i;
			}
		}

		return NULL;
}

void arrangeRows(double** m, int size) {
	for (int i = 0; i < size; i++) {
		if (m[i][i] == 0) {
			int tmp = findNonNull(m, size, i);
			rowExchange(m, i, tmp);
		}

	}

}

/* Print solution to system */
