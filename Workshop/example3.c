/*****************************************************
 *  example3.c
 *  This program prints the system limitations. 
 *****************************************************/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
	/*  integer type maximums.  */
	printf("short maximum: %d \n", SHRT_MAX);
	printf("int maximum: %d \n", INT_MAX);
	printf("long maximum: %ld \n\n", LONG_MAX);

	/*  float precision, range, maximum.  */
	printf("float precision digits: %d \n", FLT_DIG);
	printf("float maximum exponent: %d \n", FLT_MAX_10_EXP);
	printf("float maximum: %e \n\n", FLT_MAX);

	/*  double precision, range, maximum.  */
	printf("double precision digits: %d \n", DBL_DIG);
	printf("double maximum exponent: %d \n", DBL_MAX_10_EXP);
	printf("double maximum: %e \n\n", DBL_MAX);

	/*  long precision, range, maximum.  */
	printf("long double precision digits: %d \n", LDBL_DIG);
	printf("long double maximum exponent: %d \n", LDBL_MAX_10_EXP);
	printf("long double maximum: %le \n", LDBL_MAX);

	return 0;
}

