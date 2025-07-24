//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Function to convert month name to number
int monthToNumber(char month[]) {
    int month_number;

    if (strcmp(month, "January") == 0) {
        month_number = 1;
    } else if (strcmp(month, "February") == 0) {
        month_number = 2;
    } else if (strcmp(month, "March") == 0) {
        month_number = 3;
    } else if (strcmp(month, "April") == 0) {
        month_number = 4;
    } else if (strcmp(month, "May") == 0) {
        month_number = 5;
    } else if (strcmp(month, "June") == 0) {
        month_number = 6;
    } else if (strcmp(month, "July") == 0) {
        month_number = 7;
    } else if (strcmp(month, "August") == 0) {
        month_number = 8;
    } else if (strcmp(month, "September") == 0) {
        month_number = 9;
    } else if (strcmp(month, "October") == 0) {
        month_number = 10;
    } else if (strcmp(month, "November") == 0) {
        month_number = 11;
    } else if (strcmp(month, "December") == 0) {
        month_number = 12;
    }

    return month_number;
}

int main() {
    int day, year, month_number;
    char month[10];

    printf("Enter a date in natural language (e.g. January 1, 2022): ");
    scanf("%s %d, %d", month, &day, &year);

    month_number = monthToNumber(month);

    printf("The date is %02d/%02d/%d\n", month_number, day, year);

    return 0;
}