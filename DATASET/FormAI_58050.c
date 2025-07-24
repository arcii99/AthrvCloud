//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a given year is a leap year
int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// function to calculate the number of days in a month
int getDaysInMonth(int month, int year) {
    int days;

    // April, June, September and November have 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    }
    // February has 29 days in a leap year and 28 days in a non-leap year
    else if (month == 2) {
        days = isLeapYear(year) ? 29 : 28;
    }
    // All other months have 31 days
    else {
        days = 31;
    }

    return days;
}

// function to convert a date from natural language format to ISO 8601 format
void naturalToDate(char *naturalDate) {
    // declare variables
    char *monthString, *dayString, *yearString;
    int month, day, year, daysInMonth, i;

    // tokenize the natural date string
    monthString = strtok(naturalDate, " ");
    dayString = strtok(NULL, " ");
    yearString = strtok(NULL, " ");

    // convert the month string to an integer
    if (strcmp(monthString, "January") == 0) {
        month = 1;
    }
    else if (strcmp(monthString, "February") == 0) {
        month = 2;
    }
    else if (strcmp(monthString, "March") == 0) {
        month = 3;
    }
    else if (strcmp(monthString, "April") == 0) {
        month = 4;
    }
    else if (strcmp(monthString, "May") == 0) {
        month = 5;
    }
    else if (strcmp(monthString, "June") == 0) {
        month = 6;
    }
    else if (strcmp(monthString, "July") == 0) {
        month = 7;
    }
    else if (strcmp(monthString, "August") == 0) {
        month = 8;
    }
    else if (strcmp(monthString, "September") == 0) {
        month = 9;
    }
    else if (strcmp(monthString, "October") == 0) {
        month = 10;
    }
    else if (strcmp(monthString, "November") == 0) {
        month = 11;
    }
    else if (strcmp(monthString, "December") == 0) {
        month = 12;
    }
    else {
        printf("Month is invalid.\n");
        return;
    }

    // convert the day string to an integer
    day = atoi(dayString);

    // convert the year string to an integer
    year = atoi(yearString);

    // check if the day is valid for the given month and year
    daysInMonth = getDaysInMonth(month, year);
    if (day < 1 || day > daysInMonth) {
        printf("Day is invalid.\n");
        return;
    }

    // print the ISO 8601 formatted date
    printf("%04d-%02d-%02d\n", year, month, day);
}

int main() {
    // test the naturalToDate function with some example inputs
    naturalToDate("January 1 2022");
    naturalToDate("February 29 2021");
    naturalToDate("March 31 2022");
    naturalToDate("April 31 2022");
    naturalToDate("May 31 2022");
    naturalToDate("June 31 2022");
    naturalToDate("July 31 2022");
    naturalToDate("August 31 2022");
    naturalToDate("September 31 2022");
    naturalToDate("October 31 2022");
    naturalToDate("November 31 2022");
    naturalToDate("December 31 2022");

    return 0;
}