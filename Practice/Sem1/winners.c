//CS1010 Practical Exam 1 Practice
//winners.c
//James Arista Yaputra
//22 September 2017

#include <stdio.h>

int countWinner(int, int, int);
int checkWinner(int, int);

int main(void) {
	int factor, mustHave, partNum;
	
	printf("Enter factor-digit: ");
	scanf("%d", &factor);
	
	printf("Enter must-have-digit: ");
	scanf("%d", &mustHave);
	
	printf("Enter number of participants: ");
	scanf("%d", &partNum);
	
	printf("Number of winners: %d", countWinner(factor, partNum, mustHave));
	
	return 0;
}

int countWinner(int factor, int partNum, int mustHave) {
	int mult, result = 0, count = 0;
	
	for (mult = 1; result <= (partNum - factor); mult++) {
		result = factor * mult;
		if (checkWinner(result, mustHave) == 1) {
			count++;
		}
	}
	
	return count;
}

int checkWinner (int value, int mustHave) {
	for ( ; value != 0; value /= 10) {
		if (value % 10 == mustHave) {
			return 1;
		}
	}
	
	return 0;
}