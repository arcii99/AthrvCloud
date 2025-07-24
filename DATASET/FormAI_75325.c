//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    char* time_string;

    // Get the current time
    time(&current_time);

    // Convert the current time to the local time
    time_info = localtime(&current_time);

    // Convert the local time to a string
    time_string = asctime(time_info);

    // Print the current time
    printf("Current time: %s\n", time_string);

    // Set the time to January 1, 1900 at 12:00:00 AM
    time_info->tm_year = 0;
    time_info->tm_mon = 0;
    time_info->tm_mday = 1;
    time_info->tm_hour = 0;
    time_info->tm_min = 0;
    time_info->tm_sec = 0;
    current_time = mktime(time_info);

    // Convert the new time to a string
    time_string = asctime(localtime(&current_time));

    // Print the new time
    printf("Time travel back to January 1, 1900: %s\n", time_string);

    return 0;
}