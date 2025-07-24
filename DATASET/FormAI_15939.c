//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: portable
#include <stdio.h>
#include <time.h>

int main() {
    // Get the current time
    time_t current_time;
    time(&current_time);

    // Display the current time
    printf("Current time: %s", ctime(&current_time));

    // Set the time for 1 hour ago
    struct tm* timeinfo = localtime(&current_time);
    timeinfo->tm_hour -= 1;
    time_t travel_time = mktime(timeinfo);

    // Display the time 1 hour ago
    printf("Time 1 hour ago: %s", ctime(&travel_time));

    // Set the time for 24 hours in the future
    timeinfo->tm_hour += 25;
    time_t future_time = mktime(timeinfo);

    // Display the time 24 hours in the future
    printf("Time 24 hours in the future: %s", ctime(&future_time));

    return 0;
}