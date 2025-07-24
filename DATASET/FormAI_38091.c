//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>

// function to calculate if a given year is a leap year or not
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

// function to calculate number of days in a month based on year
int daysInMonth(int month, int year) {
    switch(month) {
        case 1:
            return 31;
        case 2:
            if(isLeapYear(year)) {
                return 29;
            }
            else {
                return 28;
            }
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
}

// function to convert natural language date string to integer date components
void naturalToDate(char *date, int *day, int *month, int *year) {
    // convert natural language string to lowercase
    for(int i = 0; date[i] != '\0'; i++) {
        if(date[i] >= 'A' && date[i] <= 'Z') {
            date[i] += 32;
        }
    }
    // check for month name
    if(strstr(date, "january") != NULL) {
        *month = 1;
    }
    else if(strstr(date, "february") != NULL) {
        *month = 2;
    }
    else if(strstr(date, "march") != NULL) {
        *month = 3;
    }
    else if(strstr(date, "april") != NULL) {
        *month = 4;
    }
    else if(strstr(date, "may") != NULL) {
        *month = 5;
    }
    else if(strstr(date, "june") != NULL) {
        *month = 6;
    }
    else if(strstr(date, "july") != NULL) {
        *month = 7;
    }
    else if(strstr(date, "august") != NULL) {
        *month = 8;
    }
    else if(strstr(date, "september") != NULL) {
        *month = 9;
    }
    else if(strstr(date, "october") != NULL) {
        *month = 10;
    }
    else if(strstr(date, "november") != NULL) {
        *month = 11;
    }
    else if(strstr(date, "december") != NULL) {
        *month = 12;
    }
    // find year and day
    char *token = strtok(date, " ");
    while(token != NULL) {
        if(atoi(token) > 1900) {
            *year = atoi(token);
        }
        else if(atoi(token) > 0 && atoi(token) <= 31) {
            *day = atoi(token);
        }
        else if(atoi(token) > 31 && atoi(token) <= 1900) {
            *year = atoi(token);
        }
        token = strtok(NULL, " ");
    }
}

// driver function
int main() {
    char date[100];
    printf("Enter a date in natural language: ");
    gets(date);
    int day = 0, month = 0, year = 0;
    naturalToDate(date, &day, &month, &year);
    printf("Converted date: %02d/%02d/%04d\n", day, month, year);
    int maxDays = daysInMonth(month, year);
    printf("Number of days in %02d/%d: %d\n", month, year, maxDays);
    return 0;
}