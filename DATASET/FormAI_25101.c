//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int day, month, year;
    char date[11];
    const char delim[2] = "/"; //The delimiter used in the date
    char *token;
    char monthStr[4]; //The short string representation of the month
    const char *months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%s", date);

    //Tokenize the input date string to extract the day, month and year integers
    token = strtok(date, delim);
    day = atoi(token);
    token = strtok(NULL, delim);
    month = atoi(token);
    token = strtok(NULL, delim);
    year = atoi(token);

    //Check if the year is a leap year and update the number of days in the second month accordingly
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysPerMonth[1] = 29;
    else
        daysPerMonth[1] = 28;

    //Check if the input date is valid and convert it to the short string representation
    if(month < 1 || month > 12 || day < 1 || day > daysPerMonth[month-1] || year < 1 || year > 9999)
        printf("Invalid input date.\n");
    else
    {
        strcpy(monthStr, months[month-1]);
        printf("%s %02d, %04d", monthStr, day, year);
    }

    return 0;
}