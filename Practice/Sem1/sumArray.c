//sumArray.c
//recursion practice
#include <stdio.h>
#define MAX 10

int sumArray(int arr[], int size);

int main (void) {
	int arr[MAX], numEl, i;
	
	printf("Enter number of elements: ");
	scanf("%d", &numEl);
	
	printf("Enter %d values: ", numEl);
	for (i = 0; i < numEl; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("Array read: ");
	for (i = 0; i < numEl; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\nSum = %d\n", sumArray(arr, numEl-1));
	return 0;
}

int sumArray(int arr[10], int num) {
	if (num >= 0) {
		return arr[num] + sumArray(arr, num-1);
	} else {
		return 0;
	}
}
