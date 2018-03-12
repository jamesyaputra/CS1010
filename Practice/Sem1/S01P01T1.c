/*CS1010 S1P1T1
 *James Arista Yaputra
 */

#include <stdio.h>

int main (void) {
	float timeM, time, temp;
	int timeH;

	printf("Enter  hours and minutes since power failure: ");
	scanf("%d %f", &timeH, &timeM);
	
	time = timeH + (timeM / 60.0);
	
	temp = ((4 * time * time) / (time + 2)) - 20;

	printf("Temperature in freezer = %.2f\n", temp);
	return 0;
}
