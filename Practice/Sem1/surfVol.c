//surfVol.c
#include<stdio.h>

void areaVolume (int*, int*, int*);

int main (void) {
	int lower, upper, answer = 0;
	
	printf("Enter lower and upper limits: ");
	scanf("%d %d", &lower, &upper);
	
	areaVolume(&lower, &upper, &answer);
	
	printf("Answer = %d\n", answer);
	return 0;
}

void areaVolume(int *low, int *up, int *ans) {
	int p = *ans;
	int i, j, k;
	
	for (i = *low; i <= *up; i++) {
		for (j = *low; j <= *up; j++) {
			if (i*i*j <= 2*(i*i + i*j + i*j)) {
				p++;
			}
		}
	}
	
	for (i = *low; i <= *up; i++) {
		for (j = i+1; j <= *up; j++) {
			for (k = j+1; k <= *up; k++) {
				if (i*j*k <= 2*(i*k + i*j + k*j)) {
				p++;
				}
			}
		}
	}
	*ans = p;
}