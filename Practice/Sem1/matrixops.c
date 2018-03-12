//CS1010 Practice on 2D Arrays
//matrixop.c
//27 September 2017

#include <stdio.h>
#define N 10

void sum(int[N][N], int[N][N], int, int, int, int);
void mult(int[N][N], int[N][N], int, int, int, int);
void printMat(double[N][N], int, int);

int main (void) {
	int matA[N][N], matB[N][N];
	int row, column, row1, column1, count, count1;
	
	printf("Matrix A:\n");
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &row, &column);
	
	printf("Enter values for matrix:\n");
	
	for (count = 0; count < row; count++) {
		for (count1 = 0; count1 < column; count1++) {
			scanf("%d", &matA[count][count1]);
		}
	}
	
	printf("Matrix B:\n");
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &row1, &column1);
	
	printf("Enter values for matrix:\n");
	
	for (count = 0; count < row1; count++) {
		for (count1 = 0; count1 < column1; count1++) {
			scanf("%d", &matB[count][count1]);
		}
	}
	
	sum(matA, matB, row, row1, column, column1);
	mult(matA, matB, row, row1, column, column1);
	
	return 0;
}
	
void sum(int matA[N][N], int matB[N][N], int row, int row1, int column, int column1) {
	double mat[N][N] = {{0}};
	int count, count1;
	
	if (row != row1 || column != column1) {
		printf("Unmatched dimensions; cannot be added.\n");
	} else {
		for (count = 0; count < row; count++) {
			for (count1 = 0; count1 < column; count1++) {
				mat[count][count1] = matA[count][count1] + (double) matB[count][count1];
			}
		}
		printf("Sum matrix:\n");
		printMat(mat, row, column);
	}
}

void mult(int matA[N][N], int matB[N][N], int row, int row1, int column, int column1) {
	double mat[N][N] = {{0}};
	int count, count1, count2;
	
	if (row1 != column) {
		printf("Unmatched dimensions; number of columns in the first matrix has to equal that of the rows of the second matrix.");
	} else {
		for (count = 0; count < row; count++) {
			for (count1 = 0; count1 < column1; count1++) {
				for (count2 = 0; count2 < row1; count2++) {
					mat[count][count1] += matA[count][count2] * (double)matB[count2][count1];
				}
			}
		}
		printf("Product matrix:\n");
		printMat(mat, row, column1);
	}
}

void printMat(double mat[N][N], int row, int column) {
	int count, count1;
	
	for (count = 0; count < row; count++) {
		for (count1 = 0; count1 < column; count1++) {
			printf("%.2lf\t", mat[count][count1]);
		}
		printf("\n");
	}
}
