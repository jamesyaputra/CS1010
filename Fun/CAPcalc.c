//CAPcalc.c
//James Arista Yaputra
//This program calculates the Cumulative Average Points
//of the user by reading the number of Modular Credits
//taken and the corresponding grade values received

#include <stdio.h>
#define MAX_MODS 8

typedef struct {
	char moduleName[7];
	int modularCreds;
	double grade;
} info_t;

void scanMods(info_t[MAX_MODS], int);
double computeCAP(info_t[MAX_MODS], int, int*);
void suMods(info_t[MAX_MODS], int, double);
void print(double, info_t[MAX_MODS], int, int);

int main (void) {
	int size, totalMC = 0;
	info_t studentInfo[MAX_MODS];
	double suCAP;

	printf("******** CAP CALCULATOR ********\nEnter number of modules taken this semester: ");
	scanf("%d", &size);
	
	printf("Enter S/U threshold: ");
	scanf("%lf", &suCAP);

	scanMods(studentInfo, size);
	print(computeCAP(studentInfo, size, &totalMC), studentInfo, size, totalMC);
	suMods(studentInfo, size, suCAP);

	return 0;
}

void scanMods(info_t studentInfo[], int size) {
	int i;
	
	for (i = 0; i < size; i++) {
		printf("\nEnter code for module %d: ", i+1);
		scanf("%s", studentInfo[i].moduleName);

		printf("Enter MCs for %s: ", studentInfo[i].moduleName);
		scanf("%d", &studentInfo[i].modularCreds);

		printf("Enter grade for %s: ", studentInfo[i].moduleName);
		scanf("%lf", &studentInfo[i].grade);
	}
}

double computeCAP(info_t studentInfo[],int size, int *totalMC) {
	int i;
	double totalCAP = 0;
	
	for (i = 0; i < size; i++) {
		*totalMC += studentInfo[i].modularCreds;
	}
	
	for (i = 0; i < size; i++) {
		totalCAP += studentInfo[i].modularCreds * studentInfo[i].grade;
	}

	return totalCAP / *totalMC;
}

void suMods(info_t studentInfo[], int size, double suCAP) {
	int i, totalMC = 0;
	double totalCAP = 0;
	
	printf("\nMods to S/U:\n");
	for (i = 0; i < size; i++) {
		if (studentInfo[i].grade < suCAP) {
			puts(studentInfo[i].moduleName);
		} else {
			totalMC += studentInfo[i].modularCreds;
			totalCAP += studentInfo[i].grade * studentInfo[i].modularCreds;
		}
	}

	printf("\nTotal non-S/U MCs = %d\n", totalMC);
	printf("Final CAP after S/U = %.2lf\n", totalCAP/totalMC);
}

void print(double finalGrade, info_t studentInfo[], int size, int totalMC) {
	int i;
	
	printf("\nModules taken:\n");
	for (i = 0; i < size; i++) {
		puts(studentInfo[i].moduleName);
	}

	printf("\nTotal MCs = %d\n", totalMC);
	printf("Final CAP = %.2lf\n", finalGrade);
}
