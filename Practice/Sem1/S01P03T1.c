#include <stdio.h>

int is_prime (int);

int main (void) {
	int integer, truth;

	printf("Enter a positive integer: ");
	scanf("%d", &integer);

	truth =	is_prime(integer);

	if (truth == 0)
		printf("%d is not a prime.\n", integer);
	else
		printf("%d is a prime.\n", integer);

	return 0;
}

int is_prime (int prime) {
	int i;
	i = 2;

	if (prime < 2)
		return 0;
	for (i == 2; i < prime; i++) {
		if(prime % i == 0)
			return 0;
	}
	return 1;
}
