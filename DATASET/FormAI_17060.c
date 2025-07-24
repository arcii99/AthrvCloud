//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define MAX_WEIGHT 40

typedef enum {OUTBOUND, INBOUND} FlightDirection;

typedef struct {
    int id;
    int weight;
    FlightDirection direction;
} Baggage;

void printBaggageInfo(Baggage b) {
    char* dir = (b.direction == INBOUND) ? "INBOUND" : "OUTBOUND";
    printf("Baggage ID: %d, Weight: %dkg, Direction: %s\n", b.id, b.weight, dir);
}

int main() {
    srand(time(NULL));

    // Initialize the queue of baggage
    Baggage baggageQueue[NUM_BAGS];
    int numBags = 0;

    // Loop through arrivals and departures
    for (int i = 0; i < 2; i++) {
        FlightDirection direction = (i == 0) ? OUTBOUND : INBOUND;
        printf("\n--- %s FLIGHTS ---\n", (direction == OUTBOUND) ? "OUTBOUND" : "INBOUND");

        // Process the baggage queue
        while (numBags > 0) {
            printf("Processing next baggage...\n");
            Baggage currentBag = baggageQueue[0];
            printBaggageInfo(currentBag);

            // Remove the baggage from the queue
            for (int j = 1; j < numBags; j++) {
                baggageQueue[j - 1] = baggageQueue[j];
            }
            numBags--;

            // Decide whether the baggage is accepted or rejected
            double acceptanceProb = (double)currentBag.weight / MAX_WEIGHT;
            if (acceptanceProb > 1) acceptanceProb = 1; // weight over system capacity
            if (acceptanceProb < 0.3 && rand() % 100 < 50) {
                printf("Baggage ID %d rejected by security.\n", currentBag.id);
                continue;
            }

            // Baggage is accepted, process it and send it on its way
            printf("Baggage ID %d accepted.\n", currentBag.id);
            // code for processing baggage goes here...
        }

        // Generate new baggage for the queue
        printf("Generating new baggage for queue...\n");
        for (int j = 0; j < NUM_BAGS; j++) {
            Baggage newBaggage;
            newBaggage.id = j;
            newBaggage.direction = direction;
            newBaggage.weight = rand() % (MAX_WEIGHT + 1);
            baggageQueue[numBags] = newBaggage;
            numBags++;
            printBaggageInfo(newBaggage);
        }
    }

    return 0;
}