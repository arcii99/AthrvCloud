//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int year, month, day, hour, minute, second;
    struct tm timestamp;
    char timezone[5];

    // Get current time
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    
    printf("Welcome to the Time Travel Simulator 3000!\n");
    printf("Enter the date and time you wish to travel to (YYYY-MM-DD HH:MM:SS): ");
    scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
    printf("Enter your target timezone (4-letter code): ");
    scanf("%s", timezone);

    // Set time and timezone
    timestamp.tm_year = year - 1900;
    timestamp.tm_mon = month - 1;
    timestamp.tm_mday = day;
    timestamp.tm_hour = hour;
    timestamp.tm_min = minute;
    timestamp.tm_sec = second;
    timestamp.tm_isdst = -1;
    setenv("TZ", timezone, 1);
    tzset();

    // Calculate time difference and display result
    time_t target = mktime(&timestamp);
    int diff = difftime(target, now);

    if (diff > 0) {
        printf("Preparing to travel to your destination...\n");
        printf("Estimated travel time: %d seconds\n", diff);
    } else {
        printf("Error: You cannot travel back in time!\n");
    }

    return 0;
}