//FormAI DATASET v1.0 Category: Date and time ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int day, month, year, hour, minute, second;
    time_t current_time; 

    // Get the current time
    current_time = time(NULL);

    // Convert the current time to a local time
    struct tm *local_time = localtime(&current_time);

    // Get the individual components of the local time
    day = local_time->tm_mday;
    month = local_time->tm_mon + 1; // tm_mon is 0-based
    year = local_time->tm_year + 1900; // tm_year is years since 1900
    hour = local_time->tm_hour;
    minute = local_time->tm_min;
    second = local_time->tm_sec;

    // Print the current time in a human-readable format
    printf("Current Date and Time: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);

    // Add one day to the current time
    current_time += 86400;

    // Convert the updated time to a local time
    struct tm *updated_time = localtime(&current_time);

    // Get the individual components of the updated time
    day = updated_time->tm_mday;
    month = updated_time->tm_mon + 1; // tm_mon is 0-based
    year = updated_time->tm_year + 1900; // tm_year is years since 1900
    hour = updated_time->tm_hour;
    minute = updated_time->tm_min;
    second = updated_time->tm_sec;

    // Print the updated time in a human-readable format
    printf("Updated Date and Time: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);

    return 0;
}