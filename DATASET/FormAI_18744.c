//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int year, month, day;
    char date[15], monthStr[15], dayStr[15], yearStr[15];
    printf("Enter a date (MM/DD/YYYY): ");
    fgets(date, 15, stdin);

    // Extract month from user input
    strncpy(monthStr, date, 2);
    monthStr[2] = '\0';
    month = atoi(monthStr);

    // Extract day from user input
    strncpy(dayStr, date + 3, 2);
    dayStr[2] = '\0';
    day = atoi(dayStr);

    // Extract year from user input
    strncpy(yearStr, date + 6, 4);
    yearStr[4] = '\0';
    year = atoi(yearStr);

    // Convert month from number to word
    char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char* monthName = months[month - 1];

    // Convert year to post-apocalyptic style
    char yearPostAp[15];
    sprintf(yearPostAp, "%d%s", year - 2000, " BP");

    printf("The converted date is: %s %d, %s\n", monthName, day, yearPostAp);

    return 0;
}