//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare constants
#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 10

// Define struct for flight
typedef struct {
    char destination[50];
    int flight_number;
    int num_bags;
    int processing_time;
} Flight;

// Define struct for baggage
typedef struct {
    int bag_id;
    int flight_number;
} Baggage;

// Function declarations
void generate_flights(Flight flights[]);
void process_baggage(Flight flights[], Baggage baggage[], int num_bags);

int main() {
    srand(time(NULL)); // Initialize random number generator

    // Declare variables
    Flight flights[MAX_FLIGHTS];
    Baggage baggage[MAX_BAGGAGE];
    int num_bags = 0;

    // Generate flights
    generate_flights(flights);

    // Process baggage for each flight
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        num_bags += flights[i].num_bags;
        process_baggage(flights, baggage, num_bags);
    }

    // Print processing times for each flight
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d to %s took %d minutes to process %d bags.\n", flights[i].flight_number, flights[i].destination, flights[i].processing_time, flights[i].num_bags);
    }

    return 0;
}

// Function to generate flights
void generate_flights(Flight flights[]) {
    char *destinations[] = {"New York", "London", "Paris", "Tokyo", "Sydney", "Dubai", "Shanghai", "Toronto", "Los Angeles", "San Francisco"};
    int flight_numbers[MAX_FLIGHTS];
    int num_bags;

    // Generate unique flight numbers
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        int unique = 0;
        while (!unique) {
            flight_numbers[i] = rand() % 1000 + 1000; // Generate random 4-digit number
            unique = 1;
            for (int j = 0; j < i; j++) {
                if (flight_numbers[i] == flight_numbers[j]) {
                    unique = 0;
                    break;
                }
            }
        }

        // Initialize flight details
        strcpy(flights[i].destination, destinations[rand() % 10]);
        flights[i].flight_number = flight_numbers[i];
        num_bags = rand() % 50 + 1; // Generate random number of bags between 1 and 50
        flights[i].num_bags = num_bags;
    }
}

// Function to process baggage
void process_baggage(Flight flights[], Baggage baggage[], int num_bags) {
    int processing_time = rand() % 60 + 30; // Generate random processing time between 30 and 90 minutes
    flights[num_bags - 1].processing_time = processing_time; // Set processing time for the current flight
    for (int i = num_bags - flights[num_bags - 1].num_bags; i < num_bags; i++) {
        baggage[i].bag_id = rand() % 100 + 1; // Generate random bag ID between 1 and 100
        baggage[i].flight_number = flights[num_bags - 1].flight_number; // Set the flight number for the bag
    }
}