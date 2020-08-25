/*
Author	 : Mario Ivanov
Version  : 23.08.2020.
Contents : Provide a pre-defined system of linear equations to test the Gauss-Jordan Elimination program.
*/

#include <stdlib.h>

int test(void) {
	double a[4][5] = { {1,1,1,0,2},{1,0,1,-1,0},{1,1,0,1,4},{0,1,1,-1,-3} };
	double b[4][5] = { {1,1,1,0,2},{1,2,0,2,0},{3,0,5,1,-1},{0,2,2,1,-2} };
	double c[4][5] = { {2,4,-2,0,8},{-1,0,3,0,-8},{0,1,2,0,-5},{-3,-2,-2,0,7} };
	int size = 4;

	double** mat1;
	double** mat2;
	double** mat3;
	if ((mat1 = (double**)malloc(size * sizeof(double*))) == NULL)
	{
		free(mat1);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size; i++) {
		if ((mat1[i] = (double*)malloc((size + 1) * sizeof(double))) == NULL)
		{
			free(mat1);
			exit(EXIT_FAILURE);
		}
	}
	if ((mat2 = (double**)malloc(size * sizeof(double*))) == NULL)
	{
		free(mat2);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size; i++) {
		if ((mat2[i] = (double*)malloc((size + 1) * sizeof(double))) == NULL)
		{
			free(mat2);
			exit(EXIT_FAILURE);
		}
	}
	if ((mat3 = (double**)malloc(size * sizeof(double*))) == NULL)
	{
		free(mat3);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size; i++) {
		if ((mat3[i] = (double*)malloc((size + 1) * sizeof(double))) == NULL)
		{
			free(mat3);
			exit(EXIT_FAILURE);
		}
	}


	for (int i = 0; i < size;i++) {
		for (int j = 0; j <= size;j++) {
			mat1[i][j] = a[i][j];
			mat2[i][j] = b[i][j];
			mat3[i][j] = c[i][j];
		}
	}
	printf("matrix 1\n");
	printMatrix(mat1, size);

	getRrefForm(mat1, size);
	printMatrix(mat1, size);

	printf("matrix 2\n");
	printMatrix(mat2, size);

	getRrefForm(mat2, size);
	printMatrix(mat2, size);

	printf("matrix 3\n");
	printMatrix(mat3, size);

	getRrefForm(mat3, size);
	printMatrix(mat3, size);

	freeMemory(mat1, size);
	freeMemory(mat2, size);
	freeMemory(mat3, size);


}
