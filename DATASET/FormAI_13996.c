//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up variables for simulation
    int num_bags = 100;
    int num_conveyors = 5;
    int conveyor_cap = 10;
    int min_delay = 1;
    int max_delay = 5;
    srand(time(NULL));

    // Introduce the simulation
    printf("Welcome to the Surreal Airport Baggage Handling Simulation!\n");
    printf("We have 100 bags to process and 5 conveyors with a capacity of 10 each.\n");
    printf("Delays between conveyors can be unpredictable, but range from 1 to 5 seconds.\n");
    printf("Let's get started!\n\n");

    // Initialize conveyors and bags
    int conveyors[num_conveyors][conveyor_cap];
    int num_bags_left = num_bags;
    int current_conveyor = 0;

    for (int i = 0; i < num_conveyors; i++) {
        for (int j = 0; j < conveyor_cap; j++) {
            if (num_bags_left <= 0) {
                conveyors[i][j] = -1;
            } else {
                conveyors[i][j] = rand() % 10 + 1;
                num_bags_left--;
            }
        }
    }

    // Start the simulation
    while (num_bags_left > 0) {
        // Print out the current state of conveyors
        printf("Current conveyor belts:\n");
        for (int i = 0; i < num_conveyors; i++) {
            printf("Conveyor [%d]:", i);
            for (int j = 0; j < conveyor_cap; j++) {
                if (conveyors[i][j] != -1) {
                    printf(" #%d", conveyors[i][j]);
                } else {
                    printf(" -");
                }
            }
            printf("\n");
        }
        printf("\n");

        // Move bags along conveyors
        sleep(min_delay + rand() % max_delay);
        for (int i = 0; i < conveyor_cap; i++) {
            if (conveyors[current_conveyor][i] != -1) {
                if (i == conveyor_cap - 1 || conveyors[current_conveyor][i + 1] != -1) {
                    printf("Bag #%d moved from conveyor [%d] to conveyor [%d].\n", conveyors[current_conveyor][i], current_conveyor, (current_conveyor + 1) % num_conveyors);
                    conveyors[(current_conveyor + 1) % num_conveyors][0] = conveyors[current_conveyor][i];
                    conveyors[current_conveyor][i] = -1;
                    num_bags_left--;
                }
            }
        }
        current_conveyor = (current_conveyor + 1) % num_conveyors;
        printf("\n");
    }
    printf("All bags have been successfully processed through the surreal baggage handling system!\n");

    return 0;
}