//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PASSENGERS 50
#define NUM_BAGS 100

int main() {
    srand(time(NULL)); // Seed the random number generator

    int bag_count[NUM_PASSENGERS] = {0}; // Keep count of each passenger's bags
    int total_bags = 0; // Keep track of total number of bags

    for (int i = 0; i < NUM_BAGS; i++) {
        int passenger_num = rand() % NUM_PASSENGERS; // Randomly assign a bag to a passenger
        bag_count[passenger_num]++; // Increment the passenger's bag count
        total_bags++; // Increment the total bag count
    }

    printf("There are %d passengers and %d bags.\n\n", NUM_PASSENGERS, NUM_BAGS);

    for (int i = 0; i < NUM_PASSENGERS; i++) {
        printf("Passenger %d has %d bags.\n", i+1, bag_count[i]);
    }

    printf("\nThere are a total of %d bags.\n", total_bags);

    return 0;
}