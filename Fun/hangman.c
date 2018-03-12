//Project #1
//hangman.c
//James Arista Yaputra

#include <stdio.h>
#include <string.h>

char inputName1();
char inputName2();
void inputString(char, char);

int main (void) {
	char input;
	
	printf("Welcome to Hangman!\n");
	
	while (input != 'a') {
		printf("Enter 'a' to start...\n");
		scanf("%c", &input);
	}
	
	inputString(inputName1(),inputName2());
	
	return 0;
}

char inputName1() {
	char player1[100];
	
	printf("Player 1's name: ");
	scanf("%s", player1);
	
	return player1[];
}

char inputName2() {
	char player2[100];
	
	printf("Player 2's name: ");
	scanf("%s", player2);
	
	return player2[];
}

void inputString(char player1[], char player2[]) {
	char input[100], hint[100];
	
	printf("%s, enter a word %s has to guess (lower-case)...\n", player1, player2);
	scanf("%s", input);
	
	printf("Enter a one-word hint for %s (lower-case)...\n", player2);
	scanf("%s", hint);
	
	printf("%s, %s", input, hint);
}