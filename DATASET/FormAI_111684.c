//FormAI DATASET v1.0 Category: Date and time ; Style: satisfied
#include <stdio.h>
#include <time.h>

int main() {
    struct tm tm_time = {0}; // Initialize struct to zero
    time_t time_now; // Declare time_t variable

    // Get current time and store it in time_now
    time(&time_now);

    // Convert time to struct tm
    localtime_r(&time_now, &tm_time);

    // Print the full date and time
    printf("Current date and time: %02d/%02d/%04d %02d:%02d:%02d\n",
           tm_time.tm_mday, tm_time.tm_mon + 1, tm_time.tm_year + 1900,
           tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);

    // Print the date only
    printf("Today's date is: %02d/%02d/%04d\n",
           tm_time.tm_mday, tm_time.tm_mon + 1, tm_time.tm_year + 1900);

    // Print the time only
    printf("The current time is: %02d:%02d:%02d\n",
           tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);

    return 0;
}