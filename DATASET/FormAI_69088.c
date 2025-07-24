//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 10000 // Maximum number of baggage that can be handled
#define MAX_FLIGHTS 100 // Maximum number of flights handled
#define MAX_TIME 240 // Maximum time in minutes for a flight

int main(void) {
    // Set random seed
    srand(time(NULL));

    // Declare variables
    int baggage[MAX_BAGGAGE];
    int flight[MAX_FLIGHTS];
    int flight_time[MAX_FLIGHTS];
    int baggage_count = 0;
    int flight_count = 0;
    int baggage_processed = 0;
    int total_time = 0;

    // Generate baggage and flight information
    for(int i = 0; i < MAX_BAGGAGE; i++) {
        baggage[i] = rand() % 50 + 1; // Baggage weight between 1 and 50 kgs
    }

    for(int i = 0; i < MAX_FLIGHTS; i++) {
        flight[i] = rand() % 1000 + 1; // Flight number between 1 and 1000
        flight_time[i] = rand() % MAX_TIME + 60; // Flight time between 60 to 300 minutes
    }

    // Start processing baggage for all flights
    for(int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Processing baggage for flight %d\n", flight[i]);

        // Start baggage processing timer
        int start_time = time(NULL);

        // Process baggage until flight departure time
        while((time(NULL) - start_time) < (flight_time[i] * 60)) {
            // Check if there is any baggage left to process
            if(baggage_processed == baggage_count) {
                break;
            }

            // Process next baggage
            printf("Processing baggage %d with weight %d kgs\n", baggage_processed + 1, baggage[baggage_processed]);
            baggage_processed++;
        }

        // Calculate total time taken to process baggage for the flight
        int time_taken = time(NULL) - start_time;
        printf("Baggage processing for flight %d completed in %d minutes\n", flight[i], time_taken / 60);

        // Add time taken to total time
        total_time += time_taken;
    }

    // Calculate average time taken to process baggage for all flights
    int avg_time = total_time / flight_count;
    printf("Average baggage processing time for all flights: %d minutes\n", avg_time);

    return 0;
}