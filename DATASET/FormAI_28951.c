//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate the traffic light cycles
void trafficLightCycle(int cycle) {
    if (cycle == 0) {
        printf("GREEN LIGHT ON\n");
        trafficLightCycle(cycle + 1);
    } else if (cycle == 1) {
        printf("YELLOW LIGHT ON\n");
        trafficLightCycle(cycle + 1);
    } else if (cycle == 2) {
        printf("RED LIGHT ON\n");
        trafficLightCycle(cycle + 1);
    } else {
        // Reset the cycle back to 0
        cycle = 0;
        printf("TRAFFIC LIGHT CYCLE COMPLETE\n");
        // Wait for a random time before starting the next cycle
        int waitTime = rand() % 5 + 1; // Wait for 1-5 seconds
        printf("WAIT FOR %d SECONDS...\n", waitTime);
        sleep(waitTime);
        // Start the next traffic light cycle
        trafficLightCycle(cycle);
    }
}

int main() {
    printf("TRAFFIC LIGHT CONTROLLER\n");
    printf("-----------------------\n");
    srand(time(NULL)); // Set seed for random number generation
    trafficLightCycle(0); // Start the traffic light cycle
    return 0;
}