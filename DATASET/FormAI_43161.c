//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KIOSKS 10
#define MAX_LANES 5
#define MAX_BAGS 100

int luggageCounter, kioskCounter;

struct Luggage {
    int weight;
    int destination;
};

typedef struct Luggage Luggage;

struct Kiosk {
    int id;
    int maxCapacity;
    int currentCapacity;
    Luggage* bags[MAX_BAGS];
};

typedef struct Kiosk Kiosk;

struct Conveyor {
    int id;
    int maxCapacity;
    int currentCapacity;
    Luggage* bags[MAX_BAGS];
};

typedef struct Conveyor Conveyor;

struct Lane {
    int id;
    int maxCapacity;
    int currentCapacity;
    Luggage* bags[MAX_BAGS];
};

typedef struct Lane Lane;

struct BaggageHandlingSystem {
    Kiosk* kiosks[MAX_KIOSKS];
    Conveyor* conveyorBelts[MAX_LANES];
    Lane* lanes[MAX_LANES];
};

typedef struct BaggageHandlingSystem BaggageHandlingSystem;

BaggageHandlingSystem bhSystem;

void initializeSystem() {
    for(int i=0; i<MAX_KIOSKS; i++) {
        bhSystem.kiosks[i] = NULL;
    }
    for(int i=0; i<MAX_LANES; i++) {
        bhSystem.conveyorBelts[i] = NULL;
        bhSystem.lanes[i] = NULL;
    }
}

void addKiosk(int maxCapacity) {
    if(kioskCounter == MAX_KIOSKS) {
        printf("Sorry, no more kiosks can be added.\n");
    } else {
        Kiosk* kiosk = (Kiosk*)malloc(sizeof(Kiosk));
        kiosk->id = kioskCounter;
        kiosk->maxCapacity = maxCapacity;
        kiosk->currentCapacity = 0;
        bhSystem.kiosks[kioskCounter] = kiosk;
        kioskCounter++;
    }
}

void addConveyorBelt(int maxCapacity) {
    if(luggageCounter == MAX_LANES) {
        printf("Sorry, no more conveyor belts can be added.\n");
    } else {
        Conveyor* conveyor = (Conveyor*)malloc(sizeof(Conveyor));
        conveyor->id = luggageCounter;
        conveyor->maxCapacity = maxCapacity;
        conveyor->currentCapacity = 0;
        bhSystem.conveyorBelts[luggageCounter] = conveyor;
        luggageCounter++;
    }
}

void addLane(int maxCapacity) {
    if(luggageCounter == MAX_LANES) {
        printf("Sorry, no more lanes can be added.\n");
    } else {
        Lane* lane = (Lane*)malloc(sizeof(Lane));
        lane->id = luggageCounter;
        lane->maxCapacity = maxCapacity;
        lane->currentCapacity = 0;
        bhSystem.lanes[luggageCounter] = lane;
        luggageCounter++;
    }
}

void addLuggage(int weight, int destination) {
    Luggage* luggage = (Luggage*)malloc(sizeof(Luggage));
    luggage->weight = weight;
    luggage->destination = destination;
    // Assign luggage to the nearest kiosk
    int nearestKiosk = -1;
    int minDistance = MAX_KIOSKS + 1;
    for(int i=0; i<kioskCounter; i++) {
        int distance = abs(destination - bhSystem.kiosks[i]->id);
        if(distance < minDistance) {
            minDistance = distance;
            nearestKiosk = i;
        }
    }
    if(bhSystem.kiosks[nearestKiosk]->currentCapacity == bhSystem.kiosks[nearestKiosk]->maxCapacity) {
        printf("Sorry, the nearest kiosk is full. Please try another one.\n");
    } else {
        bhSystem.kiosks[nearestKiosk]->bags[bhSystem.kiosks[nearestKiosk]->currentCapacity] = luggage;
        bhSystem.kiosks[nearestKiosk]->currentCapacity++;
    }
}

void simulateBaggageHandling() {
    bool isFinished = false;
    // While the system is not empty
    while(!isFinished) {
        // Move bags from kiosks to conveyor belts
        for(int i=0; i<kioskCounter; i++) {
            if(bhSystem.kiosks[i]->currentCapacity > 0) {
                int remainingCapacity = bhSystem.conveyorBelts[i]->maxCapacity - bhSystem.conveyorBelts[i]->currentCapacity;
                if(remainingCapacity > 0) {
                    // Move bags from kiosk to conveyor belt
                    int min = remainingCapacity;
                    if(min > bhSystem.kiosks[i]->currentCapacity) {
                        min = bhSystem.kiosks[i]->currentCapacity;
                    }
                    for(int j=0; j<min; j++) {
                        Luggage* luggage = bhSystem.kiosks[i]->bags[j];
                        bhSystem.conveyorBelts[i]->bags[bhSystem.conveyorBelts[i]->currentCapacity] = luggage;
                        bhSystem.conveyorBelts[i]->currentCapacity++;
                    }
                    bhSystem.kiosks[i]->currentCapacity -= min;
                }
            }
        }
        // Move bags from conveyor belts to lanes
        for(int i=0; i<luggageCounter; i++) {
            if(bhSystem.conveyorBelts[i]->currentCapacity > 0) {
                int remainingCapacity = bhSystem.lanes[i]->maxCapacity - bhSystem.lanes[i]->currentCapacity;
                if(remainingCapacity > 0) {
                    // Move bags from conveyor belt to lane
                    int min = remainingCapacity;
                    if(min > bhSystem.conveyorBelts[i]->currentCapacity) {
                        min = bhSystem.conveyorBelts[i]->currentCapacity;
                    }
                    for(int j=0; j<min; j++) {
                        Luggage* luggage = bhSystem.conveyorBelts[i]->bags[j];
                        bhSystem.lanes[i]->bags[bhSystem.lanes[i]->currentCapacity] = luggage;
                        bhSystem.lanes[i]->currentCapacity++;
                    }
                    bhSystem.conveyorBelts[i]->currentCapacity -= min;
                }
            }
        }
        // Check if all bags have reached their destination
        isFinished = true;
        for(int i=0; i<luggageCounter; i++) {
            if(bhSystem.lanes[i]->currentCapacity > 0) {
                printf("The bags have arrived at lane %d.\n", i);
                isFinished = false;
            }
        }
    }
}

int main() {
    initializeSystem();
    addKiosk(10); // Create kiosk 0 with capacity 10
    addKiosk(5); // Create kiosk 1 with capacity 5
    addConveyorBelt(20); // Create conveyor belt 0 with capacity 20
    addConveyorBelt(15); // Create conveyor belt 1 with capacity 15
    addLane(25); // Create lane 0 with capacity 25
    addLane(30); // Create lane 1 with capacity 30
    // Add luggage to the system
    addLuggage(20, 0); // Add luggage with weight 20 and destination 0
    addLuggage(15, 2); // Add luggage with weight 15 and destination 2
    addLuggage(10, 1); // Add luggage with weight 10 and destination 1
    // Simulate baggage handling
    simulateBaggageHandling();
    return 0;
}