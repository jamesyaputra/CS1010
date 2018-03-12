#include <stdio.h>

char generateCode (int);

int main (void) {
	int seven_digits;
	char checkCode;

	printf("Enter 7-digit NRIC number: ");
	scanf("%d", &seven_digits);

	checkCode = generateCode(seven_digits);

	printf("Check code is %c\n", checkCode);

	return 0;
}

char generateCode (int code) {
	int weight;

	weight = (code / 1000000)*2 + ((code / 100000)%10)*7 +
			 ((code / 10000)%10)*6 + ((code / 1000)%10)*5 +
			 ((code / 100)%10)*4 + ((code / 10)%10)*3 + (code %10)*2;

	switch (11 - (weight % 11)) {
		case 1:
			return 'A';
			break;
		case 2:
			return 'B';
			break;
		case 3:
			return 'C';
			break;
		case 4:
			return 'D';
			break;
		case 5:
			return 'E';
			break;
		case 6:
			return 'F';
			break;
		case 7:
			return 'G';
			break;
		case 8:
			return 'H';
			break;
		case 9:
			return 'I';
			break;
		case 10:
			return 'Z';
			break;
		case 11:
			return 'J';
			break;
	}
}
