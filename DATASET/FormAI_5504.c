//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to convert month number to a month name
char* getMonthName(int month)
{
    char *monthName;

    switch (month)
    {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
        default:
            monthName = "Invalid";
    }

    return monthName;
}

// Function to convert a date in C Natural Language format to a numeric date
void convertDate(char *date)
{
    int month, day, year;

    sscanf(date, "%d %*s %d %*s %d", &month, &day, &year);

    // Print the numeric date
    printf("Numeric date: %d/%d/%d\n", month, day, year);

    // Check if the year is a leap year and print a message
    if (isLeapYear(year))
    {
        printf("%d is a leap year.\n", year);
    }
    else
    {
        printf("%d is not a leap year.\n", year);
    }

    // Print the month name and number of days in the month (taking into account leap years)
    char *monthName = getMonthName(month);
    int numDays;

    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            numDays = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            numDays = 30;
            break;
        case 2:
            if (isLeapYear(year))
            {
                numDays = 29;
            }
            else
            {
                numDays = 28;
            }
            break;
        default:
            numDays = -1;
    }

    printf("%s has %d days.\n", monthName, numDays);
}

int main()
{
    // Example usage
    convertDate("August 19, 2021");
    convertDate("February 29, 2020");
    convertDate("April 31, 2022");
    convertDate("Invalid date");

    return 0;
}