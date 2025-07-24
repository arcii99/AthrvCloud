//FormAI DATASET v1.0 Category: Date and time ; Style: calm
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time; // Create a variable to hold the current time
    struct tm* time_info; // Create a struct to hold time information

    time(&current_time); // Get the current time
    time_info = localtime(&current_time); // Break down the current time into its components

    printf("The date and time are: %s", asctime(time_info)); // Print the date and time

    // Print the individual components of the date and time
    printf("Year: %d\n", time_info->tm_year + 1900); // Add 1900 since struct tm counts years since 1900
    printf("Month: %d\n", time_info->tm_mon + 1); // Add 1 since struct tm counts months from 0
    printf("Day: %d\n", time_info->tm_mday);
    printf("Hour: %d\n", time_info->tm_hour);
    printf("Minute: %d\n", time_info->tm_min);
    printf("Second: %d\n", time_info->tm_sec);

    return 0;
}