//CS1010 Practical Exam 1 Practice
//skipcounting.c
//James Arista Yaputra
//21 September 2017

#include <stdio.h>

int skipCount(int, int, int);
int checkOdd(int);
void printEndPos(int);

int main (void) {
	int lower, upper, startPos;
	
	printf("Enter starting position: ");
	scanf("%d", &startPos);
	
	printf("Enter lower bound and upper bound: ");
	scanf("%d %d", &lower, &upper);
	
	printEndPos(skipCount(startPos, lower, upper));
	
	return 0;
}

int skipCount(int start, int lower, int upper) {
	int endpoint = start;
	
	while (lower <= upper) {
		if (checkOdd(lower) == 0) {
			endpoint++;
		} else {
			endpoint += checkOdd(lower) + 1;
		}
		lower++;
	}

	if (endpoint > 5) {
		endpoint %= 5;
	}
	
	return endpoint;
}

int checkOdd(int num) {
	int count = 0;
	while (num != 0) {
		if ((num % 10) % 2 == 1) {
			count++;
		}
		num /= 10;
	}
	
	return count;
}

void printEndPos(int num) {
	printf("The ending position is %d.", num);
}