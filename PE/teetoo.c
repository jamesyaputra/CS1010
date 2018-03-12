/********************************************************
 * CS1010 AY2017/8 Semester 1
 * PE1 Ex2: teetoo.c
 * Name: James Arista Yaputra 
 * Student number: A0170761H
 * plab-id: plab0028
 * Discussion group: C04 
 * Description: This program reads an integer of the long long type
 * and returns its seesoo and teetoo values.
 *
 ********************************************************/

#include <stdio.h>

int seesoo(int);
int teetoo(int);

int main(void) {
	int num;

	printf("Enter a positive integer: ");
	scanf("%d", &num);
	printf("%d\n", num);

	printf("%d\n", seesoo(num));
	printf("%d", teetoo(num));
	return 0;
}

/* This function reads the integer entered by the user
 * and returns its seesoo value.
 * Pre-conds:
 * Non-negative integer
 */
int seesoo(int num) {
	int sum = 0, seesoo = 0;
	
	do {
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		
		seesoo += sum % 10;
		sum /= 10;
	} while (sum != 0);
	
	if (seesoo > 9) {
		seesoo = seesoo % 10 + (seesoo/10) % 10;
	}
	
	return seesoo;
}

/* This function reads the integer entered by the user
 * and returns its teetoo value.
 * Pre-conds:
 * Non-negative integer
 */
int teetoo(int num) {
	int numDigits = 0, sum = 0, temp = num;
	
	for (; temp != 0; temp /= 10) {
		numDigits++;
	}
	
	if (numDigits % 4 == 3) {
		sum += (num % 1000);
		num /= 10000;
	} else if (numDigits % 4 == 2) {
		sum += (num % 100);
		num /= 1000;
	} else if (numDigits % 4 == 1) {
		sum += (num % 10);
		num /= 100;
	} else {
		sum += (num/10) % 1000;
		num /= 100000;
	}
	
	while (num != 0) {
		sum += (num % 1000);
		num /= 10000;
	}

	return sum;
}