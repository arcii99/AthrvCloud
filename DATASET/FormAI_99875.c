//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char date[1000], month[1000], year[1000];
    int month_num = 0, day_num = 0, year_num = 0;
    printf("\nEnter a date in natural language: ");
    gets(date);
    // converting input date to lowercase
    for (int i = 0; i < strlen(date); i++) {
        date[i] = tolower(date[i]);
    }
    // separating day and year from the input date
    sscanf(date, "%d %s %d", &day_num, year, &year_num);
    // converting month name to month number
    if (strstr(date, "january")) {
        month_num = 1;
    } else if (strstr(date, "february")) {
        month_num = 2;
    } else if (strstr(date, "march")) {
        month_num = 3;
    } else if (strstr(date, "april")) {
        month_num = 4;
    } else if (strstr(date, "may")) {
        month_num = 5;
    } else if (strstr(date, "june")) {
        month_num = 6;
    } else if (strstr(date, "july")) {
        month_num = 7;
    } else if (strstr(date, "august")) {
        month_num = 8;
    } else if (strstr(date, "september")) {
        month_num = 9;
    } else if (strstr(date, "october")) {
        month_num = 10;
    } else if (strstr(date, "november")) {
        month_num = 11;
    } else if (strstr(date, "december")) {
        month_num = 12;
    } else {
        printf("\nInvalid input date format.");
        exit(0);
    }
    printf("\nThe date in numerical format is: %d/%d/%d", month_num, day_num, year_num);
    return 0;
}