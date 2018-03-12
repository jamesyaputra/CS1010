//checkprime.c
//James Arista Yaputra
//24 September 2017

#include <stdio.h>
#include <time.h>

int checkPrime(int);
void printMessage(int);
void printDiv(int, int);

int main (void) {
	int num = 0;
	time_t start, end;

	//checks validity of user input.
	//will address value to memory only if input is a positive integer.
	do {
		printf("Enter a positive integer: ");
		scanf("%d", &num);
	} while (num <= 0);
	
	start = clock();
	printMessage(checkPrime(num));
	end = clock();
	printf("Timing: %lf\n", ((double)(end-start)/CLOCKS_PER_SEC));
	return 0;
}

//This function performs a primality check using brute force.
int checkPrime (int num) {
	int divisor = 2;
	
	if (num == 1) {
		return 0;
	}
	
	for (; divisor < num; divisor++) {
		if (num % divisor == 0) {
			printDiv(num, divisor);
			return 0;
		}
	}
	
	return 1;
}

//This function prints a message to inform the user
//of the primality of the integer input.
void printMessage(int num) {
	if (num == 1) {
		printf("Integer is a prime.\n");
	} else {
		printf("Integer is not a prime.\n");
	}
}

//This function prints out the integers that when multiplied
//produces the entered number.
void printDiv(int num, int divisor) {
	printf("%d = %d * %d\n", num, divisor, num/divisor);
}
