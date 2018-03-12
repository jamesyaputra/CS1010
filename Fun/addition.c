//addition.c
//Simulates column by column addition

#include <stdio.h>

int add(int, int, int);
int main (void) {
	int n1, n2, carry = 0;

	printf("Enter two positive integers to be added (same length and no leading zeroes): ");
	scanf("%d %d", &n1, &n2);

	printf("Result = %d\n", add(n1, n2, carry));

	return 0;
}

int add(int n1, int n2, int carry) {
	int sum;

	if (n1 > 0) {
		sum = (n1%10 + n2%10 + carry);
		return	sum%10 + 10*(add(n1/10, n2/10, sum/10));
	} else {
		return carry;
	}
}
