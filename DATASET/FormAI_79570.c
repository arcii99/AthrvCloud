//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <string.h>

// A function to determine if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// A function to determine the number of days in a month for a given year
int daysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// A function to convert a date in natural language to a date in the format "YYYY-MM-DD"
void convertNaturalLanguageDate(char* naturalLanguageDate) {
    // Define a list of months and their corresponding numbers
    char months[12][10] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int monthNumbers[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // Parse the natural language date into month, day, and year
    char* monthString = strtok(naturalLanguageDate, " ");
    char* dayString = strtok(NULL, ", ");
    char* yearString = strtok(NULL, " ");

    // Convert the month string to a number
    int month = 0;
    for (int i = 0; i < 12; i++) {
        if (strcmp(monthString, months[i]) == 0) {
            month = monthNumbers[i];
            break;
        }
    }

    // Convert the day and year strings to numbers
    int day = atoi(dayString);
    int year = atoi(yearString);

    // Calculate the number of days since January 1, 1 AD
    int totalDays = 0;
    for (int i = 1; i < year; i++) {
        if (isLeapYear(i)) {
            totalDays += 366;
        } else {
            totalDays += 365;
        }
    }
    for (int i = 1; i < month; i++) {
        totalDays += daysInMonth(i, year);
    }
    totalDays += day - 1; // Subtract 1 because we want the number of days since January 1, not since January 2

    // Print out the date in the "YYYY-MM-DD" format
    printf("%04d-%02d-%02d", year, month, day);
}

int main() {
    // Test the function with a few different natural language dates
    char naturalLanguageDates[3][30] = {
        "February 3, 2022",
        "October 31, 2023",
        "December 25, 2024"
    };
    for (int i = 0; i < 3; i++) {
        printf("%s => ", naturalLanguageDates[i]);
        convertNaturalLanguageDate(naturalLanguageDates[i]);
        printf("\n");
    }
    return 0;
}