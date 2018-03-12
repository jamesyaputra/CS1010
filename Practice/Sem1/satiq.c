// CS1010 AY2012/3 Semester 1
// PE1 Ex1: sat.c
// Name: James Arista Yaputra
// Matriculation number: A0170761H
// plab account-id:
// Discussion group: C04
// Description:

#include <stdio.h>

double computeIQ(int, int, int);
int computePercentile(int, int, int);
void amazing(int, int, int, double);

int main(void) {
	int verbal, maths, writing, // user’s input
		percentile;
	double iQ;
	
	printf("Enter scores: ");
	scanf("%d %d %d", &verbal, &maths, &writing);
	
	iQ = computeIQ(verbal, maths, writing);
	percentile = computePercentile(verbal, maths, writing);
	
	printf("The SAT score is in the %d percentile.\n", percentile);
	printf("The IQ score is %.2lf\n", iQ);
	
	amazing(verbal, maths, writing, iQ);
	
	return 0;
}

double computeIQ(int verbal, int maths, int writing) {
	return (0.095 * maths) + (0.003 * verbal) + 50.241;
}

int computePercentile(int verbal, int maths, int writing) {
	int total;
	
	total = verbal + maths + writing;
	
	if (total >= 2200) {
		return 99;
	} else if (total >= 2000) {
		return 95;
	} else if (total >= 1500) {
		return 50;
	} else {
		return 10;
	}
}

void amazing(int verbal, int maths, int writing, double iQ) {
	if ((verbal > 600 && maths > 600 && writing > 600) || iQ >= 120) {
		printf("Wow, this is amazing!");
	}
}