//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global variables to store date
int year = 0;
int month = 0;
int day = 0;

// Function to convert month from string to digit
int monthFromString(char *monthString)
{
    if (strcmp(monthString, "January") == 0)
    {
        return 1;
    }
    else if (strcmp(monthString, "February") == 0)
    {
        return 2;
    }
    else if (strcmp(monthString, "March") == 0)
    {
        return 3;
    }
    else if (strcmp(monthString, "April") == 0)
    {
        return 4;
    }
    else if (strcmp(monthString, "May") == 0)
    {
        return 5;
    }
    else if (strcmp(monthString, "June") == 0)
    {
        return 6;
    }
    else if (strcmp(monthString, "July") == 0)
    {
        return 7;
    }
    else if (strcmp(monthString, "August") == 0)
    {
        return 8;
    }
    else if (strcmp(monthString, "September") == 0)
    {
        return 9;
    }
    else if (strcmp(monthString, "October") == 0)
    {
        return 10;
    }
    else if (strcmp(monthString, "November") == 0)
    {
        return 11;
    }
    else if (strcmp(monthString, "December") == 0)
    {
        return 12;
    }
    else
    {
        return -1; // If invalid month string is provided
    }
}

// Function to break date string into year, month and day
void breakDate(char *dateString)
{
    char *token = strtok(dateString, " "); // split the string using a space delimiter
    int tokenCount = 0; 

    // Loop through all the tokens and split them into year, month, and day
    while (token != NULL)
    {
        tokenCount++;

        // Year
        if (tokenCount == 3)
        {
            year = atoi(token);
        }

        // Month
        if (tokenCount == 2)
        {
            month = monthFromString(token);
        }

        // Day
        if (tokenCount == 1)
        {
            day = atoi(token);
        }

        token = strtok(NULL, " ");
    }
}

int main()
{
    char dateString[100];
    printf("Enter a date in the format 'day month year' (for example, '25 December 2021'):\n");
    fgets(dateString, 100, stdin);
    breakDate(dateString);

    // Print the original date
    printf("Original date: %d-%02d-%02d\n", year, month, day);

    // Convert date to natural language
    char *monthString;
    switch (month)
    {
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
            printf("Invalid month\n");
            return 1;
    }

    printf("Natural language date: %s %d, %d\n", monthString, day, year);

    return 0;
}