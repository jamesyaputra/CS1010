// validPath.c
#include <stdio.h>
#include <string.h>

#define SIZE 6
#define WALL 0
#define CELL 1
#define MAX_PATHLEN 10

void readMaze(int [][SIZE], int);
int isValid(int [][SIZE], char []);

int main(void) {
	int maze[SIZE][SIZE];
	char path[MAX_PATHLEN+1];

	readMaze(maze, SIZE); 

	printf("Enter path: ");
	scanf("%s", &path);

	if (isValid(maze, path))
		printf("Path is valid.\n");
	else
		printf("Path is not valid.\n");

	return 0;
}

void readMaze(int maze[][SIZE], int size) {
	int r, c;

	printf("Enter maze:\n");
	for (r = 0; r < size; r++)
		for (c = 0; c < size; c++)
			scanf("%d", &maze[r][c]);
}

int isValid(int maze[][SIZE], char path[]) {
	int pathlen;
	int i;
	int currentPos[2] = {0};

	pathlen = strlen(path);
	
	for (i = 0; i < pathlen; i++) {
		if (path[i] == 'N') {
			currentPos[0] -= 1;
		} else if (path[i] == 'S') {
			currentPos[0] += 1;
		} else if (path[i] == 'W') {
			currentPos[1] -= 1;
		} else if (path[i] == 'E') {
			currentPos[1] += 1;
		}
		
		if ((currentPos[0] < 0 || currentPos[1] < 0) || maze[currentPos[0]][currentPos[1]] == 0) {
			return 0;
		}
	}
	
	return 1;
}

