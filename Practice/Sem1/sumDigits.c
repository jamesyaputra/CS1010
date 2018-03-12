//sumDigits.c
//recursion practice
#include <stdio.h>
int sumDigits (int);

int main (void) {
	int value;

	printf("Enter a non-negative integer: ");
	scanf("%d", &value);

	printf("Sum of its digits = %d\n", sumDigits(value));

	return 0;
}

int sumDigits (int n) {
	if (n == 0) {
		return 0;
	} else {
		return n%10 + sumDigits(n/10);
	}
}
