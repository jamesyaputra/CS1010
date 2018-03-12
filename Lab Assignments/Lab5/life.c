/* CS1010 AY2017/8 Semester 1 Lab5 Ex3
 * Game of Life
 * James Arista Yaputra
 * C04
 */

#include <stdio.h>

#define DIM_ROW 20
#define DIM_COL 20
#define DEAD    '-'
#define LIFE    'O'
#define MAX_GEN 5

int genesis(char[][DIM_COL+2]); 
void display(int, char[][DIM_COL+2]);
int next_generation(char[][DIM_COL+2]);
void reassign(char[][DIM_COL+2], char[][DIM_COL+2]);
int checkNeigh(char[][DIM_COL+2], int, int);

int main(void) {
	char board[DIM_ROW+2][DIM_COL+2];	// the community
	int  lives;				// how many lives in community
	int  generation = 0;			// generation

	lives = genesis(board);

	while (generation < MAX_GEN) {
		lives = next_generation(board);
		generation++;
		if (lives == 0) {
			break;
		}
	}

	display(generation, board);	
	return 0;
}

// To initialise the community with generation 0 from user's input, and
// return the number of life cells read.
// Sentinels are used here. Dead cells are padded around the actual
// community area.
int genesis(char community[][DIM_COL+2]) {
	int population = 0;
	int r, c; 

	// Fill left-most and right-most columns with dead cells.
	for (r=0; r < DIM_ROW + 2; r++)
		community[r][0] = community[r][DIM_COL + 1] = DEAD;

	// Fill top and bottom rows with dead cells.
	for (c=1; c < DIM_COL + 1; c++)
		community[0][c] = community[DIM_ROW + 1][c] = DEAD;

	// Fill the middle 20x20 area with input data
	for (r=1; r<=DIM_ROW; r++) {
		for (c=1; c<=DIM_COL; c++) {
			community[r][c] = fgetc(stdin);
			if (community[r][c] == LIFE)
				population++;
		}
		fgetc(stdin);  // to read the newline character
	}

	return population;
}

// To display the community
void display(int generation, char community[][DIM_COL+2]) {
	int r, c;

	printf("Generation %d:\n", generation);
	for (r=1; r <= DIM_ROW; r++) {
		for (c=1; c <= DIM_COL; c++) {
			printf("%c", community[r][c]);
		}
		printf("\n");
	}
}

// To generate next generation and
// return number of live cells in next generation.
int next_generation(char community[][DIM_COL+2]) {
	int r, c;
	int population = 0;
	char dummyComm[DIM_ROW+2][DIM_COL+2];

	for (r = 0; r < DIM_ROW+2; r++) {
		for (c = 0; c < DIM_COL+2; c++) {
			dummyComm[r][c] = community[r][c];
		}
	} //assigns the values in the community array into a dummy array.

	for (r = 1; r < DIM_ROW+1; r++) {
		for (c = 1; c < DIM_COL+1; c++) {
			if (community[r][c] == LIFE) {
				if (checkNeigh(community, r-1, c-1) < 2 || checkNeigh(community, r-1, c-1) > 3) {
					dummyComm[r][c] = DEAD;
				}
			} else {
				if (checkNeigh(community, r-1, c-1) == 2) {
					dummyComm[r][c] = LIFE;
				}
			}
		}
	} //computes the next generation into the dummy array.

	for (r = 1; r < DIM_ROW+1; r++) {
		for (c = 1; c < DIM_COL+1; c++) {
			if (dummyComm[r][c] == LIFE) {
				population++;
			}
		}
	} //computes the population of the community.

	for (r = 1; r < DIM_ROW+1; r++) {
		for (c = 1; c < DIM_COL+1; c++) {
			if (dummyComm[r][c] != community[r][c]) {
				reassign(dummyComm, community);
				return population;
			}
		}
	} //determines whether or not the community array should be reassigned the new generation from the dummy array.

	return 0;
}

//Reassigns the community array with the values inside the dummy array.
void reassign (char dummyComm[][DIM_COL+2], char community[][DIM_COL+2]) {
	int r, c;

	for (r = 0; r < DIM_ROW+2; r++) {
		for (c = 0; c < DIM_COL+2; c++) {
			community[r][c] = dummyComm[r][c];
		}
	}
}

//Computes the number of neighbours of a cell.
int checkNeigh(char community[][DIM_COL+2], int row, int col) {
	int neighbours = -1, r, c;

	for (r = row; r < row+3; r++) {
		for (c = col; c < col+3; c++) {
			if (community[r][c] == LIFE) {
				neighbours++;
			}
		}
	}

	return neighbours;
}
