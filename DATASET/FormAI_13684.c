//FormAI DATASET v1.0 Category: Date and time ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Get the current date and time
    time_t now = time(NULL);

    // Convert the date and time to a struct tm object
    struct tm *current_time = localtime(&now);
    int year = current_time->tm_year + 1900; // Add 1900 to get the actual year
    int month = current_time->tm_mon + 1; // Add 1 to get the actual month
    int day = current_time->tm_mday;
    int hour = current_time->tm_hour;
    int minute = current_time->tm_min;
    int second = current_time->tm_sec;

    // Print the current date and time
    printf("Current date and time: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);

    // Add 24 hours to the current time
    now += 24 * 60 * 60; // 24 hours * 60 minutes * 60 seconds
    current_time = localtime(&now);
    year = current_time->tm_year + 1900;
    month = current_time->tm_mon + 1;
    day = current_time->tm_mday;
    hour = current_time->tm_hour;
    minute = current_time->tm_min;
    second = current_time->tm_sec;

    // Print the new date and time
    printf("Date and time in 24 hours: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);

    // Subtract 48 hours from the current time
    now -= 48 * 60 * 60; // 48 hours * 60 minutes * 60 seconds
    current_time = localtime(&now);
    year = current_time->tm_year + 1900;
    month = current_time->tm_mon + 1;
    day = current_time->tm_mday;
    hour = current_time->tm_hour;
    minute = current_time->tm_min;
    second = current_time->tm_sec;

    // Print the new date and time
    printf("Date and time 48 hours ago: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);

    return 0;
}