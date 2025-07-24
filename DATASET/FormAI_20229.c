//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm * time_info;
    char time_string[100];

    // get current time
    time(&current_time);
    time_info = localtime(&current_time);

    // prompt user to enter future year
    printf("Enter a future year (YYYY): ");
    int future_year;
    scanf("%d", &future_year);

    // calculate difference in years
    int years_diff = future_year - (time_info->tm_year + 1900);

    // simulate time travel!
    printf("\n\nYou're about to time travel %d years into the %s.\nPress any key to start simulation...\n", abs(years_diff), years_diff > 0 ? "future" : "past");
    getchar(); // wait for user to press a key

    if (years_diff > 0) { // time travel to the future
        printf("\nSimulating time travel to %d...\n", future_year);
        while (time_info->tm_year + 1900 < future_year) { // keep advancing year until we reach the future year
            time_t new_time = current_time + 31536000; // add one year worth of seconds (365 days * 24 hours * 60 minutes * 60 seconds)
            current_time = new_time;
            time_info = localtime(&current_time);
            strftime(time_string, sizeof(time_string), "%Y", time_info);
            printf("Year: %s\n", time_string);
        }
        printf("\nYou have arrived in the year %d!\n", future_year);
    } else { // time travel to the past
        printf("\nSimulating time travel to %d...\n", future_year);
        while (time_info->tm_year + 1900 > future_year) { // keep going back in time until we reach the past year
            time_t new_time = current_time - 31536000; // subtract one year worth of seconds (365 days * 24 hours * 60 minutes * 60 seconds)
            current_time = new_time;
            time_info = localtime(&current_time);
            strftime(time_string, sizeof(time_string), "%Y", time_info);
            printf("Year: %s\n", time_string);
        }
        printf("\nYou have arrived in the year %d!\n", future_year);
    }

    return 0;
}