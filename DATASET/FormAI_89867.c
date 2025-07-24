//FormAI DATASET v1.0 Category: Date and time ; Style: portable
#include <stdio.h>
#include <time.h>

int main()
{
    time_t now; /* initialize time_t variable */
    struct tm *current_time; /* initialize struct tm variable */
    char time_string[25]; /* initialize char array for string output */
    int year, month, day, hour, minute, second; /* initialize integer variables for date and time */

    /* Get the current time */
    time(&now); 

    /* Convert the current time to local time */
    current_time = localtime(&now);

    /* Get the values for year, month, and day */
    year = current_time->tm_year + 1900;
    month = current_time->tm_mon + 1;
    day = current_time->tm_mday;

   /* Get the values for hour, minute, and second */
    hour = current_time->tm_hour;
    minute = current_time->tm_min;
    second = current_time->tm_sec;

    /* Format the string output with the date and time values */
    sprintf(time_string, "%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);

    /* Print the formatted string output */
    printf("The current date and time is: %s\n", time_string);

    return 0;
}