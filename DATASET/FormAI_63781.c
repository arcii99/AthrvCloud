//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 1000
#define MAX_FLIGHTS 10
#define MAX_DESTINATIONS 5

typedef struct {
    int flight_num;
    char destination[50];
    int baggage[MAX_BAGGAGE];
    int num_bags;
} Flight;

typedef struct {
    int bagID;
    int flight_num;
    char destination[50];
    int baggage_weight;
} Baggage;

// Function to generate a random integer within a range
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create an array of flights
    Flight flights[MAX_FLIGHTS];
    int num_flights = rand_range(5, 10); // Randomly generate the number of flights
    printf("Creating %d flights...\n", num_flights);
    for (int i = 0; i < num_flights; i++) {
        flights[i].flight_num = rand_range(1000, 9999); // Generate a random flight number
        sprintf(flights[i].destination, "Destination%d", rand_range(1, MAX_DESTINATIONS)); // Select a random destination
        flights[i].num_bags = rand_range(100, 500); // Generate a random number of bags for the flight
        for (int j = 0; j < flights[i].num_bags; j++) {
            flights[i].baggage[j] = rand_range(1, 50); // Generate a random weight for each bag
        }
    }

    // Create an array of bags
    Baggage bags[MAX_BAGGAGE];
    int num_bags = 0;

    // Simulation loop
    for (int t = 1; t <= 60; t++) {

        // Generate new bags every minute
        int new_bags = rand_range(0, 10);
        for (int i = 0; i < new_bags; i++) {
            bags[num_bags].bagID = num_bags+1;
            bags[num_bags].flight_num = flights[rand_range(0, num_flights-1)].flight_num; // Select a random flight
            sprintf(bags[num_bags].destination, flights[rand_range(0, num_flights-1)].destination); // Select a random destination
            bags[num_bags].baggage_weight = rand_range(1, 50); // Generate a random weight for the bag
            num_bags++;
        }

        // Check in bags for each flight
        for (int i = 0; i < num_flights; i++) {
            int num_checked_bags = 0;
            for (int j = 0; j < num_bags; j++) {
                if (bags[j].flight_num == flights[i].flight_num && strcmp(bags[j].destination, flights[i].destination) == 0) {
                    flights[i].baggage[num_checked_bags] = bags[j].baggage_weight;
                    num_checked_bags++;
                }
            }
            flights[i].num_bags = num_checked_bags;
        }

        // Send bags to their destinations
        for (int i = 0; i < num_flights; i++) {
            printf("Flight %d to %s departing with %d bags: [", flights[i].flight_num, flights[i].destination, flights[i].num_bags);
            for (int j = 0; j < flights[i].num_bags; j++) {
                printf("%d", flights[i].baggage[j]);
                if (j < flights[i].num_bags-1) {
                    printf(", ");
                }
            }
            printf("]\n");
        }
    }

    return 0;
}