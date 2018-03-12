/* CS1010 AY2017/8 Semester 1 Lab3 Ex2
 * square_free.c
 * James Arista Yaputra
 * C04
 * This program computes the number of square-free integers
 * within 2 ranges of positive integers and determines which
 * range has more square-free integers or if they have
 * the same amount.
 */

#include <stdio.h>

int compute_freeSq (int, int);
int checkSq (int);

int main(void) {
	int lower1, upper1, lower2, upper2,	//Lower and upper values of the two ranges.
		numRange1, numRange2;			//Number of square-free integers in each range.

	//Prompts user to input values.
	printf("Enter four positive integers: ");
	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);

	//Calls user-defined function.
	numRange1 = compute_freeSq(lower1, upper1);
	numRange2 = compute_freeSq(lower2, upper2);

	//Determines which range has more square-free integers or if they have the same number.
	if (numRange1 > numRange2) {
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower1, upper1, numRange1);
	} else if (numRange2 > numRange1) {
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower2, upper2, numRange2);
	}else {
		printf("Both ranges have the same number of square-free numbers: %d\n", numRange1);
	}

	return 0;
}

/*This function counts the number of square-free integers
 *within the given range of integers.
 */
int compute_freeSq (int lower, int upper) {
	int count = 0;

	for (lower; lower <= upper; lower++) {
		if (lower < 4) {
			count += 1;
		} else if (checkSq(lower) == 1) {	//Passes control to next function.
			count += 1;
		}
	}
	return count;
}


/*This function checks whether an integer is square free
 *and returns the result to the previous function.
 *return 1 = integer is square-free
 *return 0 = integer is not square-free
 */
int checkSq (int value) {
	int divisor = 2;

	while ((divisor*divisor) <= value) {
		switch (value % (divisor*divisor)) {
			case 0:
				return 0;
				break;
			default:
				divisor += 1;
		}
	}

	return 1;
}
