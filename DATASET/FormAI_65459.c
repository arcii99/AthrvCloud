//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t curr_time;
    struct tm * timeinfo;
    char time_str[80];

    // Getting current time in UTC
    time(&curr_time);
    timeinfo = gmtime(&curr_time);

    // Setting the time back 100 years
    timeinfo->tm_year -= 100;
    curr_time = mktime(timeinfo);

    // Converting the time to a string for output
    strftime(time_str, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("Starting the time travel simulator...\n");
    printf("Current time: %s\n", time_str);

    // Looping through years and printing out the time
    for (int i = 0; i <= 100; i++) {
        curr_time += (365 * 24 * 60 * 60); // Adding one year in seconds
        timeinfo = gmtime(&curr_time);
        strftime(time_str, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
        printf("Year %d: %s\n", i, time_str);
    }

    printf("Time travel complete!\n");
    return 0;
}