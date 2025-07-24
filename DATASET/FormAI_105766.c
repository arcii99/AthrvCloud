//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: expert-level
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *timeinfo;
    char buffer[80];

    // Get the current time
    time(&current_time);

    // Convert current time to local time
    timeinfo = localtime(&current_time);

    // Get the current year, month, and day
    int current_year = timeinfo->tm_year + 1900;
    int current_month = timeinfo->tm_mon + 1;
    int current_day = timeinfo->tm_mday;

    // Ask the user to enter a future date
    int future_year, future_month, future_day;
    printf("Enter a future date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &future_year, &future_month, &future_day);

    // Convert future date to UNIX timestamp
    struct tm future_timeinfo = {
        .tm_year = future_year - 1900,
        .tm_mon = future_month - 1,
        .tm_mday = future_day
    };
    time_t future_time = mktime(&future_timeinfo);

    // Calculate the number of years, months, and days between current and future date
    int years = (int)((future_time - current_time) / (60 * 60 * 24 * 365.2425));
    int months = (int)(((future_time - current_time) / (60 * 60 * 24 * 30.436875)) - (years * 12));
    int days = (int)((future_time - current_time) / (60 * 60 * 24)) - ((years * 365.2425) + (months * 30.436875));

    // Print the time difference
    printf("Time difference between %d-%d-%d and %d-%d-%d: %d years, %d months, and %d days",
        current_year, current_month, current_day,
        future_year, future_month, future_day,
        years, months, days);

    return 0;
}