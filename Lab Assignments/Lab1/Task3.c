/*CS1010 AY2017/8 Semester 1 Lab1 Ex3
 * This program calculates the maximum number of slabs that
 * could fit in a tray by reading the widths and the lengths of the tray and slabs
 * provided that the slabs are all oriented the same way.
 * James Arista Yaputra
 * C04
 */

#include <stdio.h>

//Function prototype.
int compute_max_slabs (int, int, int, int);

//Main function; prompts user for input and displays result.
int main(void) {
	int max_slabs;
	int trayL, trayW;		//Variables of the tray.
	int slabL, slabW;		//Variables of the slab.

	//Prompts user to input dimensions of tray.
	printf("Enter dimension of tray: ");
	scanf("%d %d", &trayL, &trayW);

	//Prompts user to input dimensions of slabs.
	printf("Enter dimension of slab: ");
	scanf("%d %d", &slabL, &slabW);

	//Calls user defined function.
	max_slabs = compute_max_slabs (trayL, trayW, slabL, slabW);

	printf("Maximum number of slabs = %d\n", max_slabs);

	return 0;
}

/*This function calculates the number of slabs that
 *could fit in the tray in 2 different orientations
 *and determines which orientation yields the maximum number.
 */
int compute_max_slabs (int ltray, int wtray, int lslab, int wslab) {
	int level1, horizontal1, answer1,
		level2, horizontal2, answer2, answerfinal;

	level1 = wtray / lslab;
	horizontal1 = ltray / wslab;
	answer1 = level1 * horizontal1;

	level2 = wtray / wslab;
	horizontal2 = ltray / lslab;
	answer2 = level2 * horizontal2;

	if (answer1 > answer2) {
		answerfinal = answer1;
	}
	else {
		answerfinal = answer2;
	}

	return answerfinal;
}
