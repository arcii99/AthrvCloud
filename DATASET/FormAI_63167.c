//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    }
    else if (year % 400 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to convert a date string in natural language to a date object
void convertToDate(char *input) {
    char *day, *month, *year;
    int d, m, y;

    // Split the input string into day, month and year
    day = strtok(input, " ");
    month = strtok(NULL, " ");
    year = strtok(NULL, "\n");

    // Convert day to integer
    d = atoi(day);

    // Convert month to integer
    if (strcmp(month, "January") == 0) {
        m = 1;
    }
    else if (strcmp(month, "February") == 0) {
        m = 2;
    }
    else if (strcmp(month, "March") == 0) {
        m = 3;
    }
    else if (strcmp(month, "April") == 0) {
        m = 4;
    }
    else if (strcmp(month, "May") == 0) {
        m = 5;
    }
    else if (strcmp(month, "June") == 0) {
        m = 6;
    }
    else if (strcmp(month, "July") == 0) {
        m = 7;
    }
    else if (strcmp(month, "August") == 0) {
        m = 8;
    }
    else if (strcmp(month, "September") == 0) {
        m = 9;
    }
    else if (strcmp(month, "October") == 0) {
        m = 10;
    }
    else if (strcmp(month, "November") == 0) {
        m = 11;
    }
    else {
        m = 12;
    }

    // Convert year to integer
    y = atoi(year);

    // Check if the date is valid
    if (d >= 1 && d <= getDaysInMonth(m, y)) {
        printf("The date is: %d/%d/%d\n", d, m, y);
    }
    else {
        printf("Invalid date!\n");
    }
}

int main() {
    // Sample input strings in natural language
    char input1[] = "1 January 2022\n";
    char input2[] = "29 February 2021\n";
    char input3[] = "31 April 2022\n";
    char input4[] = "31 June 2022\n";
    char input5[] = "30 February 2022\n";

    // Convert the input strings to dates
    convertToDate(input1);
    convertToDate(input2);
    convertToDate(input3);
    convertToDate(input4);
    convertToDate(input5);

    return 0;
}