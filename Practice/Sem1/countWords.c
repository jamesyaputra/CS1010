//countWords.c
#include <stdio.h>
#include <ctype.h>

int countWords(char[], int);
int main (void) {
	char string[51];
	int i, count;

	printf("Enter a sentence with at most 50 characters:\n");
	fgets(string, 51, stdin);
	
	for (i = 50; i >= 0; i--) {
		if (string[i] == '\n') {
			break;
		}
	}
	
	count = countWords(string, i+1);	
	printf("Sentence = ");
	puts(string);
	
	printf("Word count = %d\n", count);	
	return 0;
}

int countWords (char string[51], int len) {
	int i = 0, count = 0;
	int j;
	
	while (i < len) {
		if (isalpha(string[i])) {
			j = i + 1;
			while(!isspace(string[j])) {
				j++;
			}
			count++;
			i = j;
		} else {
			i++;
		}	
	}

	return count;
}
