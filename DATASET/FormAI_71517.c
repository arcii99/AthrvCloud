//FormAI DATASET v1.0 Category: Date and time ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>

int main() {
    // Get current time
    time_t now = time(NULL);

    // Convert current time to local time
    struct tm *local_time = localtime(&now);

    // Print current date and time
    printf("Current date and time: %s", asctime(local_time));

    // Get current year
    int year = local_time->tm_year + 1900;

    // Get current month
    int month = local_time->tm_mon + 1;

    // Get current day
    int day = local_time->tm_mday;

    // Get current hour
    int hour = local_time->tm_hour;

    // Get current minute
    int minute = local_time->tm_min;

    // Get current second
    int second = local_time->tm_sec;

    // Print current date and time components
    printf("Current year: %d\n", year);
    printf("Current month: %d\n", month);
    printf("Current day: %d\n", day);
    printf("Current hour: %d\n", hour);
    printf("Current minute: %d\n", minute);
    printf("Current second: %d\n", second);

    return 0;
}