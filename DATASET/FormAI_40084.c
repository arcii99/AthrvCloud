//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This program converts dates from natural language to numerical format (MM/DD/YYYY).
 * It accepts a string as input and searches for date formats in the string using regular expressions.
 * If a date is found, it extracts the relevant information and converts it to numerical format.
 * The program assumes that the year is always specified in full (4 digits).
 */

int main() {
    char input[100];
    int month, day, year;

    printf("Enter date in natural language: ");
    fgets(input, 100, stdin);

    // Search for date formats "Month DD, YYYY" and "MM/DD/YYYY"
    if (sscanf(input, "%*s %d, %d", &day, &year) == 2) { // Month DD, YYYY
        month = monthToInt(input);
    } else if (sscanf(input, "%d/%d/%d", &month, &day, &year) == 3) { // MM/DD/YYYY
    } else {
        printf("Error: Could not parse date.\n");
        return 0;
    }

    // Validate date
    if (!isValidDate(month, day, year)) {
        printf("Error: Invalid date.\n");
        return 0;
    }

    printf("Converted to numerical format: %02d/%02d/%04d\n", month, day, year);
    return 0;
}

/**
 * Converts a month name to its corresponding integer value
 */
int monthToInt(char* month) {
    if (strstr(month, "January")) {
        return 1;
    } else if (strstr(month, "February")) {
        return 2;
    } else if (strstr(month, "March")) {
        return 3;
    } else if (strstr(month, "April")) {
        return 4;
    } else if (strstr(month, "May")) {
        return 5;
    } else if (strstr(month, "June")) {
        return 6;
    } else if (strstr(month, "July")) {
        return 7;
    } else if (strstr(month, "August")) {
        return 8;
    } else if (strstr(month, "September")) {
        return 9;
    } else if (strstr(month, "October")) {
        return 10;
    } else if (strstr(month, "November")) {
        return 11;
    } else {
        return 12;
    }
}

/**
 * Validates a given date
 */
int isValidDate(int month, int day, int year) {
    if (year < 0 || year > 9999) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > 31) {
        return 0;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
        return 0;
    }
    if (month == 2) {
        int leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 29 || (day == 29 && !leap)) {
            return 0;
        }
    }
    return 1;
}