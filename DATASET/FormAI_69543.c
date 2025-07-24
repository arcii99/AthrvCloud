//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50
#define MAX_CHECKPOINTS 5

typedef struct {
    int id;
    int weight;
} Baggage;

typedef struct {
    int id;
    int position;
} Checkpoint;

int main() {
    srand(time(0));
    int numBags = rand() % MAX_BAGS;
    Baggage bags[MAX_BAGS];
    for (int i = 0; i < numBags; i++) {
        Baggage bag;
        bag.id = i + 1;
        bag.weight = rand() % 50;
        bags[i] = bag;
    }
    printf("Number of bags: %d\n", numBags);

    Checkpoint checkpoints[MAX_CHECKPOINTS];
    for (int i = 0; i < MAX_CHECKPOINTS; i++) {
        Checkpoint cp;
        cp.id = i + 1;
        cp.position = rand() % numBags;
        checkpoints[i] = cp;
        printf("Checkpoint %d is handling bags from %d to %d\n", cp.id, cp.position, numBags - 1);
    }

    for (int i = 0; i < MAX_CHECKPOINTS; i++) {
        Checkpoint cp = checkpoints[i];
        printf("\nCheckpoint %d is handling:\n", cp.id);
        for (int j = cp.position; j < numBags; j++) {
            Baggage bag = bags[j];
            printf("Bag %d with weight %d\n", bag.id, bag.weight);
        }
    }

    return 0;
}