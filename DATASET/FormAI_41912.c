//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: rigorous
#include <stdio.h>
#include <time.h>

int main() {
    // Get current time
    time_t cur_time;
    time(&cur_time);

    // Set the time for travel
    struct tm travel_time;
    travel_time.tm_year = 2112 - 1900; // 112 years in the future
    travel_time.tm_mon = 6; // July
    travel_time.tm_mday = 13;
    travel_time.tm_hour = 10;
    travel_time.tm_min = 0;
    travel_time.tm_sec = 0;
    travel_time.tm_isdst = 0; // No daylight saving time

    // Convert travel time to time_t
    time_t travel_time_t = mktime(&travel_time);

    // Calculate time difference
    double time_diff = difftime(travel_time_t, cur_time);

    printf("Current time: %s", ctime(&cur_time));
    printf("Travel time: %s", ctime(&travel_time_t));
    printf("Time difference: %.0f seconds\n", time_diff);

    // Travel to the future
    double i;
    for (i = 0; i < time_diff; i++) {
        // Do something exciting while waiting
    }

    printf("Welcome to the future!\n");

    return 0;
}