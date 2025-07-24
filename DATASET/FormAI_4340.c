//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10

struct Baggage {
    int id;
    char dest[50];
    bool isLoaded;
};

struct Flight {
    int id;
    char dest[50];
    int numBags;
    struct Baggage bags[MAX_BAGS];
};

void displayBagDetails(struct Baggage bag) {
    printf("Bag ID: %d\n", bag.id);
    printf("Destination: %s\n", bag.dest);
    printf("Is loaded on flight: %s\n", bag.isLoaded ? "yes" : "no");
}

void displayFlightDetails(struct Flight flight) {
    printf("Flight ID: %d\n", flight.id);
    printf("Destination: %s\n", flight.dest);
    printf("Number of bags: %d\n", flight.numBags);
    printf("Bags: \n");

    for (int i = 0; i < flight.numBags; i++) {
        displayBagDetails(flight.bags[i]);
    }
}

void loadBagOntoFlight(struct Flight *flight, struct Baggage *bag) {
    if (flight->numBags >= MAX_BAGS) {
        printf("Cannot load bag onto flight - baggage capacity exceeded\n");
        return;
    }

    if (strcmp(flight->dest, bag->dest) != 0) {
        printf("Cannot load bag onto flight - destination mismatch\n");
        return;
    }

    for (int i = 0; i < flight->numBags; i++) {
        if (flight->bags[i].id == bag->id) {
            printf("Cannot load bag onto flight - bag already loaded\n");
            return;
        }
    }

    flight->bags[flight->numBags] = *bag;
    flight->bags[flight->numBags].isLoaded = true;
    flight->numBags++;
    printf("Bag with ID %d successfully loaded onto flight with ID %d\n", bag->id, flight->id);
}

int main() {
    struct Flight flights[MAX_FLIGHTS];

    // Initialize flights
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].id = i + 1;
        sprintf(flights[i].dest, "Destination%d", i + 1);
        flights[i].numBags = 0;
    }

    // Initialize bags
    struct Baggage bags[MAX_BAGS];
    for (int i = 0; i < MAX_BAGS; i++) {
        bags[i].id = i + 1;
        sprintf(bags[i].dest, "Destination%d", (i % MAX_FLIGHTS) + 1);
        bags[i].isLoaded = false;
    }

    // Load bags onto flights randomly
    printf("Loading bags onto flights...\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        int flightIndex = rand() % MAX_FLIGHTS;
        loadBagOntoFlight(&flights[flightIndex], &bags[i]);
    }

    // Display details of all flights
    printf("\nFlight Details:\n");
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        displayFlightDetails(flights[i]);
        printf("\n");
    }

    return 0;
}