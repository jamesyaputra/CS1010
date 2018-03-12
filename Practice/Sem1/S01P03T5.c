#include <stdio.h>

int count_numbers (int, int ,int , int);

int main (void) {
	int div1, div2, lim1, lim2, count;
	
	div1 = div2 = lim1 = lim2 = 0;
	
	do {
		printf("Enter 2 divisors: ");
		scanf("%d %d", &div1, &div2);
	} while (div1 == div2 || (div1 <= 0 || div2 <= 0));
	
	do {
		printf("Enter lower and upper limits: ");
		scanf("%d %d", &lim1, &lim2);
	} while ((lim1 >= lim2) || (lim1 <= 0 || lim2 <= 0));
	
	count = count_numbers(div1, div2, lim1, lim2);
	
	printf("Answer = %d\n", count);
	
	return 0;
}

int count_numbers (int div1, int div2, int lim1, int lim2) {
	int count = 0;
	
	for (lim1; lim1 <= lim2; lim1++) {
		if((lim1 % div1 != 0) && (lim1 % div2 != 0)) {
			count += 1;
		}
	}
	
	return count;
}
