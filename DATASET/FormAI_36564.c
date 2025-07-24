//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Get the current time
    time_t current_time = time(NULL);

    // Convert the current time to a struct tm
    struct tm *current_tm = localtime(&current_time);

    // Set a random date in the past
    struct tm past_tm = {
        .tm_year = current_tm->tm_year - rand() % 50,
        .tm_mon = rand() % 12,
        .tm_mday = rand() % 31 + 1,
        .tm_hour = rand() % 24,
        .tm_min = rand() % 60,
        .tm_sec = rand() % 60,
    };

    // Convert the past time to a time_t
    time_t past_time = mktime(&past_tm);

    // Calculate the difference between the current time and the past time
    double time_diff = difftime(current_time, past_time);

    // Print the time difference in a human-readable format
    printf("You have traveled %g seconds back in time.\n", time_diff);

    return 0;
}