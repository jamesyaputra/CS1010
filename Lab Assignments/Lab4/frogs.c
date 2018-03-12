/* CS1010 AY2017/8 Semester 1 Lab4 Ex3
 * frogs.c
 * 
 * This program is a console line game where the player
 * attempts to move frogs from one side to the other.
 *
 * James Arista Yaputra
 * C04
 */
#include <stdio.h>

void input(int[], int);
int jump(int, int, int[], int);
void printBridge(int, int[]);
int checkGameState(int[], int);
void swap(int, int, int[]);
int isValid(int[], int, int);

int main(void) {

	int bridge[1000];
	int lengthBridge, position, temp, gameState, numberMoves = 0;

	printf("Please enter the length of the bridge: ");
	scanf("%d", &lengthBridge);
	
	input(bridge, lengthBridge);
	
	printf("Input completed\n");
	printBridge(lengthBridge, bridge);
	printf("Please start moving the frogs\n");
	
	//Prompts the user to move the frogs until game ends.
	do {
		printf("Move the frog at position: ");
		scanf("%d", &position);
		temp = numberMoves;
		numberMoves = jump(position, lengthBridge, bridge, numberMoves);
		if ((temp + 1) == numberMoves) {
			printBridge(lengthBridge, bridge);
		}
	} while (checkGameState(bridge, lengthBridge) == 0);
	
	gameState = checkGameState(bridge, lengthBridge);
	
	if (gameState == 1) {
		// WIN
		printf("Congratulations! The frogs took %d jumps to cross the bridge!\n", numberMoves);
	} else if (gameState == -1) {
		// LOSE
		printf("Oh no! It seems like the two clans of frogs are stuck!\n");
	}
		
	return 0;
}

/* Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 */
void printBridge(int size, int arr[]) {
	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

//Prompts user to input frogs to certain positions.
void input(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &arr[i]);
	}
}

//Moves the frogs
int jump(int posFrog, int size, int bridge[], int moveCount) {
	moveCount++;
	if (bridge[posFrog] == 1) {
		if (posFrog + 1 < size && bridge[posFrog+1] == 0) {
			swap(posFrog,posFrog+1,bridge);
		} else if (posFrog + 2 < size && bridge[posFrog+1] != 0
				&& bridge[posFrog+2] == 0)  {
			swap(posFrog,posFrog+2,bridge);
		} else {
			printf("Invalid move!\n");
			moveCount--;
		}
	} else if (bridge[posFrog] == -1) {
		if (bridge[posFrog-1] == 0 && posFrog - 1 >= 0) {
			swap(posFrog-1,posFrog,bridge);
		} else if (bridge[posFrog-2] == 0 && posFrog - 2 >= 0 && bridge[posFrog-1] != 0) {
			swap(posFrog-2,posFrog,bridge);
		} else {
			printf("Invalid move!\n");
			moveCount--;
		}
	} else {
		printf("Invalid move!\n");
		moveCount--;
	}
	return moveCount;
}

//Performs swaps
void swap(int pos1, int pos2, int arr[]) {
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

//Checks whether the move is valid
int isValid(int arr[], int size, int position) {
	if (arr[position] == 1) {
		if (position + 1 >= size || arr[position+1] != 0) {
			if (position + 2 >= size || arr[position+2] != 0)  {
				return 0;
			}
		}
	} else if (arr[position] == -1) {
		if (arr[position-1] != 0 || position - 1 < 0) {
		  if (arr[position-2] != 0 || position - 2 < 0) {
			return 0;
			}
		}
	}
		
	return 1;
}

//Checks the state of the game.
int checkGameState(int arr[], int size) {
	int i, count = 0;
	
	for (i = 0; i < size; i++) {
		if (isValid(arr, size, i) == 0) {
			 count++;
		}
	}
	
	if (count == size-1) {
		for (i = 0; i < size-1; i++) {
			if (arr[i] > arr[i+1]) {
				return -1; // LOSE
			}
		}
		return 1; // WIN
	}
	
	return 0; //CONTINUE
}