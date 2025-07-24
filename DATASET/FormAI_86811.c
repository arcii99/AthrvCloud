//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LUGGAGE_WEIGHT 50 // Maximum weight of a single piece of luggage
#define MAX_BELT_CAPACITY 100 // Maximum capacity of the baggage belt
#define MAX_FLIGHTS 10 // Maximum number of flights per day
#define MAX_PASSENGERS 250 // Maximum number of passengers per flight

int luggageCounter = 0; // Counter to keep track of luggage being processed
int weightOnBelt = 0; // Total weight of luggage on the belt

// Structure to hold information about a passenger
typedef struct {
    char name[50];
    int flightNumber;
    int luggageCount;
    int luggage[MAX_LUGGAGE_WEIGHT];
} Passenger;

// Structure to hold information about a flight's baggage handling
typedef struct {
    int flightNumber;
    int passengersCount;
    Passenger passengers[MAX_PASSENGERS];
} BaggageHandling;

// Function to randomly generate a luggage weight between 1 and MAX_LUGGAGE_WEIGHT
int generateLuggageWeight() {
    return (rand() % MAX_LUGGAGE_WEIGHT) + 1;
}

// Function to add luggage to the belt
void addToBelt(int weight) {
    if (luggageCounter < MAX_BELT_CAPACITY) {
        weightOnBelt += weight;
        luggageCounter++;
    }
}

// Function to remove luggage from the belt
void removeFromBelt(int weight) {
    weightOnBelt -= weight;
    luggageCounter--;
}

// Function to print the status of the baggage belt
void printBeltStatus() {
    printf("Luggage on belt: %d/%d\n", weightOnBelt, MAX_BELT_CAPACITY);
}

// Function to simulate the baggage handling for a flight
void handleFlight(BaggageHandling b) {
    printf("Handling baggage for flight %d with %d passengers...\n", b.flightNumber, b.passengersCount);
    for (int i = 0; i < b.passengersCount; i++) {
        Passenger p = b.passengers[i];
        printf("%s checking in %d pieces of luggage...\n", p.name, p.luggageCount);
        for (int j = 0; j < p.luggageCount; j++) {
            int weight = p.luggage[j];
            printf("Checking in luggage with weight %d...\n", weight);
            if (weightOnBelt + weight <= MAX_BELT_CAPACITY) {
                printf("Adding luggage to the belt...\n");
                addToBelt(weight);
            } else {
                printf("Luggage cannot be added to the belt, please wait...\n");
                while (weightOnBelt + weight > MAX_BELT_CAPACITY) {
                    printf("Waiting for some luggage to be removed from the belt...\n");
                    removeFromBelt(generateLuggageWeight());
                }
                printf("Adding luggage to the belt...\n");
                addToBelt(weight);
            }
            printBeltStatus();
        }
    }
    printf("All baggage for flight %d has been handled.\n", b.flightNumber);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Create some sample flights with passengers and luggage
    BaggageHandling flights[MAX_FLIGHTS];
    int totalLuggageCount = 0;
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        BaggageHandling b;
        b.flightNumber = i + 1;
        b.passengersCount = (rand() % MAX_PASSENGERS) + 1;
        totalLuggageCount += b.passengersCount;
        for (int j = 0; j < b.passengersCount; j++) {
            Passenger p;
            sprintf(p.name, "Passenger %d-%d", b.flightNumber, j + 1);
            p.flightNumber = b.flightNumber;
            p.luggageCount = (rand() % 5) + 1;
            int luggageWeight = 0;
            for (int k = 0; k < p.luggageCount; k++) {
                int weight = generateLuggageWeight();
                p.luggage[k] = weight;
                luggageWeight += weight;
            }
            printf("%s has %d pieces of luggage with total weight %d for flight %d.\n", p.name, p.luggageCount, luggageWeight, b.flightNumber);
            b.passengers[j] = p;
        }
        flights[i] = b;
    }
    
    // Simulate the baggage handling for each flight
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        handleFlight(flights[i]);
    }

    printf("All flights have been handled, total luggage count: %d\n", totalLuggageCount);
    return 0;
}