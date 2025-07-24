//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struct for the baggage
typedef struct {
    int id;
    float weight;
} Baggage;

// function to generate random baggage
Baggage generateBaggage(int id) {
    Baggage baggage;
    baggage.id = id;
    baggage.weight = (float)(rand() % 100 + 1) / 10;
    return baggage;
}

int main() {
    srand(time(NULL)); // seed for random number generator

    int numBaggage = 10; // number of baggage to process
    Baggage *baggageList = malloc(sizeof(Baggage) * numBaggage); // allocate memory for list of baggage

    // generate random baggage
    for (int i = 0; i < numBaggage; i++) {
        baggageList[i] = generateBaggage(i + 1);
    }

    // simulate baggage handling
    for (int i = 0; i < numBaggage; i++) {
        printf("Processing baggage %d with weight %.1f kg\n", baggageList[i].id, baggageList[i].weight);

        // check weight of baggage
        if (baggageList[i].weight > 30.0) {
            printf("Baggage exceeds maximum weight limit\n");
            continue;
        }

        // send baggage to loading area
        printf("Sending baggage %d to loading area\n", baggageList[i].id);
    }

    free(baggageList); // free memory

    return 0;
}