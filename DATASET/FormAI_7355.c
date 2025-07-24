//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    int year, month, day;
    printf("Enter a date (yyyy-mm-dd): ");
    scanf("%d-%d-%d", &year, &month, &day);

    struct tm travel_time = {0};
    travel_time.tm_year = year - 1900;
    travel_time.tm_mon = month - 1;
    travel_time.tm_mday = day;

    time_t travel_time_t = mktime(&travel_time);

    // Calculate time difference in seconds
    double diff_seconds = difftime(travel_time_t, now);

    // Adjust time difference by taking into account time travel
    // direction and speed
    diff_seconds *= -1;
    diff_seconds /= 2;

    // Add time difference to current time
    time_t final_time_t = now + diff_seconds;

    // Convert final time to local time format
    struct tm *final_tm = localtime(&final_time_t);

    // Print final time
    printf("After time travel, it's now %d-%02d-%02d %02d:%02d:%02d\n",
           final_tm->tm_year + 1900,
           final_tm->tm_mon + 1,
           final_tm->tm_mday,
           final_tm->tm_hour,
           final_tm->tm_min,
           final_tm->tm_sec);

    return 0;
}