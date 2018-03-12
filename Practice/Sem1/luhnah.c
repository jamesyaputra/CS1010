//CS1010 Practical Exam Practice
//luhnah.c
//James Arista Yaputra
//21 September 2017

#include <stdio.h>

int luhnAh(int);
int doubleDigit(int);
void printMessage(int checkNum);
void issued(int cardNum);

int main (void) {
	int cardNum, checkNum;
	
	printf("Enter uCard number: ");
	scanf("%d", &cardNum);
	
	checkNum = luhnAh(cardNum);
	
	printMessage(checkNum);
	
	if (checkNum % 7 == 0) {
		issued(cardNum);
	}
	
	return 0;
}

int luhnAh(int num) {
	int sum = 0;
	
	while (num != 0) {
		sum += (num % 10) + doubleDigit((num/10) % 10);
		
		if (num >= 10) {
			num /= 100;
		} else {
			num /= 10;
		}
	}
	
	return sum;
}

int doubleDigit (int num) {
	num *= 2;
	if (num >= 10) {
		return (num % 10) + (num / 10);
	} else {
		return num;
	}
}

void printMessage(int checkNum) {
	printf("The check number is %d\n", checkNum);
	
	if (checkNum % 7 == 0) {
		printf("Valid\n");
	} else {
		printf("Invalid");
	}
}

void issued(int cardNum) {
	while (cardNum / 100 != 0) {
		cardNum /= 10;
	}
	
	printf("Issued by ");
	switch (cardNum) {
		case 31: case 32: case 33: case 34: case 35:
			printf("East Branch");
			break;
		case 51: case 52: case 53: case 54: case 55:
			printf("West Branch");
			break;
		default:
			printf("Central Branch");
	}
}