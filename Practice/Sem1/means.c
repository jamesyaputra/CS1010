//means.c
# include <stdio.h>
# include <math.h>

void compute_AM_GM(int [], float*, float*);

int main (void) {
	int arr[3], i;
	float arith, geo;
	
	printf("Enter 3 positive integers: ");
	for (i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
	}

	compute_AM_GM(arr, &arith, &geo);
	
	printf("Arithmetic mean = %.2f\n", arith);
	printf("Geometric mean = %.2f\n", geo);
	
	return 0;
}

void compute_AM_GM(int arr[3], float *arith, float *geo) {
	float am, gm;

	am = (float) (arr[0] + arr[1] + arr[2])/3;
	gm = pow((float)(arr[0]*arr[1]*arr[2]),((float)1/3));
	
	*arith = am;
	*geo = gm;
}
