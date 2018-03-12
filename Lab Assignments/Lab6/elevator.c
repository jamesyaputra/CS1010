/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex3
 * elevator.c
 * This program simulates an elevator system in a building
 * and prints put the final conditions of the simulation
 * James Arista Yaputra
 * C04
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

typedef struct { 
	int floor, passengers, usage;
} elevator_t;

void setupElevator(elevator_t [], int);
void readSequence(char [][MAX_LEN], int);
void runElevator(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);

int main(void){
	int size;
	elevator_t elevators[MAX_ELEVATORS];
	char sequences[MAX_ELEVATORS][MAX_LEN];
	
	printf("Enter number of elevators: ");
	scanf("%d", &size);
	
	setupElevator(elevators, size);
	readSequence(sequences, size);
	
	runElevator(elevators, sequences, size);
	
	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));
	
	return 0;
}

// Sets up all elevators such that they all start at
// 1st floor with 0 passengers and 0 usage
void setupElevator(elevator_t elevators[], int size){
	int i;
	
	for (i = 0; i < size; i++) {
		elevators[i].floor = 1;
		elevators[i].passengers = 0;
		elevators[i].usage = 0;
	}
}	

// Reads in the sequences of floors the elevators go to.
void readSequence(char sequences[][MAX_LEN], int size){
	int i;
	
	for (i = 0; i<size; i++){
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}

// move elevator to a specified floor and calculates the usage of each elevator
void goToFloor(elevator_t *elevator, int floor){
	if ((*elevator).floor < floor) {
		if (((*elevator).passengers + floor) < CAPACITY)
			(*elevator).passengers += floor;
		else
			(*elevator).passengers = CAPACITY;
	} else if ((*elevator).floor > floor) {
		if ((*elevator).passengers < floor) {
			(*elevator).usage += (*elevator).passengers;
			(*elevator).passengers -= (*elevator).passengers;
		} else {
			(*elevator).usage += floor;
			(*elevator).passengers -= floor;
		}
	}
	(*elevator).floor = floor;
}

// Executes the movement of the elevators
void runElevator(elevator_t elevators[], char sequences[][MAX_LEN], int size){
    int i, j;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < strlen(sequences[i]); j++) {
            goToFloor(&elevators[i], sequences[i][j] - '0');
        }
    }
}

// Prints out the results of the final condition of each elevator
void printElevators(elevator_t elevators[], int size){
	int i;
	
	for (i = 0; i < size; i++) {
		printf("Elevator %d:\n", i+1); 
		printf("Floor: %d\n", elevators[i].floor);
		printf("Number of passengers: %d\n", elevators[i].passengers);
		printf("Usage: %d\n", elevators[i].usage);
	}
}

// Compares elevators and returns the elevator with the highest usage
int mostUsedElevator(elevator_t elevators[], int size){
	int i, mostUsedElev, mostUsage = 0, passengers;
	
	for (i = 0; i < size; i++) {
		if (elevators[i].usage > mostUsage) {
			passengers = elevators[i].passengers;
			mostUsage = elevators[i].usage;
			mostUsedElev = i+1;
		} else if (elevators[i].usage == mostUsage) {
			if (elevators[i].passengers > passengers) {
				mostUsage = elevators[i].usage;
				mostUsedElev = i + 1;
				passengers = elevators[i].passengers;
			} else if (elevators[i].passengers == passengers) {
				if (i+1 < mostUsedElev) {
					mostUsage = elevators[i].usage;
					mostUsedElev = i+1;
					passengers = elevators[i].passengers;
				} else {
					continue;
				}
			}
		}
	}
	return mostUsedElev;
}
