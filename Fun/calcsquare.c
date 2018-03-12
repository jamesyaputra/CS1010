//calcsquare.c
//James Arista Yaputra
//Determines if a number is the square of an integer.

#include <stdio.h>

int checkSquare(int);

int main (void) {
	int num, flag;
	
	printf("Enter an integer: ");
	scanf("%d", &num);
	
	flag = checkSquare(num);

	if (flag == 0) {
		printf("%d is not a square of any integer\n", num);
	} else {
		printf("%d = %d * %d\n", num, flag, flag);
	}

	return 0;
}

int checkSquare(int num) {
	int i;
	
	for (i = 1; i <= num; i++) {
		if ((float)num/i == i) {
			return i;
		}
			
	}
	
	return 0;
}
