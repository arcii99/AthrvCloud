//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 5

typedef struct {
    int id;
    int weight;
    int flight_number;
} baggage;

int main() {

    srand(time(NULL)); // Seed the random number generator
    
    // Initialize baggage array
    baggage bags[MAX_BAGGAGE];
    int num_bags = 0;

    // Initialize flights
    int flights[MAX_FLIGHTS] = {101, 202, 303, 404, 505};
    int num_flights = MAX_FLIGHTS;

    // Populate baggage array with random data
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        bags[i].id = i + 1;
        bags[i].weight = rand() % 50 + 1;
        bags[i].flight_number = flights[rand() % num_flights];
        num_bags++;
    }

    // Print out the original baggage list
    printf("Original baggage list:\n");
    for (int i = 0; i < num_bags; i++) {
        printf("%d,%d,%d\n", bags[i].id, bags[i].weight, bags[i].flight_number);
    }
    printf("\n");

    // Sort the baggage array by flight number
    for (int i = 0; i < num_bags - 1; i++) {
        for (int j = i + 1; j < num_bags; j++) {
            if (bags[i].flight_number > bags[j].flight_number) {
                // Swap i and j
                baggage temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }

    // Print out the sorted baggage list
    printf("Sorted baggage list:\n");
    for (int i = 0; i < num_bags; i++) {
        printf("%d,%d,%d\n", bags[i].id, bags[i].weight, bags[i].flight_number);
    }
    printf("\n");

    // Calculate the total weight of baggage for each flight
    int total_weight[MAX_FLIGHTS] = {0};
    for (int i = 0; i < num_bags; i++) {
        int flight_index = bags[i].flight_number / 100 - 1;
        total_weight[flight_index] += bags[i].weight;
    }

    // Print out the total weight of baggage for each flight
    printf("Total weight of baggage for each flight:\n");
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d: %d kg\n", flights[i], total_weight[i]);
    }

    return 0;
}