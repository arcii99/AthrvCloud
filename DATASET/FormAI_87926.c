//FormAI DATASET v1.0 Category: Date and time ; Style: grateful
#include <stdio.h>
#include <time.h>

int main(void) {
    time_t current_time;
    struct tm *local_time;

    // Get current time
    current_time = time(NULL);

    // Convert current time to local time
    local_time = localtime(&current_time);

    // Display date and time
    printf("Today's date is: %02d/%02d/%04d\n", local_time->tm_mon + 1, local_time->tm_mday, local_time->tm_year + 1900);
    printf("The time is: %02d:%02d:%02d\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

    return 0;
}