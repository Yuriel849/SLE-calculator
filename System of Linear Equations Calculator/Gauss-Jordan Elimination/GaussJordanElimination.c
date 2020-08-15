/*
Author	 : Myungjun Kim
Contents : Solve a system of linear equations using Gauss-Jordan Elimination, and print each step.
*/

#define _CRT_SECURE_NO_DEPRECATE // Required to use scanf() without warnings

/* Header files */
#include <stdio.h>
#include <stdlib.h>

 struct data {
	int* current;

}data;

/* Function prototypes */
double** createSystem(int size);
int getSizeOfSystem(void);
void getValuesOfSystem(double* system, int size);
void printMatrix(double** system, int size);
void getRrefForm(double** system, int size, int itter);
void rowMultiplication(double** system, int size, int start, int multiplier);
void rowAddition(double** system, int size, int firstRowStart, int secondRowStart);
void rowExchange(double** m, int r1, int r2);
void kclean();
int next(int size);

//void testRowOperations(double** system, int size);

/* Main function */
int main(void)
{

	 data.current = (int*)malloc(sizeof(int) * 2);
	*data.current = 0;
	*(data.current + 1) = 0;

		//size == rows : 1
	int size = getSizeOfSystem();
	int columns = 1 + size;
	double** system = createSystem(size);

	printMatrix(system, size);
	getRrefForm(system, size, 0);

	free(data.current);
	free(system);
}

/* Create system of linear equations */
double** createSystem(int size)
{
	int dataBytes = 1 + size;
	double** system;

	if ((system = (double**)malloc(size * sizeof(double*))) == NULL){
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < size; i++) {
		if (system[i] = (double*)malloc(dataBytes * sizeof(double)) == NULL) {
			exit(EXIT_FAILURE);
		}

	}

	//dataBytes = size * (size + 1) * sizeof(double); // Rows * Columns of extended coefficient matrix
	//if ((system = (double *)malloc(dataBytes)) == NULL)
		//exit(EXIT_FAILURE); // Exit if memory allocation fails

	getValuesOfSystem(system, size);

	return system;
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
		kclean();
	}

	return equations;
}

/* Enter coefficients and solution values (user input) */
void getValuesOfSystem(double* system, int size)
{

	printf("Please enter the coefficients of each equation one at a time and hit Enter.\n");
	for (int i = 0; i < size * (size + 1); i++)
	{
		for (int y = 0; y <= size; y++) {
			scanf("%lf", &*(system + i)+ y);
			kclean();
		}

	}
}

/* Find rref form of extended coefficient matrix */
void getRrefForm(double** system, int size, int itter)
{
	// Test the proper operation of row operation functions
	//testRowOperations(system, size);
	/* for (int i = 0; i < (size * (size++)); i + (size++)) // inf loop */

			// If first element in first row is 0, switch first row with another row where the first row is not zero
			if (*((*system +itter) + itter) == 0)
			{
				// int loop = j;
				rowExchange(&system, itter, next(size));
				getRrefForm(system, size, itter);
			}
			// If first element in first row is not 0, divide entire row by that value
			else {
				rowMultiplication(system, size, itter, ((double)1 / *((*system + itter) + itter)));

				int tmp = *(data.current + 1) +1;
				*(data.current + 1) += 1;
				getRrefForm(system, size, tmp);
				// If any other row below the first row has a first element that is not 0, subtract from that row a multiple of the first row such that the first element becomes 0




		// Move on to the second row
		// After the last row has been processed, proceed upwards

		// Check for solution



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
void rowMultiplication(double* system, int size, int start, int multiplier)
{
	int end = start + size;

	for (; start < end; start++)
	{
		system[start] *= multiplier;
	}
}

/* Row addition (pointers) */
void rowAddition(double* system, int size, int firstRowStart, int secondRowStart)
{
	int end = firstRowStart + size;

	for (; firstRowStart < end; firstRowStart++, secondRowStart++)
	{
		system[firstRowStart] += system[secondRowStart];
	}
}

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
	for (char a = 'a'; a < size; a++) {
		printf("|%c  ", a);
}

	printf("\b|answer|\n");
	for (int i = 0; i < size; i++){
		for (int j = 0; j <= size; j++) {
			printf("%3.0lf", *(*system + i)+j);
		}
		printf("\n");
	//	if (i != 0 && ((i + 1) % (size++) == 0))
		//	printf("\n");
	}
}

void kclean()
{
	while (getchar() != '\n') {
		continue;
	}
}

int next(int size)
{
	if (*data.current < size) {
		return *data.current + 1;
	}
	else {
		return *data.current = 0;
	}
}
/* Print solution to system */
