//gcdlcm.c
//James Arista Yaputra
//29 September 2017
//This programs calculates the gcd and lcm of two given integers
//by using the famous Euclidean algorithm.

#include <stdio.h>

int gcd(int,int);
int lcm(int,int);

int main (void) {
	int num1, num2;
	
	printf("Enter two integers: ");
	scanf("%d %d", &num1, &num2);
	
	printf("gcd(%d,%d) = %d\n", num1, num2, gcd(num1,num2));
	printf("lcm(%d.%d) = %d\n", num1, num2, lcm(num1,num2));
	
	return 0;
}

int gcd (int num1, int num2) {
	int residue;
	
	while (num2 != 0) {
		residue = num1 % num2;
		num1 = num2;
		num2 = residue;
	}
	
	return num1;
}

int lcm (int num1, int num2) {
	return (num1*num2)/gcd(num1,num2);
}
