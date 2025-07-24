//FormAI DATASET v1.0 Category: Date and time ; Style: single-threaded
#include <stdio.h>
#include <time.h>

int main() {
    time_t curr_time;
    struct tm *current_time;
    char time_buffer[50];

    // Get current time
    curr_time = time(NULL);

    // Convert to local time
    current_time = localtime(&curr_time);

    // Format time string
    strftime(time_buffer, sizeof(time_buffer), "%D %T", current_time);

    // Print current time
    printf("Current date and time: %s\n", time_buffer);

    // Set a future date
    struct tm future_time;
    future_time.tm_sec = 0;
    future_time.tm_min = 0;
    future_time.tm_hour = 0;
    future_time.tm_mday = 1;
    future_time.tm_mon = 0;  // January
    future_time.tm_year = current_time->tm_year + 2;  // 2 years from now
    future_time.tm_isdst = -1;  // Determine daylight saving time automatically

    // Convert future time to seconds since Epoch
    time_t future_time_sec = mktime(&future_time);

    // Sleep until future time
    printf("Sleeping until %s...\n", asctime(&future_time));
    while (curr_time < future_time_sec) {
        curr_time = time(NULL);
    }

    // Print future time
    curr_time = time(NULL);
    current_time = localtime(&curr_time);
    strftime(time_buffer, sizeof(time_buffer), "%D %T", current_time);
    printf("Future date and time: %s\n", time_buffer);

    return 0;
}