//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a given year is leap year or not
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

// Function to get the number of days in a given month of a given year
int getNumberOfDays(int month, int year)
{
    switch (month) {
        case 2:
            return isLeapYear(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

// Function to convert string to uppercase
char *toUpper(char *str)
{
    char *ptr = str;
    while (*ptr) {
        *ptr = toupper(*ptr);
        ptr++;
    }
    return str;
}

// Function to check if the given string has only digits
int isNumeric(char *str)
{
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to parse the input date string and return the three components
void parseInputDate(char *inputStr, int *day, int *month, int *year)
{
    char str[100];
    strcpy(str, inputStr);
    char *token = strtok(str, "-/");
    int parts[3];
    int i = 0;
    while (token != NULL && i < 3) {
        if (isNumeric(token)) {
            parts[i] = atoi(token);
            i++;
        }
        token = strtok(NULL, "-/");
    }
    *day = parts[0];
    *month = parts[1];
    *year = parts[2];
}

// Main function to convert the input date to Natural Language Date format
int main()
{
    char inputString[100];
    printf("Please enter a date in the format dd-MM-yyyy or dd/MM/yyyy: ");
    fgets(inputString, 100, stdin);
    inputString[strcspn(inputString, "\n")] = '\0'; // remove the newline character from input string
    toUpper(inputString);
    int day, month, year;
    parseInputDate(inputString, &day, &month, &year);
    int numberOfDays = getNumberOfDays(month, year);
    char *monthNames[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char *postfix;
    if (day == 1 || day == 21 || day == 31) {
        postfix = "st";
    } else if (day == 2 || day == 22) {
        postfix = "nd";
    } else if (day == 3 || day == 23) {
        postfix = "rd";
    } else {
        postfix = "th";
    }
    if (month < 1 || month > 12 || day < 1 || day > numberOfDays || year < 0) {
        printf("Invalid date!\n");
        return 1;
    }
    printf("%s %d%s, %d\n", monthNames[month - 1], day, postfix, year);
    return 0;
}