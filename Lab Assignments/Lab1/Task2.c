/*CS1010 AY2017/8 Semester 1 Lab1 Ex2
 * This program calculates the surface area 
 * and the distance between the two furthest vertices of a cuboid
 * by reading its length, width, and height.
 * James Arista Yaputra
 * C04
 */

#include <stdio.h>
#include <math.h>

//Function prototypes.
int compute_surface_area(int, int, int);
double compute_diagonal(double, double, double);

//Main function; prompts user for input and displays results.
int main(void) {
	int length, width, height,		//Variables of the cuboid.
		surfArea;
	double diag;

	//Prompts user to input length.
	printf("Enter length: ");
	scanf("%d", &length);

	//Prompts user to input width.
	printf("Enter width : ");
	scanf("%d", &width);

	//Prompts user to input height.
	printf("Enter height: ");
	scanf("%d", &height);

	//Calls user-defined functions.
	surfArea = compute_surface_area(length, width, height);
	diag = compute_diagonal(length, width, height);

	printf("Surface area = %d\n", surfArea);
	printf("Diagonal = %.2lf\n", diag);
	return 0;
}

//This function calculates the surface area of the cuboid.
int compute_surface_area(int l, int  w, int  h) {
	int sArea;

	sArea = 2 * ((l * h) + (l * w) + (w * h));
	return sArea;
}

//This function calculates the distance between the two furthest vertices of the cuboid.
double compute_diagonal(double l, double w, double h) {
	double diagonal;

	diagonal = pow(sqrt(pow(l, 2) + pow(w, 2)), 2) + pow(h, 2);
	return sqrt(diagonal);
}
