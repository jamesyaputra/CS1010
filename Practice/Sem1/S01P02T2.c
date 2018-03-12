/*CS1010 Sem-1 AY17/18
 *This program reads two positive integers, each with at most 5 digits, and
 *for each integer, add up the digits (from right) in positions 1, 3 and 5. 
 *The right-most digit of the sum is the required answer (the magic number).
 *James Arista Yaputra
 *C04
 */

#include <stdio.h>

//Function prototype.
int get_magic(int);

//Main function; prompts user for input and diplays results.
int main (void) {
	int value1, value2, magic1, magic2;

	printf("Enter 1st value: ");	//Prompts user to input 1st value.
	scanf("%d", &value1);

	magic1 = get_magic(value1);
	printf("Magic number = %d\n", magic1);

	printf("Enter 2nd value: ");	//Prompts user to input 2nd value.
	scanf("%d", &value2);

	magic2 = get_magic(value2);
	printf("Magic number = %d\n", magic2);

	return 0;
}

//This function computes the magic number for each value entered by the user.
int get_magic (int input) {
	int pos1, pos3, pos5, intermediate, answer;

	pos5 = input % 10;			//Determines the digit in position 5.
	pos3 = (input / 100) % 10;	//Determines the digit in position 3.
	pos1 = (input /10000);		//Determines the digit in position 1.

	intermediate = pos1 + pos3 + pos5;	//Computes the sum of the digits in positions 1, 3, and 5.

	answer = intermediate % 10;	//Determines the right most digit of the sum of the 3 digits.

	return answer;
}
