/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * James Arista Yaputra
 * C04
 */

#include <stdio.h>
#define DIM 12

int scanBoard(int[DIM][DIM]);
int search(int[DIM][DIM], int, int*, int*);

int main(void) {
	int board[DIM][DIM] = { {0} };     
	int length;           // length of the longest sequence of search digit
	int bestRow, bestCol; // where the longest sequence of search digit starts in the board

	length = search(board, scanBoard(board), &bestRow, &bestCol);

	if (length > 0) {
		printf("Length of longest sequence = %d\n", length); 
		printf("Start at (%d,%d)\n", bestRow, bestCol);      
	} else {
		printf("No such sequence.\n");
	}

	return 0;
}

//This function scans the search digit and the values of the board
//input by the user and returns the search digit to be passed to
//the search function called in the main function.
//pre-cond: values inserted are integers
int scanBoard(int arr[DIM][DIM]) {
	int i, j, key;

	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	scanf("%d", &key);

	return key;
}

//This function searches for the search digit in the board,
//counts the longest sequence of the search digit in the board
//and returns the length of the longest sequence and the location
//of the sequence closest to 0,0 according to the row-major order.
//pre-cond: search digit is an integer.
int search(int arr[DIM][DIM], int key, int *row, int *col) {
	int length[3], lengthMAX = 0;
	int i, j, k;

	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			length[0] = length[1] = length[2] = 0;
			k = 1;
			if (arr[i][j] == key) {
				length[0]++;
				length[1]++;
				length[2]++;
				if (arr[i+1][j] == key) {
					while (arr[i+k][j] == key) {
						length[0]++;
						k++;
					}
				}
				k = 1;
				if (arr[i][j+1] == key) {
					while (arr[i][j+k] == key) {
						length[1]++;
						k++;
					}
				}
				k = 1;
				if (arr[i+1][j+1] == key) {
					while (arr[i+k][j+k] == key) {
						length[2]++;
						k++;
					}
				}
			}	
			for (k = 0; k < 3; k++) {
				if (length[k] > lengthMAX) {
					lengthMAX = length[k];
					*row = i;
					*col = j;
				}
			}
		}
	}

	return lengthMAX;
}
