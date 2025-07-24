//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Function to check if a year is a leap year or not
int isLeapYear(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

// Function to convert a date from natural language to yyyy-mm-dd format
void convertToDate(char* input) {
    // Initialize variables
    char month[10], day[5], year[5];
    int monthNum, dayNum, yearNum;
    
    // Scan for month, day, and year
    sscanf(input, "%s %s %s", month, day, year);
    
    // Set monthNum based on month string
    if (strcmp(month, "January") == 0)
        monthNum = 1;
    else if (strcmp(month, "February") == 0)
        monthNum = 2;
    else if (strcmp(month, "March") == 0)
        monthNum = 3;
    else if (strcmp(month, "April") == 0)
        monthNum = 4;
    else if (strcmp(month, "May") == 0)
        monthNum = 5;
    else if (strcmp(month, "June") == 0)
        monthNum = 6;
    else if (strcmp(month, "July") == 0)
        monthNum = 7;
    else if (strcmp(month, "August") == 0)
        monthNum = 8;
    else if (strcmp(month, "September") == 0)
        monthNum = 9;
    else if (strcmp(month, "October") == 0)
        monthNum = 10;
    else if (strcmp(month, "November") == 0)
        monthNum = 11;
    else if (strcmp(month, "December") == 0)
        monthNum = 12;
    else {
        printf("Invalid month. Please try again.\n");
        return;
    }
    
    // Convert day and year to numbers
    dayNum = atoi(day);
    yearNum = atoi(year);
    
    // Check for valid day and year ranges
    if (dayNum < 1 || dayNum > 31) {
        printf("Invalid day. Please try again.\n");
        return;
    }
    if (yearNum < 1 || yearNum > 9999) {
        printf("Invalid year. Please try again.\n");
        return;
    }
    
    // Check for correct number of days in each month
    if (monthNum == 2) {
        if (isLeapYear(yearNum)) {
            if (dayNum > 29) {
                printf("Invalid day. February only has 29 days in leap years.\n");
                return;
            }
        }
        else {
            if (dayNum > 28) {
                printf("Invalid day. February only has 28 days in non-leap years.\n");
                return;
            }
        }
    }
    else if (monthNum == 4 || monthNum == 6 || monthNum == 9 || monthNum == 11) {
        if (dayNum > 30) {
            printf("Invalid day. This month only has 30 days.\n");
            return;
        }
    }
    
    // Print the converted date
    printf("The converted date is: %04d-%02d-%02d\n", yearNum, monthNum, dayNum);
}

int main() {
    // Ask for natural language input
    char input[30];
    printf("Enter a date in natural language (i.e. January 1, 2022): ");
    fgets(input, 30, stdin);
    
    // Call convertToDate function with input
    convertToDate(input);
    
    return 0;
}