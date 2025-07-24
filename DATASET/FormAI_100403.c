//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Flight data structure
typedef struct {
    int flightNumber;
    bool hasLuggage;
} Flight;

// Baggage data structure
typedef struct {
    int baggageID;
    int flightNumber;
} Baggage;

// Luggage list
Baggage *luggage;

// Function that simulates baggage handling
void baggageHandling(int numberOfFlights) {
    // Allocate memory for luggage list
    luggage = (Baggage*) malloc(sizeof(Baggage) * numberOfFlights * 10);

    // Simulate baggage handling for each flight
    for (int i = 0; i < numberOfFlights; i++) {
        Flight flight = {i+1, rand()%2};
        printf("Flight %d has %s luggage.\n", flight.flightNumber, flight.hasLuggage ? "some" : "no");
        
        if (flight.hasLuggage) {
            for (int j = 0; j < 10; j++) {
                Baggage baggage = {i*10+j+1, flight.flightNumber};
                luggage[i*10+j] = baggage;
                printf("Flight %d - Baggage ID: %d\n", baggage.flightNumber, baggage.baggageID);
            }
        }
    }

    // Free luggage list memory
    free(luggage);
}

// Main function
int main() {
    // Call baggage handling simulation with 5 flights
    baggageHandling(5);

    return 0;
}