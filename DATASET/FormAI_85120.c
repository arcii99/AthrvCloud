//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000 // Maximum number of events to store
#define THRESHOLD 5 // Limit of failed login attempts to detect intrusion

int main() {
    char events[MAX_EVENTS][100]; // Array to store events
    int num_events = 0; // Number of events stored
    srand(time(NULL)); // Set random seed based on current time

    while (1) { // Infinite loop to simulate events
        int r = rand() % 10; // Generate a random number from 0 to 9
        if (r < 3) { // 30% chance of failed login attempt
            sprintf(events[num_events], "Failed login attempt #%d", r+1); // Store event in array
            num_events++; // Increment number of events stored
            if (num_events == MAX_EVENTS) { // Check if array is full
                printf("Intrusion detected!\n");
                break; // Exit program if intrusion detected
            }
        }
        else { // 70% chance of successful event
            printf("Success!\n");
        }
        sleep(1); // Wait for 1 second
    }

    return 0;
}