//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int bags = 30; // Number of bags to be handled
    int max_weight = 50; // Maximum weight of a bag
    int total_weight = 0; // Total weight of all bags
    int conveyor_capacity = 100; // Maximum capacity of conveyor belt
    int conveyor_weight = 0; // Total weight on conveyor belt
    int security_capacity = 10; // Maximum capacity of security scanner
    int security_weight = 0; // Total weight on security scanner
    int flights = 5; // Number of flights handled by the system
    int current_flight = 1; // Current flight being handled
    int i, j;

    srand(time(NULL)); // Seed random number generator

    for (i = 0; i < flights; i++) { // Loop through each flight
        printf("Starting baggage handling for flight %d\n", current_flight);

        for (j = 0; j < bags; j++) { // Load bags onto conveyor belt
            int weight = rand() % max_weight + 1; // Random bag weight between 1 and max_weight
            total_weight += weight; // Add weight to total
            conveyor_weight += weight; // Add weight to conveyor

            if (conveyor_weight > conveyor_capacity) { // Conveyor belt is full
                printf("Conveyor belt is full, stopping loading\n");
                break;
            }
        }

        if (conveyor_weight > security_capacity) { // Security scanner can't handle all bags
            printf("Security scanner capacity exceeded, stopping baggage handling for this flight\n");
            current_flight++;
            continue;
        }

        for (j = 0; j < bags; j++) { // Scan bags at security checkpoint
            int weight = rand() % max_weight + 1; // Random bag weight between 1 and max_weight
            security_weight += weight; // Add weight to security scanner

            if (security_weight > security_capacity) { // Security scanner is full
                printf("Security scanner is full, stopping scanning\n");
                break;
            }
        }

        printf("All bags for flight %d successfully handled\n", current_flight);
        printf("Total weight of bags: %d\n", total_weight);
        printf("Total weight on conveyor: %d\n", conveyor_weight);
        printf("Total weight on security scanner: %d\n\n", security_weight);

        current_flight++; // Move on to next flight
        conveyor_weight = 0; // Reset conveyor weight
        security_weight = 0; // Reset security weight
    }

    return 0;
}