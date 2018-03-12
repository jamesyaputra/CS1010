/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex1
 * prerequisites.c
 * This program reads a list of module codes, reads the target module,
 * and returns the prerequisites of the module provided that the module
 * and its prerequisites exist within the list.
 * James Arista Yaputra
 * C04
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_MOD  10
#define MAX_LEN  7

int scanModules(char [][MAX_LEN]);
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]);
void printPrereq(char [][MAX_LEN], int, char []);

int main(void) {
	int numModules, numPrereq;
	char codes[MAX_MOD][MAX_LEN], target[MAX_LEN], prerequisites[MAX_MOD][MAX_LEN];

	numModules = scanModules(codes);

	printf("Choose a module: ");
	scanf("%s", target);

	numPrereq = computePrereq(codes, numModules, target, prerequisites);

	printPrereq(prerequisites, numPrereq, target);

	return 0;
}

//Scans the list of modules
//Returns number of modules entered
int scanModules(char codes[MAX_MOD][MAX_LEN]) {
	int numMods, i;

	printf("Enter number of modules: ");
	scanf("%d", &numMods);

	printf("Enter %d modules:\n", numMods);
	for (i = 0; i < numMods; i++) {
		scanf("%s", codes[i]);
	}

	return numMods;
}

//Prints the prerequisites
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[]) {
	int i;

	if (numPrereq == -1) {
		printf("No such module %s\n", target);
	}
	else if (numPrereq == 0) {
		printf("No prerequisites for %s\n", target);
	}
	else {
		printf("Prerequisites for %s:", target);
		for (i = 0; i < numPrereq; i++){
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}

//Computes the prerequites of the target module
//Returns number of prerequisites found
int computePrereq(char codes[][MAX_LEN], int numMods, char target[], char prereq[][MAX_LEN]) {
	int i, j, count = 0;
	int returnValue = -1;
	for (i = 0; i < numMods; i++) {
		if (strcmp(target, codes[i]) == 0) {
			returnValue = 0;
			for (j = 0; j < numMods; j++) {
				if (strncmp(target, codes[j], 2) == 0 && target[2] > codes[j][2] && codes[j][3] <= target[3] && codes[j][4] <= target[4] && codes[j][5] <= target[5]) {
					strcpy(prereq[count], codes[j]);
					count++;
				}
			}
		}
	}
	
	if (count == 0) {
		return returnValue;
	} else {
		return count;
	}
}
