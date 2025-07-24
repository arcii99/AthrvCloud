//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm* time_info;
    char* time_str;

    /* Get current time */
    time(&current_time);
    time_info = localtime(&current_time);

    /* Print current time */
    printf("Current Time: %s", asctime(time_info));

    printf("Welcome to the Time Travel Simulator 2000!\n");

    /* Prompt user for year to travel to */
    printf("Enter the year you would like to travel to: ");
    int year;
    scanf("%d", &year);

    /* Check if year is in the future or past */
    if (year < time_info->tm_year + 1900) {
        printf("Sorry, time travel only works to the future!\n");
    } else if (year == time_info->tm_year + 1900) {
        printf("You're already here, silly!\n");
    } else {
        printf("Traveling through time to the year %d!\n", year);

        /* Calculate difference in years */
        int years_diff = year - (time_info->tm_year + 1900);

        /* Add years to current time */
        time_info->tm_year += years_diff;

        /* Normalize time */
        time_t travel_time = mktime(time_info);

        /* Convert back to struct tm */
        time_info = localtime(&travel_time);

        /* Print time after travel */
        printf("You have arrived in the year %d! The date is %s", year, asctime(time_info));
    }

    return 0;
}