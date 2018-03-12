/***************************************************************
 *  example2.c
 *  This program prints two values as characters and integers.
 ***************************************************************/

#include <stdio.h>

int main(void) {
	/*  Declare and initialize variables.  */
	char ch = 'a';
	int i = 97;

	/*  Print both values as characters.  */
	printf("value of ch: %c; value of i: %c \n", ch, i);

	/*  Print both values as integers.  */
	printf("value of ch: %d; value of i: %d \n", ch, i);

	return 0;
}
