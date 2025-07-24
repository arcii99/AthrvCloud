//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

/*
 * This is a simple program that converts natural language dates to numeric date format.
 * It accepts dates in the form:
 * 
 *    "Today", "Tomorrow", "Yesterday"
 * 
 * or
 * 
 *    "December 25th, 2022", "May 1, 2023", "Jan 05th, 2021"
 * 
 * and returns them in the format:
 * 
 *    "2022-12-25", "2023-05-01", "2021-01-05"
 * 
 * The program assumes that the input is valid and does not perform any input checking.
 * */

int main()
{
    char input[20]; // buffer for the user's input
    int year, month, day; // variables for storing the converted date
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in natural language format: ");
    fgets(input, sizeof(input), stdin); // get the user's input
    
    if (strncmp(input, "Today", 5) == 0) // if the input is "Today"
    {
        printf("Today is %s.", __DATE__);
        return 0;
    }
    else if (strncmp(input, "Tomorrow", 8) == 0) // if the input is "Tomorrow"
    {
        printf("Tomorrow is %s.", __DATE__ + 4);
        return 0;
    }
    else if (strncmp(input, "Yesterday", 9) == 0) // if the input is "Yesterday"
    {
        printf("Yesterday was %s.",__DATE__ - 17);
        return 0;
    }

    // if the input is a date in the form "Month DD, YYYY" or "Month DDth, YYYY"
    if (sscanf(input, "%*s %d%*c%d%*c%d", &day, &month, &year) == 3)
    {
        printf("%d-%02d-%02d", year, month, day); // print the converted date
        return 0;
    }

    // if the input is a date in the form "MMM DD, YYYY" or "MMM DDth, YYYY"
    if (sscanf(input, "%*s %d%*c%*s%*c%d", &day, &year) == 2)
    {
        char month_str[4];
        sscanf(input, "%*s %*d%*c%3s", month_str);
        month_str[3] = '\0';

        // convert the month string to a number
        switch (month_str[0])
        {
            case 'J':
                if (month_str[1] == 'a') month = 1;
                else if (month_str[2] == 'n') month = 6;
                else month = 7;
                break;
            case 'F':
                month = 2;
                break;
            case 'M':
                if (month_str[2] == 'r') month = 3;
                else month = 5;
                break;
            case 'A':
                if (month_str[1] == 'p') month = 4;
                else month = 8;
                break;
            case 'S':
                month = 9;
                break;
            case 'O':
                month = 10;
                break;
            case 'N':
                month = 11;
                break;
            case 'D':
                month = 12;
                break;
            default:
                printf("Invalid month: %s", month_str);
                return 1;
        }

        printf("%d-%02d-%02d", year, month, day); // print the converted date
        return 0;
    }

    // if we get here, the input was not recognized
    printf("Invalid input: %s", input);
    return 1;
}