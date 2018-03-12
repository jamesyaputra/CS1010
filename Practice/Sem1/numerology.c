//CS1010 Practical Exam Practice
//numerology.c
//James Arista Yaputra
//21 September 2017

#include <stdio.h>
#include <math.h>

int multiply2digit(int);
void getAdvicePos(int);
void getAdviceNeg(int);

int main (void) {
	int integer;
	
	printf("Enter a non-zero integer: ");
	scanf("%d", &integer);
	
	if (integer > 0) {
		getAdvicePos(multiply2digit(integer));
	} else {
		getAdviceNeg(multiply2digit(integer));
	}
	
	return 0;
}

int multiply2digit(int num) {
	int mult, temp;
	
	num = fabs(num);
	
	for ( ; num >= 10; num = mult) {
		mult = 1;
		temp = num;
		while (temp / 10 != 0) {
			mult *= temp % 10;
			temp /= 10;
		}
	}
	
	return num;
}

void getAdvicePos(int num) {
	switch (num) {
		case 0: case 3: case 7: case 9:
			printf("You should protect life.");
			break;
		case 2: case 5: case 8:
			printf("Share your wealth, donate generously.");
			break;
		default:
			printf("Build harmony, bring people together.");
			break;
	}
}

void getAdviceNeg(int num) {
		switch (num) {
		case 0: case 3: case 7: case 9:
			printf("Speak honestly.");
			break;
		case 2: case 5: case 8:
			printf("Praise others' successes.");
			break;
		default:
			printf("Lend your hand to those who are in need.");
			break;
	}
}