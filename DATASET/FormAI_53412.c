//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting initial time to present time
    time_t present_time;
    time(&present_time);

    // Displaying current time
    printf("Present time is: %s", ctime(&present_time));

    // Prompting user to input the time travel mode
    printf("\nEnter the time travel mode:\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    int time_travel_mode;
    scanf("%d", &time_travel_mode);
    
    // Prompting user to input the number of years to travel
    printf("\nEnter the number of years to travel: ");
    int years_to_travel;
    scanf("%d", &years_to_travel);
    
    // Calculating time to travel
    time_t time_to_travel;
    if (time_travel_mode == 1) {
        time_to_travel = present_time - (years_to_travel * 365 * 24 * 60 * 60);
    } else if (time_travel_mode == 2) {
        time_to_travel = present_time + (years_to_travel * 365 * 24 * 60 * 60);
    }

    // Displaying travel time
    printf("\nTraveling to %d years in the %s...\n", years_to_travel, (time_travel_mode == 1) ? "past" : "future");
    
    // Waiting for 3 seconds to simulate time travel
    printf("\nSimulating time travel...\n");
    for (int i = 3; i >= 1; i--) {
        printf("%d...", i);
        sleep(1);
    }
    
    // Displaying travel time
    printf("\n\nYou have arrived at %s", ctime(&time_to_travel));

    return 0;
}