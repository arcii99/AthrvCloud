//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 100 // maximum number of bags allowed
#define MAX_WEIGHT 500 // maximum weight of a single bag

typedef struct {
    int bagID; // bag ID
    int weight; // weight of bag
} Baggage;

int main() {
    srand(time(NULL)); // seed random number generator with current time

    // initialize array of bags
    Baggage bags[MAX_BAGS];
    for (int i = 0; i < MAX_BAGS; i++) {
        bags[i].bagID = i + 1;
        bags[i].weight = rand() % MAX_WEIGHT + 1;
    }

    // initialize conveyor belt
    bool conveyorBelt[MAX_WEIGHT] = { false };
    int currentWeight = 0;

    // add bags to conveyor belt
    printf("Adding bags to conveyor belt...\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        if (currentWeight + bags[i].weight <= MAX_WEIGHT) {
            conveyorBelt[bags[i].weight] = true;
            currentWeight += bags[i].weight;
            printf("Bag %d added to conveyor belt\n", bags[i].bagID);
        } else {
            printf("Conveyor belt is full. Cannot add bag %d with weight %d\n", bags[i].bagID, bags[i].weight);
        }
    }

    // process bags on conveyor belt
    printf("\nProcessing bags on conveyor belt...\n");
    for (int i = 1; i <= MAX_WEIGHT; i++) {
        if (conveyorBelt[i]) {
            printf("Bag with weight %d processed\n", i);
        }
    }

    printf("\nAll bags have been processed\n");

    return 0;
}