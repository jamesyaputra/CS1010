/*CS1010 Sem-1 AY17/18 Lab2 Nanotable(1)
 *nanotable.c
 *This program parses commands from the user and takes
 *actions accordingly.
 *User is able to use 4 commands, which include:
 -help	: Displays commands user is able to use.
 -sum	: Calculates the sum of all the integers
		  the user enters.
 -ave	: Calculates the average of all the integers
		  the user enters.
 -exit	: Terminates the program.
 *James Arista Yaputra
 *C04
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INIT 4
#define COMMAND_INSERT 5
#define COMMAND_RANK 6
#define COMMAND_INVALID 7

int parse_command();

int check_command(char* input);

void table(int);

int main() {
	int command;

	//Prints welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	do {
		command = parse_command();
	} while (command != COMMAND_EXIT);

	return 0;
}


/*This function parses commands entered by the user
 *and passes control to the necessary function(s).
 *Commands include:
 -help
 -sum
 -ave
 -exit
 */
int parse_command() {
	char tmp_command[100] = "";
	int command_code, count = 0;

	printf("Waiting for command...\n");
	scanf("%s", tmp_command);

	command_code = check_command(tmp_command);    

	if (command_code == COMMAND_HELP) {
		print_help();
	} else if (command_code == COMMAND_EXIT) {
		printf("See you!\n");
		return COMMAND_EXIT;
	} else if (command_code == COMMAND_SUM) {
		
	} else if (command_code == COMMAND_AVE) {
		
	} else if (command_code == COMMAND_INIT) {
		
	} else if (command_code == COMMMAND_INSERT) {
		table(command_code, count);
		count++;
	} else if (command_code == COMMAND_RANK) {
		
	} else {
		// others
		printf("No such command: %s, please input command again!\n", tmp_command);
	}
	return 0;
}

void table(int command, int count) {
	int arr[][2];
	int count1, count2;
	
	if (command == COMMAND_INSERT) {
		printf("Please input the student's ID...\n");
		scanf("%d", arr[count][0]);
		printf("Please input the student's score...\n");
		scanf("%d", arr[count][1]);
	} else if (command == COMMAND_INIT) {
		for (count1 = 0; count1 < count; count1++) {
			for (count2 = 0; count2 < 2; count2++) {
				arr[count1][count2] = 0;
			}
		}
	} else if (command == COMMAND_SUM) {
		sum(arr, count);
	} else if (command == COMMAND_AVE) {
		ave(arr, count);
	}
	
//This function takes a command as input and returns an integer as output.
/*INPUT    OUTPUT
  help     0
  exit     1
  sum      2
  ave      3
  init     4
  insert   5
  rank     6
  others   7
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	} else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	} else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;      
	} else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	} else if (strcmp(input,"init") == 0) {
		return COMMAND_INIT;
	} else if (strcmp(input,"insert") == 0) {
		return COMMAND_INSERT;
	} else if )strcmp(input,"rank") == 0) {
		return COMMAND_RANK;
	} else {
		return COMMAND_INVALID;
	}
}


//This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}
