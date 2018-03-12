// CS1010 AY2015/6 Semester 2 PE2 Ex1
//
// minefield.c
//
// Name: James Arista Yaputra
// Matriculation number: A0170761H
// plab-id:
// Discussion group: C04
// Description: Reads in a minefield and computes the aftermath of the detonation of the mine(s)
//		in the field, the maximum damage done, and the number of safe spaces in the field. 

#include <stdio.h>
#define MAX_SIZE 10

int readField(int [][MAX_SIZE]);
int computeSafe(int [][MAX_SIZE], int);
int detonate(int[][MAX_SIZE], int[][MAX_SIZE], int);
void printField(int [][MAX_SIZE], int);

int main(void) {
	int field[MAX_SIZE][MAX_SIZE], aftermath[MAX_SIZE][MAX_SIZE] = {{0}};
	int size, max;

	size = readField(field);
	max = detonate(field, aftermath, size);

	printf("Aftermath: \n");
	printField(aftermath, size);

	printf("Maximum damage: %d\n", max); // Incomplete
	printf("Number of safe areas: %d\n", computeSafe(aftermath, size)); // Incomplete

	return 0;
}

// Computes the aftermath of the detonation of the mines in the field
// and returns the maximum damage done.
// Pre-cond:
// size > 0
int detonate(int field[MAX_SIZE][MAX_SIZE], int aftermath[MAX_SIZE][MAX_SIZE], int size) {
	int maximum = 0, i, j, k;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (field[i][j] != 0) {
				aftermath[i][j] += 1;
				for (k = 1; k < field[i][j]; k++) {
					if (i+k < size) 
						aftermath[i+k][j] += 1;
					if (i-k >= 0)
						aftermath[i-k][j] += 1;
					if (j+k < size)
						aftermath[i][j+k] += 1;
					if (j-k >= 0)
						aftermath[i][j-k] += 1;
				}
			}
		}
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (aftermath[i][j] > maximum)
				maximum = aftermath[i][j];
		}
	}

	return maximum;
}

// Computes the number of safe spaces
// in the aftermath of the detonation
// Pre-cond:
// size > 0
int computeSafe(int aftermath[MAX_SIZE][MAX_SIZE], int size) {
	int i, j, safe = 0;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (aftermath[i][j] == 0) {
				safe++;
			}
		}
	}

	return safe;
}

// Reads in a minefield
int readField(int field[][MAX_SIZE]) {
	int i,j, size;

	printf("Enter size: \n");
	scanf("%d", &size);

	printf("Enter minefield: \n");
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			scanf("%d", &field[i][j]);
		}
	}

	return size;
}

// Prints a minefield
void printField(int field[][MAX_SIZE], int size) {
	int i,j;

	for (i=0; i<size; i++){
		for (j=0; j<size; j++)
			printf("%d ", field[i][j]);
		printf("\n");
	}
}
