//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that takes a date as input and converts it to natural language
char* convertToDate(int day, int month, int year){
    char* monthString;
    char* dayString;
    char* yearString;

    // Determine month
    switch(month){
        case 1:
            monthString = "January";
            break;
        case 2:
            monthString = "February";
            break;
        case 3:
            monthString = "March";
            break;
        case 4:
            monthString = "April";
            break;
        case 5:
            monthString = "May";
            break;
        case 6:
            monthString = "June";
            break;
        case 7:
            monthString = "July";
            break;
        case 8:
            monthString = "August";
            break;
        case 9:
            monthString = "September";
            break;
        case 10:
            monthString = "October";
            break;
        case 11:
            monthString = "November";
            break;
        case 12:
            monthString = "December";
            break;
        default:
            monthString = "Invalid Month";
            break;
    }

    // Determine day suffix
    switch(day){
        case 1:
        case 21:
        case 31:
            dayString = "st";
            break;
        case 2:
        case 22:
            dayString = "nd";
            break;
        case 3:
        case 23:
            dayString = "rd";
            break;
        default:
            dayString = "th";
            break;
    }

    // Convert year to string
    char yearTemp[5];
    sprintf(yearTemp, "%d", year);
    yearString = yearTemp;

    // Generate natural language string
    char* result;
    result = (char *) malloc(strlen(monthString) + strlen(dayString) + strlen(yearString) + 15);
    sprintf(result, "%s %d%s, %s", monthString, day, dayString, yearString);

    return result;
}

int main(){
    int day, month, year;
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter the date in the format DD/MM/YYYY:\n");
    scanf("%d/%d/%d", &day, &month, &year);

    // Call the conversion function and print the result
    char* naturalLanguageDate = convertToDate(day, month, year);
    printf("The natural language date is: %s\n", naturalLanguageDate);

    // Free memory
    free(naturalLanguageDate);

    printf("Thanks for using the Natural Language Date Converter!\n");

    return 0;
}