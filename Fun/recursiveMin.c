//recursiveMin.c
//Finds the index of the minimum element in an array using recursion

#include <stdio.h>
#include <limits.h>
#define MAX 1000

int get_min (int[MAX], int, int, int, int);

int main (void) {
	int arr[MAX], size, i;
	int index = 0, position = 0, minimum = INT_MAX;

	printf("Enter the size of the array: ");
	scanf("%d", &size);

	printf("Enter the elements of the array: ");
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	printf("Index of the minimum element in the array is %d\n", get_min(arr, size, minimum, position, index));

	return 0;
}

int get_min (int arr[MAX], int size, int minimum, int position, int index) {
	if (position < size) {
		if (arr[position] < minimum)
			return get_min(arr, size, arr[position], position+1, position);
		else
			return get_min(arr, size, minimum, position+1, index);
	} else return index;
}
