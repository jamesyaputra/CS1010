#include <stdio.h>

int main (void) {
	int age, count;
	
	printf("Enter age: ", &age);
	scanf("%d", &age);
	
	count = 1;

	while (age < 1 || age > 100) {
		printf("Enter age: ");
		scanf("%d", &age);
		count += 1;
	}

	printf("Your age is %d.\n", age);
	printf("Number of attempts = %d\n", count);

	return 0;
}
