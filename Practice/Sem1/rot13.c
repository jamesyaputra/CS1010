//rot.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt (char[81]);
int main (void) {
	int value;
	char str[81];

	printf("Enter 1 for encryption, 2 for decription: ");
	scanf("%d", &value);
	
	printf("Enter message: ");
	scanf("%s", str);
	
	if (value == 1) {
		encrypt(str);
	}
	
	return 0;
}

void encrypt (char message[81]) {
	int len, i;
	char enc[81];
	
	len = strlen(message);
	
	for (i = 0; i < len; i++) {
		if(isupper(message[i])) {
			if (message[i] 
			enc[i] = (message[i]+13)%90 + 65;
		} else {
			enc[i] = (message[i]+13)%122 + 97;
		}
	}

	printf("%s\n", enc);
}
