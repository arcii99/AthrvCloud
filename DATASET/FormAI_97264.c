//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: random
#include<stdio.h>

int main() {

	int month, day, year;
	char month_name[20];

	printf("Enter the date in \"Month Day, Year\" format: ");
	scanf("%s %d, %d", month_name, &day, &year);

	if(strcmp(month_name, "January") == 0) {
		month = 1;
	} else if(strcmp(month_name, "February") == 0) {
		month = 2;
	} else if(strcmp(month_name, "March") == 0) {
		month = 3;
	} else if(strcmp(month_name, "April") == 0) {
		month = 4;
	} else if(strcmp(month_name, "May") == 0) {
		month = 5;
	} else if(strcmp(month_name, "June") == 0) {
		month = 6;
	} else if(strcmp(month_name, "July") == 0) {
		month = 7;
	} else if(strcmp(month_name, "August") == 0) {
		month = 8;
	} else if(strcmp(month_name, "September") == 0) {
		month = 9;
	} else if(strcmp(month_name, "October") == 0) {
		month = 10;
	} else if(strcmp(month_name, "November") == 0) {
		month = 11;
	} else if(strcmp(month_name, "December") == 0) {
		month = 12;
	} else {
		printf("Invalid input\n");
		return 0;
	}

	printf("The date in \"MM/DD/YYYY\" format is: %d/%d/%d", month, day, year);

	return 0;
}