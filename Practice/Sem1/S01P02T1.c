/*CS1010 Sem-1 AY17/18
 *This program calculates the speed of sound in air
 *by reading the temperature in Fahrenheit.
 *James Arista Yaputra
 *C04
 */

#include <stdio.h>
#include <math.h>

//Function prototype.
float speed_Sound(float);

//Main function; prompts user for input and displays result.
int main (void) {
	float temp, speed;

	//Prompts user to input temperature in degree Fahrenheit.
	printf("Temperature in degree Fahrenheit: ");
	scanf("%f", &temp);

	speed = speed_Sound(temp);

	printf("Speed of sound in air of %.2f degree = %.2f ft/sec\n", temp, speed);

	return 0;
}

/*This function calculates the speed of sound by reading
 *the temperature of the air in degree Fahrenheit
 *and returns the result to the main function.
 */
float speed_Sound (float fahren) {
	float speed_ofSound;

	speed_ofSound = 1086 * sqrt((5 * fahren + 297) / 247);

	return speed_ofSound;
}
