//gcdlcmn2.c
//James Arista Yaputra
//29 September 2017
//This programs calculates the gcd and lcm of three given integers
//by using the famous Euclidean algorithm.

#include <stdio.h>

int gcd(int,int,int);
int lcm(int,int,int);

int main (void) {
	int num1, num2, num3;
	
	printf("Enter three integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);
	
	printf("gcd(%d,%d,%d) = %d\n", num1, num2, num3, gcd(num1,num2,num3));
	printf("lcm(%d,%d,%d) = %d\n", num1, num2, num3, lcm(num1,num2,num3));
	
	return 0;
}

int gcd (int num1, int num2, int num3) {
	int residue;
	
	while (num2 != 0) {
		residue = num1 % num2;
		num1 = num2;
		num2 = residue;
	}
	
	while (num3 != 0) {
		residue = num1 % num3;
		num1 = num3;
		num3 = residue;
	}
	
	return num1;
}

int lcm (int num1, int num2, int num3) {
	return (num1*num2*num3)/gcd(num1,num2,num3);
}
