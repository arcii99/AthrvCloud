//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// A struct to hold the traffic information
typedef struct {
    int cars;
    int bicycles;
    int pedestrians;
} Traffic;

int main() {
    printf("Welcome to the wackiest traffic simulation in town!\n");

    // Initializing the traffic system
    Traffic system = {0, 0, 0};

    for (int time = 0; time < 6; time++) {
        printf("It's now %dAM! Let's see how the traffic flows.\n", time);

        // Simulating cars
        int cars = rand() % 50;
        system.cars += cars;
        printf("%d cars joined the road!\n", cars);

        // Simulating bicycles
        int bicycles = rand() % 25;
        system.bicycles += bicycles;
        printf("%d bicycles joined the road!\n", bicycles);

        // Simulating pedestrians
        int pedestrians = rand() % 100;
        system.pedestrians += pedestrians;
        printf("%d pedestrians on the road! Watch out!\n", pedestrians);

        // Displaying current traffic information
        printf("Current traffic: %d cars, %d bicycles, %d pedestrians.\n", system.cars, system.bicycles, system.pedestrians);

        // Taking a break
        printf("Time for a coffee break!\n");
        sleep(2);
    }

    printf("End of simulation! Thank you for participating.\n");
    return 0;
}