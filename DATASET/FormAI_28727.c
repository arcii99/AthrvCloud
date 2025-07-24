//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INTERVAL 60 // Time interval in seconds
#define MAX_CARS 100 // Maximum number of cars
#define SIMULATION_TIME 3600 // Simulation time in seconds

int main() {
    int i, j;
    int num_cars = 0;
    int num_arrival = 0;
    int num_departure = 0;
    int queue_length = 0;
    int total_delay = 0;
    int num_served = 0;
    float arrival_prob = 0.25; // Probability of car arrival per second
    float departure_prob = 0.2; // Probability of car departure per second
    float delay[MAX_CARS];
    int time_arrival[MAX_CARS];
    int time_departure[MAX_CARS];
    int queue[MAX_CARS];
    time_t t;
    srand((unsigned) time(&t)); // Initializing random number generator
    
    // Simulating traffic flow
    for (i = 0; i < SIMULATION_TIME; i += INTERVAL) {
        num_arrival = 0;
        num_departure = 0;
        // Calculate number of arrivals and departures in given interval
        for (j = 0; j < INTERVAL; j++) {
            if ((float)rand() / RAND_MAX < arrival_prob) {
                num_arrival++;
            }
            if ((float)rand() / RAND_MAX < departure_prob && num_cars > 0) {
                num_departure++;
            }
        }
        // Add arrived cars to queue
        for (j = 0; j < num_arrival && num_cars < MAX_CARS; j++) {
            queue[num_cars] = i;
            num_cars++;
            queue_length++;
        }
        // Serve departing cars
        for (j = 0; j < num_departure && num_cars > 0; j++) {
            time_departure[num_served] = i;
            total_delay += i - time_arrival[num_served];
            num_cars--;
            queue_length--;
            num_served++;
        }
        // Add delay for waiting cars
        for (j = num_served; j < num_cars; j++) {
            delay[j] += INTERVAL;
        }
    }
    // Print simulation result
    printf("Number of cars served: %d\n", num_served);
    printf("Average delay per car: %.2f seconds\n", (float)total_delay/num_served);
    printf("Maximum queue length: %d\n", queue_length);
    return 0;
}