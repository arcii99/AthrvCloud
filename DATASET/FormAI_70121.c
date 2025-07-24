//FormAI DATASET v1.0 Category: Date and time ; Style: enthusiastic
/* Welcome to my exciting date and time program! */
#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *current_time;
    char time_string[25];

    // Get the current time
    time(&now);
    current_time = localtime(&now);

    // Format the time string
    strftime(time_string, 25, "%Y-%m-%d %H:%M:%S", current_time);

    // Print the date and time
    printf("Today is %s\n", time_string);

    // Calculate the time 24 hours from now
    now += 24 * 60 * 60; // add one day (in seconds)
    current_time = localtime(&now);

    // Format the time string
    strftime(time_string, 25, "%Y-%m-%d %H:%M:%S", current_time);

    // Print the new date and time
    printf("24 hours from now it will be %s\n", time_string);

    // Calculate the time 1 week and 5 days from now
    now += (7 * 24 + 5) * 60 * 60; // add 1 week and 5 days (in seconds)
    current_time = localtime(&now);

    // Format the time string
    strftime(time_string, 25, "%Y-%m-%d %H:%M:%S", current_time);

    // Print the new date and time
    printf("1 week and 5 days from now it will be %s\n", time_string);

    return 0;
}