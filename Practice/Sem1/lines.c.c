#include <stdio.h>
#define OVERLAP 0
#define PARALLEL 1
#define INTERSECT 2

double computeK(int, int, int, int);
int determineType(double, double, double);
void printMessage(int);

int main (void) {
	int xofA, yofA, xofB, yofB, xofC, yofC, xofD, yofD;
	
	printf("Enter the coordinates of A: ");
	scanf("%d %d", &xofA, &yofA);
	
	printf("Enter the coordinates of B: ");
	scanf("%d %d", &xofB, &yofB);
	
	printf("Enter the coordinates of C: ");
	scanf("%d %d", &xofC, &yofC);
	
	printf("Enter the coordinates of D: ");
	scanf("%d %d", &xofD, &yofD);
	
	printMessage(determineType(computeK(xofA,yofA,xofB,yofB),
				 computeK(xofC,yofC,xofD,yofD),computeK(xofA,yofA,xofC,yofC)));
	
	return 0;
}

double computeK (int x1, int y1, int x2, int y2) {
	return (double)(y1 - y2) / (x1 - x2);
}

int determineType(double aB, double cD, double aC) {
	if (aB == aC) {
		return OVERLAP;
	} else if (aB == cD) {
		return PARALLEL;
	} else {
		return INTERSECT;
	}
}

void printMessage(int type) {
	printf("The two lines are ");
	if (type == OVERLAP) {
		printf("overlapping.");
	} else if (type == PARALLEL) {
		printf("parallel.");
	} else {
		printf("intersecting.");
	}
}