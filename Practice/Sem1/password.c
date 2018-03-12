// CS1010 AY2012/3 Semester 1 PE2 Ex1
//
// password.c
// This program checks whether a new password satisfies
// corresponding rules or not.
//
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEN 15

int isValidPassword(char [], char [], char [], char []);

int main(void) {
	char domain[LEN+1], userID[LEN+1], 
		 oldPasswd[LEN+1], newPasswd[LEN+1], confirmPasswd[LEN+1];

	printf("Domain: ");
	scanf("%s", domain);

	printf("UserID: ");
	scanf("%s", userID);

	printf("Old password: ");
	scanf("%s", oldPasswd);

	printf("New password: ");
	scanf("%s", newPasswd);

	printf("Confirm new password: ");
	scanf("%s", confirmPasswd);

	if (isValidPassword(userID, oldPasswd, newPasswd, confirmPasswd) == 1) {
		printf("Password changed successfully!\n");
	} else {
		printf("Error: Invalid userID or password!\n");
	}
	return 0;
}

// Check whether a new password is valid
int isValidPassword(char userID[], char oldPasswd[], char newPasswd[], char confirmPasswd[]) {
	int count = 0;
	int countup = 0, countlow = 0;

	while (newPasswd[count] != '\0') {
		if (!(isalnum(newPasswd[count]) || newPasswd[count] == '_')) {
			return 0;
		}
		if (islower(newPasswd[count])) {
			countlow++;
		}
		if (isupper(newPasswd[count])) {
			countup++;
		}
		count++;
	}

	if (count < 8 || countup == 0 || countlow == 0 || strcmp(newPasswd, oldPasswd) == 0 || strcmp(newPasswd, confirmPasswd) == 1 || strstr(newPasswd, userID) != NULL) {
		return 0;
	}
    
	return 1;	
}
