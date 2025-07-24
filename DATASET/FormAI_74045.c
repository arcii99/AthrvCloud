//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to check if the given year is a leap year or not */
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1; // it's a leap year
    }
    return 0; // it's not a leap year
}

/* Function to find the number of days in the given month */
int daysInMonth(int month, int year) {
    if (month == 2) { // February
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { // April, June, September, November
        return 30;
    } else { // January, March, May, July, August, October, December
        return 31;
    }
}

/* Function to convert a given date string to C natural language date format */
void convertToDate(char *date) {
    int day, year, month;
    char monthString[4];

    // Tokenize the date string and extract the day, month and year
    sscanf(date, "%d %s %d", &day, monthString, &year);
    
    // Convert the month string to a numerical value
    if (strcmp(monthString, "January") == 0) {
        month = 1;
    } else if (strcmp(monthString, "February") == 0) {
        month = 2;
    } else if (strcmp(monthString, "March") == 0) {
        month = 3;
    } else if (strcmp(monthString, "April") == 0) {
        month = 4;
    } else if (strcmp(monthString, "May") == 0) {
        month = 5;
    } else if (strcmp(monthString, "June") == 0) {
        month = 6;
    } else if (strcmp(monthString, "July") == 0) {
        month = 7;
    } else if (strcmp(monthString, "August") == 0) {
        month = 8;
    } else if (strcmp(monthString, "September") == 0) {
        month = 9;
    } else if (strcmp(monthString, "October") == 0) {
        month = 10;
    } else if (strcmp(monthString, "November") == 0) {
        month = 11;
    } else if (strcmp(monthString, "December") == 0) {
        month = 12;
    } else {
        printf("Invalid date format provided!\n");
        return;
    }

    // Check if the given date is valid
    int daysInGivenMonth = daysInMonth(month, year);
    if (day <= 0 || day > daysInGivenMonth) {
        printf("Invalid date provided!\n");
        return;
    }

    // Print the date in C natural language format
    printf("Date: %d%c%s %d\n", day, day == 1 || day == 21 || day == 31 ? 's' : day == 2 || day == 22 ? 'n' : 't', 
           month == 1 ? " January " : month == 2 ? " February " : month == 3 ? " March " : month == 4 ? " April " :
           month == 5 ? " May " : month == 6 ? " June " : month == 7 ? " July " : month == 8 ? " August " :
           month == 9 ? " September " : month == 10 ? " October " : month == 11 ? " November " : " December ", year);
}

int main() {
    char date[20];

    printf("Enter date in the format of (day month year): ");
    fgets(date, 20, stdin);
    convertToDate(date);

    return 0;
}