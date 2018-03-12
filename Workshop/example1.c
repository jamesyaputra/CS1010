/************************************************************
 *  example1.c 
 *  This program computes the distance between two points.
 ************************************************************/

#include <stdio.h>
#include <math.h>

int main(void) {
	/* Declare and initialize variables.       */
	/* x1,y1 are coordinates of 1st point, and */
	/* x2,y2 are coordinates of 2nd point.     */
	double x1=1, y1=5, x2=4, y2=7,
	       side1, side2, distance;

	/*  Compute sides of a right triangle.  */
	side1 = x2 - x1;
	side2 = y2 - y1;
	distance = sqrt(side1*side1 + side2*side2);

	/*  Print distance.  */
	printf("The distance between the two points is %5.2f\n", distance);

	return 0;
}

