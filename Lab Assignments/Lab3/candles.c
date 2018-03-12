/*CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * This program computes the total number of candles the user can burn
 * by reading the initial number of candles and the number of
 * residual candles needed to roll out a new one.
 * James Arista Yaputra
 * C04
 */

#include <stdio.h>

int count_candles (int, int);

int main(void) {
	int numCandles, numRes, burntCandles;

	//Prompts user to input number of candles and residuals to make a new one.
	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");
	scanf("%d %d", &numCandles, &numRes);

	burntCandles = count_candles(numCandles, numRes);

	printf("Total candles burnt = %d\n", burntCandles);

	return 0;
}

/*This function calculates the number of candles
 *the user is able to burn by reading the
 *initial number of candles and the number of residual
 *candles needed to roll out a new one.
 *The preconditions of the function include:
	 -Number of candles and number of residuals are positive integers.
	 -Number of candles is larger than number of residuals.
 */
int count_candles (int numC, int numR) {
	int countBurnt = 0;

	while (numC >= numR) {
		countBurnt += numR;
		numC = numC - numR + 1;
	}

	return countBurnt + numC;
}
