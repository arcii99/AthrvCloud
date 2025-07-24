//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the maximum number of bags that can be processed
#define MAX_BAGS 1000

// structure for a single bag
typedef struct {
    int id; // unique identifier for the bag
    int weight; // weight of the bag in grams
    int flight_number; // flight number of the bag
} Bag;

// structure for the conveyor belt
typedef struct {
    int items[MAX_BAGS]; // array to store the bag ids
    int front; // index of the front of the conveyor belt
    int rear; // index of the rear of the conveyor belt
} ConveyorBelt;

// function to initialize the conveyor belt
void initConveyorBelt(ConveyorBelt *cb) {
    cb->front = -1;
    cb->rear = -1;
}

// function to check if the conveyor belt is empty
int isConveyorBeltEmpty(ConveyorBelt *cb) {
    return cb->front == -1;
}

// function to check if the conveyor belt is full
int isConveyorBeltFull(ConveyorBelt *cb) {
    return (cb->rear + 1) % MAX_BAGS == cb->front;
}

// function to add a bag to the conveyor belt
void addToConveyorBelt(ConveyorBelt *cb, int bagID) {
    if (isConveyorBeltFull(cb)) {
        printf("Error: Conveyor belt is full\n");
        return;
    }
    if (isConveyorBeltEmpty(cb)) {
        cb->front = 0;
        cb->rear = 0;
    } else {
        cb->rear = (cb->rear + 1) % MAX_BAGS;
    }
    cb->items[cb->rear] = bagID;
    printf("Bag with ID %d added to conveyor belt\n", bagID);
}

// function to remove a bag from the conveyor belt
void removeFromConveyorBelt(ConveyorBelt *cb, int *bagIDptr) {
    if (isConveyorBeltEmpty(cb)) {
        printf("Error: Conveyor belt is empty\n");
        return;
    }
    *bagIDptr = cb->items[cb->front];
    if (cb->front == cb->rear) {
        cb->front = -1;
        cb->rear = -1;
    } else {
        cb->front = (cb->front + 1) % MAX_BAGS;
    }
    printf("Bag with ID %d removed from conveyor belt\n", *bagIDptr);
}

// main function to simulate the baggage handling system
int main() {

    // seed the random number generator
    srand(time(NULL));

    // initialize the conveyor belt
    ConveyorBelt cb;
    initConveyorBelt(&cb);

    // simulate the arrival of bags
    for (int i = 1; i <= 200; i++) {
        // create a new bag with random weight and flight number
        Bag bag;
        bag.id = i;
        bag.weight = rand() % 5000 + 1000;
        bag.flight_number = rand() % 100 + 100;

        // add the bag to the conveyor belt
        addToConveyorBelt(&cb, bag.id);
    }

    // simulate the processing of bags
    for (int i = 0; i < 200; i++) {
        // remove a bag from the conveyor belt
        int bagID;
        removeFromConveyorBelt(&cb, &bagID);

        // simulate processing time
        int processing_time = rand() % 5 + 1;
        printf("Processing bag with ID %d... (processing time: %d seconds)\n", bagID, processing_time);

        // simulate the transfer of the bag to the plane
        int transfer_time = rand() % 2 + 1;
        printf("Transferring bag with ID %d to flight %d... (transfer time: %d seconds)\n", bagID, rand() % 100 + 100, transfer_time);
    }

    return 0;
}