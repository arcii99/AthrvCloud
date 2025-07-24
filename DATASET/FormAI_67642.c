//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define constants
    const int YEAR_START = 2021;
    const int YEAR_END = 2041;
    const int MONTH_RANGE = 12;
    const int DAY_RANGE = 31;

    // Initialize variables
    int year, month, day;
    time_t current_time;
    struct tm * timeinfo;

    // Get current time
    time(&current_time);
    timeinfo = localtime(&current_time);

    // Display current time
    printf("Current date: %02d/%02d/%d\n\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);

    // Get input from user
    printf("Enter a date to travel to (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Check input validity
    if (year < YEAR_START || year > YEAR_END || month < 1 || month > MONTH_RANGE || day < 1 || day > DAY_RANGE) {
        printf("Invalid input!\n");
        return 0;
    }

    printf("\nTraveling to %02d/%02d/%d...\n\n", day, month, year);

    // Set new time
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    // Convert new time to Unix time
    current_time = mktime(timeinfo);

    // Set system time to new time
    printf("Setting system clock to %02d/%02d/%d...\n", day, month, year);
    set_time(current_time);
    printf("System clock set!\n");

    return 0;
}

void set_time(time_t new_time) {
    struct timespec ts;
    ts.tv_sec = new_time;
    ts.tv_nsec = 0;
    clock_settime(CLOCK_REALTIME, &ts);
}