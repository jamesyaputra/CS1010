#include <stdio.h>

int computeDays (int, int);

int main (void) {
	int day, month, total;

	printf("Enter day and month: ");
	scanf("%d %d", &day, &month);

	total = computeDays(day, month);

	printf("Day %d of month %d is the %dth day of 2017.\n", day, month, total);

	return 0;
}

int computeDays (int day, int month) {
	int daY;

	switch (month / 1) {
		case 1:
			daY = 0 + day;
			return daY;
			break;
		case 2:
			daY = 31 + day;
			return daY;
			break;
		case 3:
			daY = 59 + day;
			return daY;
			break;
		case 4:
			daY = 90 + day;
			return daY;
			break;
		case 5:
			daY = 120 + day;
			return daY;
			break;
		case 6:
			daY = 151 + day;
			return daY;
			break;
		case 7:
			daY = 181 + day;
			return daY;
			break;
		case 8:
			daY = 212 + day;
			return daY;
			break;
		case 9:
			daY = 243 + day;
			return daY;
			break;
		case 10:
			daY = 273 + day;
			return daY;
			break;
		case 11:
			daY = 304 + day;
			return daY;
			break;
		case 12:
			daY = 334 + day;
			return daY;
			break;
		default:
			daY = 10000;
			return daY;
			break;
	}
}
