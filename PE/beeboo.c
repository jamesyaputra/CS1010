/********************************************************
 * CS1010 AY2017/8 Semester 1
 * PE1 Ex1: beeboo.c
 * Name: James Arista Yaputra
 * Student number: A0170761H
 * plab-id: plab0028
 * Discussion group: C04 
 * Description: This program reads an integer from the user and determines its beeboo value and
 * its beeboo code.
 *
 ********************************************************/

#include <stdio.h>

int firstLast(int);
char printCheck(int);

int main(void) {
	int num, beeboo;

	printf("Enter a positive integer: ");
	scanf("%d", &num);

	printf("%d\n", num);
	
	beeboo = firstLast(num);

	printf("%d\n", beeboo);
	printf("%c\n", printCheck(beeboo));
	return 0;
}

/* This function reads the integer input by the user,
 * determines the first and last digits of the integer,
 * and returns its beeboo value.
 * Pre-cond:
 * Value has to be a positive integer.
 */
int firstLast(int num) {
	int last, count = 1;

	last = num % 10;

	while (num >= 10) {
		num /= 10;
		count++;
	}

	return (num * num + last * last) * count;
}

/* This function checks the last digit of the beeboo
 * value and returns the beeboo code.
 * Pre-cond:
 * Value has to be an integer.
 */
char printCheck(int beeboo) {
	switch (beeboo % 10) {
		case 0:
			return 'C';
		case 1:
			return 'D';
		case 2:
			return 'E';
		case 3:
			return 'F';
		case 4:
			return 'G';
		case 5: 
			return 'H';
		case 6:
			return 'I';
		case 7:
			return 'J';
		case 8:
			return 'K';
		default:
			return 'L';
	}
}
