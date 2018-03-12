//CS1010 Practice Problems (Arrays)
//

#include <stdio.h>

int main (void) {
	int arr[10] = {0}, numCand, numVoters, count, vote, winner, max = -1;
	char print;
	
	printf("Enter number of candidates: ");
	scanf("%d", &numCand);
	
	printf("Enter number of voters: ");
	scanf("%d", &numVoters);
	
	printf("\nVoting starts now...\n");
	
	for (count = 0; count < numVoters; count++) {
		printf("Please submit your vote: ");
		scanf("%d", &vote);
		arr[vote - 1]++;
	}
	
	printf("\nAll votes have been submitted...\n");
	
	for (count = 0; count <numVoters; count++) {
		printf("Candidate %d: %d votes.\n", count + 1, arr[count]);
	}
	
	for (count = 0; count < numVoters; count++) {
		if (arr[count] > max) {
			max = arr[count];
			winner = count + 1;
		}
	}
	
	printf("The winner is candidate %d with %d votes.\n", winner, max);
	
	return 0;
}