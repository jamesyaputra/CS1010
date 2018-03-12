/***********************************************************
 * CS1010 AY2017/8 Semester 1 Lab4 Ex2
 * subsequence.c
 
 * This program reads in a list of integers and finds the
 * k-interval subsequence with the largest sum.
 
 * James Arista Yaputra
 * C04
 **********************************************************/

#include <stdio.h>
#include <limits.h>

int scan_list(int []);
void sum_subsequence(int [], int, int []);

int main(void) {
	int list[10], size;		// array and number of elements entered
	int answers[3] = {0};	// stores the required answers
	
	size = scan_list(list); 
	sum_subsequence(list, size, answers);
	
	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
			answers[0], answers[1], answers[2]);
	
	return 0;
}

// Reads elements for the array 
// and returns the number of elements read.
// post-conds:
// i > 0
int scan_list(int arr[]) {
	int num, i;

	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num>1)?"s":"");
	for (i=0; i<num; i++) {
		scanf("%d", &arr[i]);
	}

	return num;
}

// Calculates the sum of each k-interval
// subsequence at each starting position and prints out
// the info of the subsequence with the largest sum.
// pre-conds:
// size > 0
// ans[0] = maximum sum of solution subsequence
// ans[1] = interval k of the solution subsequence
// ans[2] = start position of the solution subsequence
void sum_subsequence(int arr[], int size, int ans[]) {
	int sum, i, j, k, min = INT_MIN; 

	//First for-loop is for (k >= 1)-interval
	for (k = 1; k <= size; k++) {
		//Second for-loop is for starting position
		for (j = 0; j < k; j++) {
			sum = 0;
			//Third for-loop is for summation
			for (i = 0; j + k*i < size; i++) {
				sum += arr[j + (k*i)];
			}
			if (sum > min) {
				min = sum;
				ans[0] = sum;
				ans[1] = k;
				ans[2] = j;
			}
		}
	}
}
