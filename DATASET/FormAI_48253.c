//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define YEAR_LENGTH 4
#define MAX_MONTH 12
#define MIN_MONTH 1
#define MAX_DAY 31
#define MIN_DAY 1

int main()
{
    char date_str[11]; // Holds date string in "MM/DD/YYYY" format
    int month, day, year; // Holds parsed date values

    // Get date input from user
    printf("Enter a date in MM/DD/YYYY format: ");
    fgets(date_str, sizeof(date_str), stdin);

    // Verify that date string is in the correct format and is not too long
    if (strlen(date_str) != 11 || date_str[2] != '/' || date_str[5] != '/')
    {
        printf("Error: Date must be in MM/DD/YYYY format\n");
        return 1;
    }

    // Parse date values from string
    if (sscanf(date_str, "%d/%d/%d", &month, &day, &year) != 3)
    {
        printf("Error: Unable to parse date values\n");
        return 1;
    }

    // Perform paranoid checks on date values
    if (year < 1)
    {
        printf("Error: Year cannot be negative or zero\n");
        return 1;
    }

    if (month < MIN_MONTH || month > MAX_MONTH)
    {
        printf("Error: Month must be between %d and %d\n", MIN_MONTH, MAX_MONTH);
        return 1;
    }

    if (day < MIN_DAY || day > MAX_DAY)
    {
        printf("Error: Day must be between %d and %d\n", MIN_DAY, MAX_DAY);
        return 1;
    }

    // Convert month to text
    char* month_text;
    switch (month)
    {
        case 1:
            month_text = "January";
            break;
        case 2:
            month_text = "February";
            break;
        case 3:
            month_text = "March";
            break;
        case 4:
            month_text = "April";
            break;
        case 5:
            month_text = "May";
            break;
        case 6:
            month_text = "June";
            break;
        case 7:
            month_text = "July";
            break;
        case 8:
            month_text = "August";
            break;
        case 9:
            month_text = "September";
            break;
        case 10:
            month_text = "October";
            break;
        case 11:
            month_text = "November";
            break;
        case 12:
            month_text = "December";
            break;
        default:
            printf("Error: Invalid month\n");
            return 1;
    }

    // Print paranoid-friendly output with results
    printf("%s %d, %d\n", month_text, day, year);

    return 0;
}