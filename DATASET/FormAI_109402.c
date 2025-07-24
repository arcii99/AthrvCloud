//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
    // Get current time
    time_t current_time;
    struct tm *current_tm;
    time(&current_time);
    current_tm = localtime(&current_time);

    printf("Welcome to the Time Travel Simulator!\n\n");

    // Prompt user to enter year to travel to
    int year;
    printf("Enter the year you would like to travel to: ");
    scanf("%d", &year);

    // Check if year is in the past or future
    if (year < current_tm->tm_year + 1900) {
        printf("\nYou are traveling back in time!\n\n");
    } else if (year > current_tm->tm_year + 1900) {
        printf("\nYou are traveling to the future!\n\n");
    } else {
        printf("\nYou are already in the current year!\n\n");
        return 0;
    }

    // Calculate difference in years
    int years_diff = abs(current_tm->tm_year + 1900 - year);

    // Travel through time
    struct tm *time_travel_tm;
    time_t time_travel_time;

    if (year < 1970) {
        // Travel before Unix epoch
        time_travel_tm = localtime(&(time_t){-years_diff * 365 * 24 * 60 * 60});
    } else {
        // Travel after Unix epoch
        time_travel_tm = localtime(&(time_t){years_diff * 365 * 24 * 60 * 60});
    }

    // Print time travel result
    printf("You have arrived in %d.\n", year);
    printf("Current date and time: %s", asctime(current_tm));
    printf("Time after time travel: %s\n", asctime(time_travel_tm));

    return 0;
}