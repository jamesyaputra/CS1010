/***************************************************************************
 * CS1010 AY2017/8 Semester 1 Lab4 Ex1
 * nanotable1.c
 
 * This program stores data in the form of student scores and IDs
 * and processes the data according to the command entered by the user.
 * These commands include:
 * help = prints help information
 * insert = allows user to enter student ID and score
 * init = resets the data table
 * sum = calculates total sum of students' scores
 * ave = calculates average of students' scores
 * rank = ranks students by their scores
 * exit = terminates the program
 
 * James Arista Yaputra
 * C04
 ***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define MAX_COMMAND_LENGTH 100

void print_help();
void insert(int [][2], int);
int sum(int [][2], int);
int ave(int [][2], int);

int main(void) {
	char input[MAX_COMMAND_LENGTH];
	int arr[1000][2] = {0}, count = 0, ranking, i;
	
	//Welcome info
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");
	
	//Parses user commands
	while (TRUE) {
		printf("Waiting for command...\n");
		scanf("%s", input);
		
		if (strcmp(input,"help") == 0) {
			print_help();
		} else if (strcmp(input,"exit") == 0){
			printf("See you!\n");
			break;
		} else if (strcmp(input,"sum") == 0) {
			if (count == 0) {
				printf("The table is empty\n");
			} else {
				printf("The sum of score is %d\n", sum(arr, count));
			}
		} else if (strcmp(input,"ave") == 0) {
			if (count == 0) {
				printf("The table is empty\n");
			} else {
				printf("The average of score is %d\n", ave(arr, count));
			}
		} else if (strcmp(input,"insert") == 0) {
			count++;
			insert(arr, count);
		} else if (strcmp(input,"init") == 0) {
			for (i = 0; i < count; i++) {
				arr[i][0] = 0;
				arr[i][1] = 0;
			}
			count = 0;
			printf("Initializing table...\n");
		} else if (strcmp(input,"rank") == 0) {
			if (count == 0) {
				printf("The table is empty\n");
			} else {
				while(TRUE) {
					printf("Please input the rank (1 - %d)...\n", count);
					scanf("%d", &ranking);
					if (ranking > count || ranking < 1) {
						printf("Invalid rank: %d\n", ranking);
					} else {
						printf("ID: %d, Score: %d\n", arr[ranking-1][0], arr[ranking-1][1]);
						break;
					}
				}
			}
		} else {
			printf("No such command: %s, please input command again!\n", input);
		}
	}
	return 0;
}

//This function prints the help information.
void print_help() {
	printf("Commands available: insert, init, sum, ave, rank, help, exit\n");
}

//This function inserts the values inserted by the user and arranges them
//in the array accordingly.
void insert(int arr[][2], int size) {
	int i, j, store[2];
	
	printf("Please input student's ID...\n");
	scanf("%d", &store[0]);
	printf("Please input student's score...\n");
	scanf("%d", &store[1]);
	
	for (i = 0; i < size-1; i++) {
		if (arr[i][1] > store[1]) {
			for (j = size-2; j >= i; j--) {
				arr[j+1][0] = arr[j][0];
				arr[j+1][1] = arr[j][1];
			}
		}
	}
	arr[i][0] = store[0];
	arr[i][1] = store[1];
}

//This function calculates the sum of the students' scores.
//Pre-conds:
//count > 0
int sum(int arr[][2], int count) {
	int sum = 0, i;
	
	for (i = 0; i < count; i++) {
		sum += arr[i][1];
	}
	
	return sum;
}

//This function calculates the average of the students' scores (closest integer).
//Pre-conds:
//count > 0
int ave(int arr[][2], int count) {
	return (sum(arr,count)/(double)(count)) + 0.5;
}
