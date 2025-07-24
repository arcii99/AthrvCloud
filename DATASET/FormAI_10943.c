//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <time.h>

void time_travel(int years) {
    time_t raw_time;
    struct tm *time_info;

    // Get the current time
    time(&raw_time);
    time_info = localtime(&raw_time);

    // Subtract the given number of years from the current year
    time_info->tm_year -= years;

    // Normalize the new date/time so it falls within the valid range
    mktime(time_info);

    // Print the new date/time
    printf("Time travel successful! The date is now: %s", asctime(time_info));
}

int main() {
    int years;

    // Prompt the user for the number of years to travel
    printf("Enter the number of years to travel: ");
    scanf("%d", &years);

    // Perform the time travel
    time_travel(years);

    return 0;
}