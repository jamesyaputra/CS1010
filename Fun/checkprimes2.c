//James Arista Yaputra
//Prime Factorization
//checkprimes2.c

#include <stdio.h>
#include <limits.h>

void insertnum();
void primefactor(int);
int checkprime(int);

int main (void) {
        insertnum();
        return 0;
}

void insertnum(void) {
	int num;
	
	printf("Enter an integer: ");
	scanf("%d", &num);
	
	primefactor(num);
}

void primefactor(int num) {
	int i = 2, temp = num, count;
	
	printf("%d = ", num);

	while (num != 1) {
		count = 0;

		if (checkprime(i) == 1 && num%i == 0) {
			if (num < temp)
				printf("* ");
			
			printf("%d^", i);

			while(num%i == 0) {
				num /= i;
				count++;
			}

			printf("%d ", count);
		} else {
			i++;
		}
	}

	printf("\n");
}

int checkprime (int num) {
        int divisor = 2;

	if (num == 2) {
		return 1;
	}

        for (; divisor < num; divisor++) {
                if (num % divisor == 0)
                        return 0;
        }

        return 1;
}
