// CS1010 AY2016/7 Semester 1
// PE1 Ex1: collatz.c
// Name: James Arista Yaputra
// Matriculation number: A0170761H
// plab account-id:
// Discussion group: C04
// Description:

#include <stdio.h>

void collatzSequence(int, int);
void printDiv(int);
void printMult(int);

int main(void) {
	int n, count;
	
	printf("Enter positive numbers for n and count: ");
	scanf("%d %d", &n, &count);
	
	printf("The collatz sequence is: ");
	collatzSequence(n, count);
	
	return 0;
}

void collatzSequence(int n, int count) {
	int count1, divBy2 = 0, mult3 = 0;
	
	for (count1 = 1; count1 <= count; count1++) {
		if (n == 1) {
			break;
		} else {
			if (n % 2 ==0) {
				n = n / 2;
				divBy2++;
			} else {
				n = n * 3 + 1;
				mult3++;
			}
		}
		printf("%d ", n);
	}
	
	printDiv(divBy2);
	printMult(mult3);
}

void printDiv(int num) {
	printf("\nThe division statement has been executed %d times.\n", num);
}

void printMult(int num) {
	printf("The multiplication statement has been executed %d times.", num);
}