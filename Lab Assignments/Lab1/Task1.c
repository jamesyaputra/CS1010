/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex1
 * This program calculates the final amount given principal amount,
 * interest rate, and number of years, based on compound interest.
 * <James Arista Yaputra>
 * <C04>
 */

#include <stdio.h>
#include <math.h>

int main(void) {
	int principal;
	float rate, amount, numYears;

	//Prompts user to input value for principle amount.
	printf("Enter principal amount: ");
	scanf("%d", &principal);

	//Prompts user to input value for interest rate.
	printf("Enter interest rate   : ");
	scanf("%f", &rate);

	//Prompts user to input value for number of years.
	printf("Enter number of years : ");
	scanf("%f", &numYears);

	//The formula used to calculate the final amount.
	amount = principal * (1 - pow((rate/100), numYears + 1)) / (1 - rate / 100);

	printf("Amount = $%.2f\n", amount);
	return 0;
}
