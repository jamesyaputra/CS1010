
//incenter.c

#include <stdio.h>
#include <math.h>

void incenter(float, float, float, float, float, float, float*, float*);

int main (void) {
	float x1, x2, x3;
	float y1, y2, y3;
	float centerx, centery;

	printf("Coordinates of 1st vertex: ");
	scanf("%f %f", &x1, &y1);
	
	printf("Coordinates of 2nd vertex: ");
	scanf("%f %f", &x2, &y2);

	printf("Coordinates of 3rd vertex: ");
	scanf("%f %f", &x3, &y3);

	incenter(x1, x2, x3, y1, y2, y3, &centerx, &centery);
	
	printf("Coordinates of incenter = (%.2f, %.2f)\n", centerx, centery);
	return 0;
}

float distance (float xa, float xb, float ya, float yb) {
	return sqrt(pow((xb-xa),2) + pow((yb-ya),2));
}

void incenter(float x1, float x2, float x3, float y1, float y2, float y3, float *centerx, float *centery) {
	float distance1, distance2, distance3, perimeter;

	distance1 = distance(x2,x3,y2,y3);
	distance2 = distance(x1,x3,y1,y3);
	distance3 = distance(x1,x2,y1,y2);
	perimeter = distance1 + distance2 + distance3;

	*centerx = (x1*distance1 + x2*distance2 + x3*distance3)/perimeter;
	*centery = (y1*distance1 + y2*distance2 + y3*distance3)/perimeter;
}
