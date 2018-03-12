#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 21

int isPalindrome(char[], int);
int main (void) {
	char str[MAX];
	int len;

	printf("Enter word: ");	
	scanf("%s", str);
	len = strlen(str);

	if (isPalindrome(str, len) == 1) {
		printf("'%s' is a palindrome.\n", str);
	} else {
		printf("'%s' is not a palindrome.\n", str);
	}
	return 0;
}

int isPalindrome(char str[21], int len) {
	int i;

	for (i = 0; i < len/2; i++) {
		if (toupper(str[i]) != toupper(str[len-1-i])) {
			return 0;
		}
	}
	return 1;
}
