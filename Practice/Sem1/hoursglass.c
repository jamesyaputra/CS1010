//hourglass.c
//17/10/17

#include <stdio.h>

int computeflips(int, int, int, int*, int*);

int main (void) {
	int a, b, c, boolean;
	int aflip, bflip;

	printf("Enter 3 inputs: ");
	scanf("%d %d %d", &a, &b, &c);

	boolean = computeflips(a, b, c, &aflip, &bflip);

	if (boolean == 1) {
		printf("Possible!\n");
		printf("%d flip(s) for %d-minute hourglass and %d flip(s) for %d-minute hourglass.\n", aflip, a, bflip, b);
	} else {
		printf("Impossible!\n");
	}

	return 0;
}

int computeflips(int a, int b, int c, int *aflip, int *bflip) {
	int i, j;

	for (i = 0; i*a <= c; i++) {
		for (j = 0; i*a + j*b <= c; j++) {
			if (i*a + j*b == c && !(a == 0 && b == 0)) {
				*bflip = j;
				*aflip = i;
				return 1;
			}
		}
	}
	return 0;	
}
