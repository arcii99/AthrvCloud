//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 1000 // Maximum number of baggage that can be handled
#define MAX_DELAY 5 // Maximum delay time for handling the baggage

// Enum to represent the status of baggage
typedef enum {
    NOT_ARRIVED,
    ARRIVED,
    BEING_HANDLED,
    HANDLED
} BaggageStatus;

// Structure to represent a single baggage
typedef struct {
    int id;
    BaggageStatus status;
} Baggage;

// Array to store all the baggages
Baggage baggages[MAX_BAGGAGE];

// Function to randomly generate the baggages
void generateBaggages() {
    int i;
    for (i = 0; i < MAX_BAGGAGE; i++) {
        baggages[i].id = i + 1;
        baggages[i].status = NOT_ARRIVED;
    }
}

// Function to handle a single baggage
void handleBaggage(Baggage* baggage) {
    printf("Handling Baggage %d\n", baggage->id);
    baggage->status = BEING_HANDLED;
    int delay = rand() % MAX_DELAY + 1;
    printf("Delay of %d seconds\n", delay);
    sleep(delay);
    baggage->status = HANDLED;
    printf("Baggage %d handled\n", baggage->id);
}

// Function to handle all the baggages
void handleAllBaggages() {
    int i;
    for (i = 0; i < MAX_BAGGAGE; i++) {
        if (baggages[i].status == ARRIVED) {
            handleBaggage(&baggages[i]);
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the baggages
    generateBaggages();

    int totalBaggages = MAX_BAGGAGE;
    int handledBaggages = 0;

    // Loop until all the baggages are handled
    while (handledBaggages < totalBaggages) {
        // Generate a random number of baggages to arrive
        int baggagesToArrive = rand() % (totalBaggages - handledBaggages) + 1;

        int i;
        for (i = 0; i < baggagesToArrive; i++) {
            // Find the first NOT_ARRIVED baggage and set its status to ARRIVED
            int j;
            for (j = 0; j < MAX_BAGGAGE; j++) {
                if (baggages[j].status == NOT_ARRIVED) {
                    baggages[j].status = ARRIVED;
                    handledBaggages++;
                    printf("Baggage %d arrived\n", baggages[j].id);
                    break;
                }
            }
        }

        // Handle the arrived baggages
        handleAllBaggages();
    }

    printf("All baggages handled\n");

    return 0;
}