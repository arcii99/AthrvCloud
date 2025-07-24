//FormAI DATASET v1.0 Category: Data validation ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
    This is a program to validate user input of a date in the form of "mm/dd/yyyy".
    We will ensure that each part is a valid number with correct ranges for month/day and year range above 1900 and below 2100.
*/

#define MIN_YEAR 1900
#define MAX_YEAR 2100

bool is_valid_date(char *date) {
    int month, day, year;
    char c;
    if (sscanf(date, "%d%c%d%c%d", &month, &c, &day, &c, &year) != 5) {
        printf("Invalid date format. Please input date in the form of mm/dd/yyyy.\n");
        return false;
    }
    if (c != '/') {
        printf("Invalid date separator. Please use '/' as separator.\n");
        return false;
    }
    if ((month < 1) || (month > 12)) {
        printf("Invalid month. Please input a month between 1 - 12.\n");
        return false;
    }
    if ((day < 1) || (day > 31)) {
        printf("Invalid day. Please input a day between 1 - 31.\n");
        return false;
    }
    if ((year < MIN_YEAR) || (year > MAX_YEAR)) {
        printf("Invalid year. Please input a year between %d - %d.\n", MIN_YEAR, MAX_YEAR);
        return false;
    }
    return true;
}

int main() {

    char date[11];
    printf("Please input a date in the form of mm/dd/yyyy: ");
    fgets(date, 11, stdin);
    if (is_valid_date(date)){
        printf("The date \"%s\" is valid!",date);
    }
    return 0;
}