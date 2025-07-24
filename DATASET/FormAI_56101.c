//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void baggageHandler(int time) {
    if (time == 0) {
        printf("\nAll baggage has been handled.\n");
        return;
    } else {
        printf("\nHandling baggage for %d minutes...\n", time);
        baggageHandler(time - 1);
    }
}

int main() {
    int totalTime, timeInterval;

    // Get the total time needed for baggage handling
    printf("Enter the total time (in minutes) needed for baggage handling:\n");
    scanf("%d", &totalTime);

    // Get the time interval needed for each baggage handling cycle
    printf("\nEnter the time interval (in minutes) needed for each baggage handling cycle:\n");
    scanf("%d", &timeInterval);

    // Start the simulation
    printf("\nStarting baggage handling simulation...\n");

    baggageHandler(totalTime/timeInterval);

    printf("\nSimulation complete.\n");

    return 0;
}