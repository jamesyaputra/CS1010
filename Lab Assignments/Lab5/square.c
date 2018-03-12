//CS1010 AY2017/8 Semester 1 Lab5 Ex1
/* square.c
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * James Arista Yaputra
 * C04
 */

#include <stdio.h>
#define MAXSIZE 9

int scanSquare(int [MAXSIZE][MAXSIZE]);
int checkRange(int [MAXSIZE][MAXSIZE], int);
int checkSum(int [MAXSIZE][MAXSIZE], int);

int main(void) { 
	int size;
	int arr[MAXSIZE][MAXSIZE] = {{0}};
	
	size = scanSquare(arr);
	
	if (checkRange(arr, size) + checkSum(arr, size) == 2) {
		printf("It is a semi-magic square.\n");  
	} else {
		printf("It is not a semi-magic square.\n");
	}

	return 0;
}

// Reads in size of square and values in the square. 
// Returns the size of square.
int scanSquare(int square[MAXSIZE][MAXSIZE]) {
	int r, c, size;

	printf("Enter size of square: ");
	scanf("%d", &size);

	printf("Enter values in the square: \n");
	for (r=0; r<size; r++) {
		for (c=0; c<size; c++) {
			scanf("%d", &square[r][c]);
		}
	}

	return size;
}

// Checks whether all the numbers within the range
// [1, size*size] are inside the square.
// Pre-cond: size = positive int
// Return 1: All numbers within the range are found
// Return 0: Number(s) missing
int checkRange (int arr[MAXSIZE][MAXSIZE], int size) {
	int i, j, k, found = 0, start = 1;
	int check[size*size];
	
	for (i = 0; i < size*size; i++) {
		check[i] = start;
		start++;
	}
	
	for (i = 0; i < size*size; i++) {
		for (j = 0; j < size; j++) {
			for (k = 0; k < size; k++) {
				if (arr[j][k] == check[i]) {
					found++;
					check[i] = -1;
				}
			}
		}
	}
	
	if (found == size*size) {
		return 1;
	} else {
		return 0;
	}	
}

// Checks whether the sum of every row and column
// is the same.
// Pre-cond: size = positive int
// Return 1: The sums across all the rows and columns are equal
// Return 0: Different sums across rows and columns
int checkSum (int arr[MAXSIZE][MAXSIZE], int size) {
	int i, j, k, sumRow, sumCol;
	int sum = 0;

	for (i = 0; i < size; i++) {
		sum += arr[0][i];
	}
	
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			sumRow = 0;
			sumCol = 0;
			for (k = 0; k < size; k++) {
				sumRow += arr[j][k];
				sumCol += arr[k][j];
			}
			if (sumRow != sum || sumCol != sum) {
			return 0;
			}
		}
	}
	return 1;
}
