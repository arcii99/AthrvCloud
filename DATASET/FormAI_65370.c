//FormAI DATASET v1.0 Category: Date and time ; Style: lively
#include <stdio.h>
#include <time.h>

int main()
{
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);                   // Get the current time
    localTime = localtime(&currentTime);  // Convert the current time to the local time

    int day = localTime->tm_mday;          // Get day of the month (1 to 31)
    int month = localTime->tm_mon + 1;     // Get month of year (0 to 11)
    int year = localTime->tm_year + 1900;  // Get year since 1900
    int hour = localTime->tm_hour;         // Get hours since midnight (0 to 23)
    int min = localTime->tm_min;           // Get minutes after the hour (0 to 59)
    int sec = localTime->tm_sec;           // Get second (0 to 59)

    // Display the current date and time
    printf("Current date and time: %02d/%02d/%d %02d:%02d:%02d\n", day, month, year, hour, min, sec);

    // Get the current time in seconds and add one year to it
    time_t nextYearTime = currentTime + (365 * 24 * 60 * 60);
    struct tm *nextYearLocalTime = localtime(&nextYearTime);

    // Display the date and time one year from now
    printf("Date and time one year from now: %02d/%02d/%d %02d:%02d:%02d\n", nextYearLocalTime->tm_mday, 
            nextYearLocalTime->tm_mon + 1, nextYearLocalTime->tm_year + 1900, nextYearLocalTime->tm_hour, 
            nextYearLocalTime->tm_min, nextYearLocalTime->tm_sec);

    return 0;
}