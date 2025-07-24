//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 50
#define MAX_FLIGHTS 10

typedef struct Bag {
    int bagNumber;
    int flightNumber;
    int weight;
} Bag;

typedef struct Flight {
    int flightNumber;
    int numBagsLoaded;
    int totalWeightLoaded;
    bool baggageLoaded;
} Flight;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize an array of Bag structures
    Bag bags[MAX_BAGS];
    for (int i = 0; i < MAX_BAGS; i++) {
        bags[i].bagNumber = i + 1;
        bags[i].weight = rand() % 50 + 1;
        bags[i].flightNumber = rand() % MAX_FLIGHTS + 1;
    }

    // Initialize an array of Flight structures
    Flight flights[MAX_FLIGHTS];
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].flightNumber = i + 1;
        flights[i].numBagsLoaded = 0;
        flights[i].totalWeightLoaded = 0;
        flights[i].baggageLoaded = false;
    }

    // Load the baggage onto the flights
    for (int i = 0; i < MAX_BAGS; i++) {
        int flightNumber = bags[i].flightNumber - 1;
        flights[flightNumber].numBagsLoaded++;
        flights[flightNumber].totalWeightLoaded += bags[i].weight;

        // If all the baggage for a flight has been loaded, set baggageLoaded to true
        if (flights[flightNumber].numBagsLoaded == MAX_BAGS / MAX_FLIGHTS) {
            flights[flightNumber].baggageLoaded = true;
        }
    }

    // Print out the status of each flight
    printf("Flight\tBags Loaded\tWeight Loaded (lbs)\tBaggage Loaded\n");
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("%d\t%d\t\t%d\t\t\t", flights[i].flightNumber, flights[i].numBagsLoaded, flights[i].totalWeightLoaded);
        if (flights[i].baggageLoaded) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}