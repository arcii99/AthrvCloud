//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Defining the size of the conveyor belt and capacity of the trolleys.
#define CONVEYOR_BELT_SIZE 100
#define TROLLEY_CAPACITY 10

// Struct to define each trolley
typedef struct {
    int id;
    int items;
    int itemsLoaded;
} Trolley;

// Struct to define the conveyor belt
typedef struct {
    Trolley trolleys[CONVEYOR_BELT_SIZE];
    int front;
    int rear;
} ConveyorBelt;

// Function to check if the conveyor belt is full
bool isConveyorBeltFull(ConveyorBelt* conveyorBelt) {
    return ((conveyorBelt->rear + 1) % CONVEYOR_BELT_SIZE == conveyorBelt->front);
}

// Function to check if the conveyor belt is empty
bool isConveyorBeltEmpty(ConveyorBelt* conveyorBelt) {
    return (conveyorBelt->front == conveyorBelt->rear);
}

int main() {
    // Initializing the conveyor belt with empty trolleys
    ConveyorBelt conveyorBelt;
    conveyorBelt.front = 0;
    conveyorBelt.rear = 0;
    for (int i = 0; i < CONVEYOR_BELT_SIZE; i++) {
        conveyorBelt.trolleys[i].id = i+1;
        conveyorBelt.trolleys[i].items = TROLLEY_CAPACITY;
        conveyorBelt.trolleys[i].itemsLoaded = 0;
    }

    // Simulating the bag handling
    int numBags = 53;
    int bagCount = 0;
    while (bagCount < numBags) {
        // Loading bags onto the trolleys
        if (!isConveyorBeltFull(&conveyorBelt)) {
            Trolley* trolley = &conveyorBelt.trolleys[conveyorBelt.rear];
            if (trolley->itemsLoaded < trolley->items) {
                trolley->itemsLoaded++;
                bagCount++;
                printf("Loaded Bag %d onto Trolley %d\n", bagCount, trolley->id);
            }
            else {
                conveyorBelt.rear = (conveyorBelt.rear + 1) % CONVEYOR_BELT_SIZE;
            }
        }
        // Unloading full trolleys
        if (!isConveyorBeltEmpty(&conveyorBelt)) {
            Trolley* trolley = &conveyorBelt.trolleys[conveyorBelt.front];
            if (trolley->itemsLoaded == trolley->items) {
                printf("Unloaded Trolley %d\n", trolley->id);
                trolley->itemsLoaded = 0;
                conveyorBelt.front = (conveyorBelt.front + 1) % CONVEYOR_BELT_SIZE;
            }
            else {
                break;
            }
        }
    }

    return 0;
}