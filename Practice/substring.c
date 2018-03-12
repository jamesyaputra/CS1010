#include <stdio.h>
#include <string.h>

int substring(char[]);

int main (void) {
	char str[100];
	
	printf("Enter string: ");
	scanf("%s", str);
	printf("Period = %d\n", substring(str));
	
	return 0;
}

int substring(char str[]) {
	int i, j, len, count;
	char substr[100];

	len = strlen(str);
	for (i = 1; i <= len/2; i++) {
		strncpy(substr, str, i);
		count = 0;
		for (j = 0; j < len; j += i) {
			if (strncmp(substr, str+j, i) != 0) break;
			count++;
		}
		if (count == len/i) return i;
	}
	return len;
}
