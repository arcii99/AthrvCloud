//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: rigorous
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;

    char date_string[80];

    // Get the current time
    time(&current_time);

    // Convert it to the local time
    time_info = localtime(&current_time);

    // Convert the time to a string
    strftime(date_string, sizeof(date_string), "%m/%d/%Y %H:%M:%S", time_info);

    printf("Current date and time: %s\n", date_string);

    // Get the future time
    time_t future_time = current_time + (60 * 60 * 24 * 365 * 10); // 10 years from now

    // Convert it to the local time
    time_info = localtime(&future_time);

    // Convert the time to a string
    strftime(date_string, sizeof(date_string), "%m/%d/%Y %H:%M:%S", time_info);

    printf("Future date and time (10 years from now): %s\n", date_string);

    // Get the past time
    time_t past_time = current_time - (60 * 60 * 24 * 365 * 10); // 10 years ago

    // Convert it to the local time
    time_info = localtime(&past_time);

    // Convert the time to a string
    strftime(date_string, sizeof(date_string), "%m/%d/%Y %H:%M:%S", time_info);

    printf("Past date and time (10 years ago): %s\n", date_string);

    return 0;
}