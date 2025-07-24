//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50
#define MAX_FLIGHTS 15

// Define structs for flights and bags
typedef struct {
    char* airline;
    int flightNumber;
    char* destination;
    int numBags;
    int bagsProcessed;
} Flight;

typedef struct {
    int flightNumber;
    int bagID;
    int status; // 0 for unchecked, 1 for approved, -1 for rejected
} Baggage;

// Define functions
void displayArrivals(Flight flights[], int numFlights);
void simulateBaggageHandling(Flight* flight, Baggage* bags, int numBags);

int main() {
    srand(time(NULL)); // Set random seed

    // Create array of flights
    Flight flights[MAX_FLIGHTS] = {
        {"Delta", 1120, "Atlanta", 25, 0},
        {"Southwest", 2324, "Las Vegas", 30, 0},
        {"American Airlines", 789, "Chicago", 40, 0},
        {"United Airlines", 450, "New York", 20, 0},
        {"Alaska Airlines", 1980, "Seattle", 35, 0}
    };
    int numFlights = 5;

    // Create array of bags
    Baggage bags[MAX_BAGS] = {0};
    int numBags = 0;

    // Simulation loop
    for (int i = 0; i < numFlights; i++) {
        Flight* currentFlight = &flights[i];

        // Add bags to array
        for (int j = 0; j < currentFlight->numBags; j++) {
            bags[numBags].flightNumber = currentFlight->flightNumber;
            bags[numBags].bagID = numBags + 1;
            numBags++;
        }

        // Simulate baggage handling for current flight
        simulateBaggageHandling(currentFlight, bags, numBags);

        // Display final count of processed bags for current flight
        printf("%s Flight %d processed %d bags.\n\n", currentFlight->airline, currentFlight->flightNumber, currentFlight->bagsProcessed);
    }

    // Display final list of arrivals
    displayArrivals(flights, numFlights);

    return 0;
}

void simulateBaggageHandling(Flight* flight, Baggage* bags, int numBags) {
    printf("Processing bags for %s Flight %d.\n", flight->airline, flight->flightNumber);

    // Randomly approve or reject bags
    for (int i = 0; i < numBags; i++) {
        if (rand() % 2 == 0) {
            bags[i].status = 1;
            flight->bagsProcessed++;
        } else {
            bags[i].status = -1;
        }

        // Display status of current bag
        switch (bags[i].status) {
            case 0:
                printf("Bag %d for Flight %d is not checked.\n", bags[i].bagID, bags[i].flightNumber);
                break;
            case 1:
                printf("Bag %d for Flight %d is approved.\n", bags[i].bagID, bags[i].flightNumber);
                break;
            case -1:
                printf("Bag %d for Flight %d is rejected.\n", bags[i].bagID, bags[i].flightNumber);
                break;
        }
    }

    printf("\n");
}

void displayArrivals(Flight flights[], int numFlights) {
    printf("Arrivals:\n");
    printf("Airline\tFlight\tDestination\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < numFlights; i++) {
        Flight f = flights[i];
        printf("%s\t%d\t%s\n", f.airline, f.flightNumber, f.destination);
    }
}