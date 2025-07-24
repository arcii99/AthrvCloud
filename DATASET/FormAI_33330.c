//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the constants
#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9 
#define OCT 10
#define NOV 11
#define DEC 12

// function to convert month name to number
int month_name_to_number(char* month_name) {
    int month_number;
    if (strcmp(month_name, "January") == 0) {
        month_number = JAN;
    }
    else if (strcmp(month_name, "February") == 0) {
        month_number = FEB;
    }
    else if (strcmp(month_name, "March") == 0) {
        month_number = MAR;
    }
    else if (strcmp(month_name, "April") == 0) {
        month_number = APR;
    }
    else if (strcmp(month_name, "May") == 0) {
        month_number = MAY;
    }
    else if (strcmp(month_name, "June") == 0) {
        month_number = JUN;
    }
    else if (strcmp(month_name, "July") == 0) {
        month_number = JUL;
    }
    else if (strcmp(month_name, "August") == 0) {
        month_number = AUG;
    }
    else if (strcmp(month_name, "September") == 0) {
        month_number = SEP;
    }
    else if (strcmp(month_name, "October") == 0) {
        month_number = OCT;
    }
    else if (strcmp(month_name, "November") == 0) {
        month_number = NOV;
    }
    else if (strcmp(month_name, "December") == 0) {
        month_number = DEC;
    }
    else {
        // if invalid month name is entered, terminate the program.
        printf("Error: Invalid month name!\n");
        exit(0);
    }
    return month_number;
}

// function to convert date to number of days
int date_to_days(int day, int month, int year) {
    int days = day;
    for (int i = 1; i < month; i++) {
        switch(i) {
            case JAN:
            case MAR:
            case MAY:
            case JUL:
            case AUG:
            case OCT:
            case DEC:
                days += 31;
                break;
            case APR:
            case JUN:
            case SEP:
            case NOV:
                days += 30;
                break;
            case FEB:
                if (year%4 == 0 && year%100 != 0 || year%400 == 0) {
                    // leap year condition
                    days += 29;
                }
                else {
                    days += 28;
                }
                break;
            default:
                printf("Invalid month!");
                exit(0);
        }
    }
    return days;
}

int main() {
    // take user input
    char month_name[10];
    int day, year;
    printf("Enter date in natural language (ex: January 1st, 2022): ");
    scanf("%s %d, %d", month_name, &day, &year);
    
    // convert month name to number
    int month = month_name_to_number(month_name);
    
    // convert date to number of days
    int days = date_to_days(day, month, year);
    
    // print output
    printf("Number of days since January 1st, 0000: %d\n", days);
    
    return 0;
}