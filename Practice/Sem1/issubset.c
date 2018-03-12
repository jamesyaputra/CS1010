//CS1010 Practice on Arrays
//issubset.c
//26 September 2017

#include <stdio.h>

int isSubset(int[], int[], int);
void printMessage(int[], int[], int, int);

int main (void) {
	int arrA[4], arrB[7];
	
	printf("1st array:\nEnter 4 values: ");
	scanf("%d %d %d %d", &arrA[0], &arrA[1], &arrA[2], &arrA[3]);
	
	printf("2nd array:\nEnter 7 values: ");
	scanf("%d %d %d %d %d %d %d", &arrB[0], &arrB[1], &arrB[2], &arrB[3], &arrB[4], &arrB[5], &arrB[6]);
	
	printMessage(arrA, arrB, 7, isSubset(arrA, arrB, 7));
	printMessage(arrA, arrB, 6, isSubset(arrA, arrB, 6));
	
	return 0;
}

int isSubset (int arrA[], int arrB[], int size) {
	int count, count1, check[4] = {0};
	
	for (count = 0; count < size; count++) {
		for(count1 = 0; count1 < 4; count1++) {
			if (arrB[count] == arrA[count1]) {
				check[count1] = 1;
				break;
			}
		}
	}
	
	for (count = 0; count < 4; count++) {
		if (check[count] == 0) {
			return 0;
		}
	}
	
	return 1;
}

void printMessage(int arrA[], int arrB[], int size, int check) {
	printf("arrayA[0..3] is ");
	
	if (check == 1) {
		printf("a subset of ");
	} else {
		printf("not a subset of ");
	}
	
	printf("arrayB[");
	
	if (size ==7) {
		printf("0..6]\n");
	} else {
		printf("0..5]\n");
	}
}