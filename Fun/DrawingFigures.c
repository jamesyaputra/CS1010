#include <stdio.h>

void checkDraw(char);
void draw_rocket();
void draw_male();
void draw_female();
void drawCircle();
void drawRectangle();
void drawTriangle();
void drawInverted();

int main (void) {
	char input;
	
	do {
		printf("Draw (r)ocket, (m)ale, or (f)emale?\n");
		scanf("%c", &input);
	} while (input != 'r' && input != 'm' && input != 'f');
	
	checkDraw(input);
	
	return 0;
}

void checkDraw (char input) {
	switch (input) {
		case 'r':
			draw_rocket();
			break;
		case 'm':
			draw_male();
			break;
		default:
			draw_female();
	}
}

void draw_rocket() {
	drawTriangle();
	drawRectangle();
	drawInverted();
}

void draw_male() {
	drawCircle();
	drawRectangle();
	drawInverted();
}

void draw_female() {
	drawCircle();
	drawTriangle();
	drawInverted();
}

void drawCircle() {
	printf("   **   \n");
	printf(" *    * \n");
	printf(" *    * \n");
	printf("   **   \n");
}

void drawRectangle() {
	printf(" ****** \n");
	printf(" *    * \n");
	printf(" *    * \n");
	printf(" *    * \n");
	printf(" *    * \n");
	printf(" ****** \n");
}

void drawTriangle() {
	printf("   **   \n");
	printf("  *  *  \n");
	printf(" *    * \n");
	printf("* *  * *\n");
}

void drawInverted() {
	printf("   **   \n");
	printf("  *  *  \n");
	printf(" *    * \n");
	printf("*      *\n");
}