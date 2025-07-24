//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <time.h>

unsigned long long timetravel(unsigned long long current_time)
{
    unsigned long long destination_time;
    printf("Enter the year you want to travel back to: ");
    scanf("%llu", &destination_time);

    if (current_time < destination_time)
    {
        printf("Sorry, time only flows forward. You can't go to the future.\n");
        return current_time;
    }

    printf("Calculating time travel distance...\n");
    unsigned long long distance = current_time - destination_time;
    printf("Time travel distance: %llu years\n", distance);

    printf("Adjusting time travel...\n");
    unsigned long long time_travel_time = current_time - distance;

    printf("Time travel complete! You have arrived in the year %llu.\n", destination_time);
    return destination_time;
}

int main()
{
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Initializing time travel...\n");

    // Set the current time as the time when the program runs
    time_t current_time = time(NULL);
    printf("Current year: %llu\n", (unsigned long long)current_time);

    unsigned long long new_time = timetravel(current_time);

    printf("Your current year is now: %llu\n", new_time);

    printf("Thank you for using the Time Travel Simulator.\n");
    return 0;
}