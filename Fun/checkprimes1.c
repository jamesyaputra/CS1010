#include <stdio.h>
#include <time.h>

void insertnum();
int checkPrime(int);

int main (void) {
	time_t start, end;

	start = clock();
	insertnum();
	end = clock();
	printf("Timing: %lf\n", ((double)(end-start)/CLOCKS_PER_SEC));
	return 0;
}


void insertnum (void) {
	int  i, range, count = 1;
	
	printf("Checks from prime numbers within the range of 2 to ");
	scanf("%d", &range);

	for (i = 2; i <= range ; i++)
		if (checkPrime(i) == 1) {
			printf("%d.\t%d\n", count, i);
			count++;
		}
}

//This function performs a primality check using brute force.
int checkPrime (int num) {
	int divisor = 2;

	for (; divisor < num; divisor++) {
		if (num % divisor == 0)
			return 0;
	}
	
	return 1;
}
