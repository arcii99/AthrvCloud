//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: introspective
#include <stdio.h>

// function to check if a given year is a leap year or not
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// function to get the number of days in a given month of a given year
int getDaysInMonth(int month, int year) {
    int numDays = 0;
    
    switch (month) {
        case 1: // January
        case 3: // March
        case 5: // May
        case 7: // July
        case 8: // August
        case 10: // October
        case 12: // December
            numDays = 31;
            break;
        case 4: // April
        case 6: // June
        case 9: // September
        case 11: // November
            numDays = 30;
            break;
        case 2: // February
            if (isLeapYear(year)) {
                numDays = 29;
            } else {
                numDays = 28;
            }
            break;
        default:
            printf("Error: Invalid month entered\n");
            break;
    }
    
    return numDays;
}

// main function
int main(void) {
    int month, day, year, numDays, i;
    char monthName[10];
    
    // get input from user
    printf("Enter a date in the format mm/dd/yyyy: ");
    scanf("%2d/%2d/%4d", &month, &day, &year);
    
    // convert month to month name
    switch (month) {
        case 1:
            strcpy(monthName, "January");
            break;
        case 2:
            strcpy(monthName, "February");
            break;
        case 3:
            strcpy(monthName, "March");
            break;
        case 4:
            strcpy(monthName, "April");
            break;
        case 5:
            strcpy(monthName, "May");
            break;
        case 6:
            strcpy(monthName, "June");
            break;
        case 7:
            strcpy(monthName, "July");
            break;
        case 8:
            strcpy(monthName, "August");
            break;
        case 9:
            strcpy(monthName, "September");
            break;
        case 10:
            strcpy(monthName, "October");
            break;
        case 11:
            strcpy(monthName, "November");
            break;
        case 12:
            strcpy(monthName, "December");
            break;
        default:
            printf("Error: Invalid month entered\n");
            break;
    }
    
    // calculate number of days since January 1st
    numDays = day;
    for (i = 1; i < month; i++) {
        numDays += getDaysInMonth(i, year);
    }
    
    // output result
    printf("%s %d, %d is day %d of the year.\n", monthName, day, year, numDays);
    
    return 0;
}