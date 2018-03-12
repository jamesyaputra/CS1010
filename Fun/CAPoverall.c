#include <stdio.h>

int main (void) {
	int overallMC, semMC;
	double cap, semCAP;

	printf("Enter number of MCs taken so far: ");
	scanf("%d", &overallMC);
	
	printf("Current overall CAP: ");
	scanf("%lf", &cap);
	
	printf("Enter number of MCs taken this sem: ");
	scanf("%d", &semMC);
	
	printf("Current semester CAP: ");
	scanf("%lf", &semCAP);
	
	printf("Total CAP = %.2lf\n", (overallMC*cap + semMC*semCAP)/(overallMC + semMC));
	
	return 0;
}
