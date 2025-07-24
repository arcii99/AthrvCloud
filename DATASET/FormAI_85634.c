//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Current time
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    printf("Current time is: %s", asctime(local));

    // Time travel input
    int years, months, days, hours, minutes, seconds;
    printf("Enter how far you want to time travel:\n");
    printf("Years: "); scanf("%d", &years);
    printf("Months: "); scanf("%d", &months);
    printf("Days: "); scanf("%d", &days);
    printf("Hours: "); scanf("%d", &hours);
    printf("Minutes: "); scanf("%d", &minutes);
    printf("Seconds: "); scanf("%d", &seconds);

    // Adjust current time
    struct tm traveler = *local;
    traveler.tm_year += years;
    traveler.tm_mon += months;
    traveler.tm_mday += days;
    traveler.tm_hour += hours;
    traveler.tm_min += minutes;
    traveler.tm_sec += seconds;
    time_t travel_time = mktime(&traveler);

    // Time traveled output
    struct tm *travel_local = localtime(&travel_time);
    printf("\nYou have time traveled to: %s", asctime(travel_local));
    printf("The difference from the current time is:\n");
    printf("%d years\n", travel_local->tm_year - local->tm_year);
    printf("%d months\n", travel_local->tm_mon - local->tm_mon);
    printf("%d days\n", travel_local->tm_mday - local->tm_mday);
    printf("%d hours\n", travel_local->tm_hour - local->tm_hour);
    printf("%d minutes\n", travel_local->tm_min - local->tm_min);
    printf("%d seconds\n", travel_local->tm_sec - local->tm_sec);

    return 0;
}