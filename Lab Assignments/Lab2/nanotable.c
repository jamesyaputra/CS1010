/*CS1010 Sem-1 AY17/18 Lab2 Nanotable(0)
 *nanotable.c
 *This program parses commands from the user and takes
 *actions accordingly.
 *User is able to use 4 commands, which include:
 -help	: Displays commands user is able to use.
 -sum	: Calculates the sum of all the integers
 the user enters.
 -ave	: Calculates the average of all the integers
 the user ebters.
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
#define COMMAND_INVALID 4

int parse_command();

int check_command(char* input);

void print_help();

int simple_sum();

int simple_average();


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
	int command_code;

	printf("Waiting for command...\n");
	scanf("%s", tmp_command);

	command_code = check_command(tmp_command);    

	if (command_code == COMMAND_HELP) {
		print_help();
	} else if (command_code == COMMAND_EXIT) {
		printf("See you!\n");
		return COMMAND_EXIT;
	} else if (command_code == COMMAND_SUM) {
		printf("sum is %d\n", simple_sum());
	} else if (command_code == COMMAND_AVE) {
		printf("average is %d\n", simple_average());
	} else {
		// others
		printf("No such command: %s, please input command again!\n", tmp_command);
	}
	return 0;
}

int sum (int numInt) {
	int count, temp, mod, sum = 0;
	
	for (count = 1; count <= numInt; count++) {
		printf("Please input the %d", count);

		mod = count % 10;

		if (count == 11 || count == 12 || count == 13) {
			printf("th number:\n");
		} else if (mod == 1) {
			printf("st number:\n");
		} else if (mod == 2) {
			printf("nd number:\n");
		} else if (mod == 3) {
			printf("rd number:\n");
		} else {
			printf("th number:\n");
		}
		scanf("%d", &temp);
		sum += temp;
	}
	return sum;
}
	
/*This function calculates the sum of all
 *the integers entered by the user.
 */
int simple_sum() {
	int numInt;

	printf("Please indicate the number of integers:\n");
	scanf("%d", &numInt);
	
	return sum(numInt);
}

/*This function calculates the average of all the
 *integers entered by the user.
 */
int simple_average() {
	int numInt;

	printf("Please indicate the number of integers:\n");
	scanf("%d", &numInt);
	
	return ((double)sum(numInt) / numInt) + 0.5;
}

//This function takes a command as input and returns an integer as output.
/*INPUT    OUTPUT
  help     0
  EXIT     1
  SUM      2
  AVE      3
  others   4
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;      
	}
	else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	}
	else {
		return COMMAND_INVALID;
	}
}


//This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}
