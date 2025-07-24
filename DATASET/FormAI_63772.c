//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <time.h>

// Function to simulate time travel
void time_travel(int year) {

    struct tm time_now = {0};
    time_t current_time;

    // Get the current time
    current_time = time(NULL);
    localtime_r(&current_time, &time_now);

    // Set the year to travel to
    time_now.tm_year = year - 1900;

    // Normalize the time
    mktime(&time_now);

    printf("You have traveled to %d!\n", year);
    printf("The date is: %s\n", asctime(&time_now));
}

// Main program
int main() {

    int year;

    // Get the year the user wants to travel to
    printf("Enter the year you want to travel to: ");
    scanf("%d", &year);

    // Call the time travel function
    time_travel(year);

    return 0;
}