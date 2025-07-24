//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to convert the given month into integer value
int monthValue(char *month) {
    int value;

    if (strcmp(month,"January") == 0) {
        value = 1;
    } else if (strcmp(month,"February") == 0) {
        value = 2;
    } else if (strcmp(month,"March") == 0) {
        value = 3;
    } else if (strcmp(month,"April") == 0) {
        value = 4;
    } else if (strcmp(month,"May") == 0) {
        value = 5;
    } else if (strcmp(month,"June") == 0) {
        value = 6;
    } else if (strcmp(month,"July") == 0) {
        value = 7;
    } else if (strcmp(month,"August") == 0) {
        value = 8;
    } else if (strcmp(month,"September") == 0) {
        value = 9;
    } else if (strcmp(month,"October") == 0) {
        value = 10;
    } else if (strcmp(month,"November") == 0) {
        value = 11;
    } else if (strcmp(month,"December") == 0) {
        value = 12;
    } else {
        printf("Error: Invalid month - %s, expected full month name (example: January)\n", month);
        exit(0);
    }

    return value;
}

// main function to convert the date
int main() {
    char dateString[12];
    int day,month,year;
    printf("Date converter: C Natural Language to Date Format\n\n");

    // read the user input
    printf("Input Date (example: January 1, 2022): ");
    gets(dateString);

    // validate the input
    if (sscanf(dateString,"%d,%d,%d",&month,&day,&year) != 3) {
        printf("Error: Invalid date format - %s, expected 'Full Month Name day, year'\n", dateString);
        exit(0);
    }

    if (month < 1 || month > 12) {
        printf("Error: Invalid month value - %d, expected value between 1 and 12\n", month);
        exit(0);
    }

    if (day < 1 || day > 31) {
        printf("Error: Invalid day value - %d, expected value between 1 and 31\n", day);
        exit(0);
    }

    if (year < 0 || year > 9999) {
        printf("Error: Invalid year value - %d, expected value between 0 and 9999\n", year);
        exit(0);
    }

    printf("\nConverted Date: %d-%02d-%02d\n", year, month, day);

    return 0;
}