//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 500 // Maximum number of bags that can be processed
#define MAX_FLIGHTS 10 // Maximum number of flights that can be handled
#define MAX_BAG_WEIGHT 30 // Maximum weight of any bag

typedef struct Baggage {
    int id;
    int weight;
    char destination[10];
    int flightNo;
    int conveyorNo;
    int status; // 0 - not processed, 1 - on conveyor, 2 - on flight, 3 - lost
} Baggage;

typedef struct Conveyor {
    int id;
    int capacity;
    int currentWeight;
    int baggageCount;
    Baggage baggage[MAX_BAGS];
} Conveyor;

typedef struct Flight {
    int id;
    char destination[10];
    int conveyorNo;
    int baggageCount;
    Baggage baggage[MAX_BAGS];
} Flight;

Conveyor conveyors[5]; // Array of 5 conveyors
Flight flights[MAX_FLIGHTS]; // Array of flights

int lostBaggageCount = 0;
int totalBaggageCount = 0;

// Function to generate a random integer between two numbers
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check whether a bag can be added to a conveyor or not
int canAddBagToConveyor(Baggage baggage, Conveyor conveyor) {
    return conveyor.currentWeight + baggage.weight <= conveyor.capacity && conveyor.baggageCount + 1 < MAX_BAGS;
}

// Function to add a bag to a conveyor
void addBagToConveyor(Baggage baggage, Conveyor conveyor) {
    printf("Adding bag with ID %d to conveyor %d\n", baggage.id, conveyor.id);
    conveyor.baggage[conveyor.baggageCount] = baggage;
    conveyor.currentWeight += baggage.weight;
    conveyor.baggageCount++;
}

// Function to remove a bag from a conveyor
void removeBagFromConveyor(Baggage baggage, Conveyor conveyor) {
    printf("Removing bag with ID %d from conveyor %d\n", baggage.id, conveyor.id);
    int i;
    for (i = 0; i < conveyor.baggageCount; i++) {
        if (conveyor.baggage[i].id == baggage.id) {
            conveyor.currentWeight -= baggage.weight;
            conveyor.baggageCount--;
            conveyor.baggage[i] = conveyor.baggage[conveyor.baggageCount];
            conveyor.baggage[conveyor.baggageCount].status = 1;
            break;
        }
    }
}

// Function to check whether a bag can be added to a flight or not
int canAddBagToFlight(Baggage baggage, Flight flight) {
    return flight.baggageCount + 1 < MAX_BAGS && strcmp(baggage.destination, flight.destination) == 0;
}

// Function to add a bag to a flight
void addBagToFlight(Baggage baggage, Flight flight) {
    printf("Adding bag with ID %d to flight %d\n", baggage.id, flight.id);
    flight.baggage[flight.baggageCount] = baggage;
    flight.baggageCount++;
    baggage.status = 2;
}

// Function to randomize baggage and fill the conveyors
void fillConveyors() {
    int i, j;
    for (i = 0; i < 5; i++) {
        conveyors[i].id = i + 1;
        conveyors[i].capacity = getRandomNumber(5000, 10000);
        conveyors[i].currentWeight = 0;
        conveyors[i].baggageCount = 0;
        for (j = 0; j < MAX_BAGS / 5; j++) {
            Baggage baggage;
            baggage.id = totalBaggageCount + 1;
            totalBaggageCount++;
            baggage.weight = getRandomNumber(1, MAX_BAG_WEIGHT);
            sprintf(baggage.destination, "DEST%d", getRandomNumber(1, 5));
            baggage.flightNo = getRandomNumber(1, 10);
            baggage.conveyorNo = i + 1;
            baggage.status = 0;

            if (canAddBagToConveyor(baggage, conveyors[i])) {
                addBagToConveyor(baggage, conveyors[i]);
            } else {
                lostBaggageCount++;
                baggage.status = 3;
                printf("Bag with ID %d was lost\n", baggage.id);
            }
        }
    }
}

// Function to transfer bags from conveyors to flights
void transferBags() {
    int i, j;
    for (i = 0; i < 10; i++) {
        flights[i].id = i + 1;
        sprintf(flights[i].destination, "DEST%d", i % 5 + 1);
        flights[i].conveyorNo = getRandomNumber(1, 5);

        // Find the conveyor for this flight
        Conveyor conveyor = conveyors[flights[i].conveyorNo - 1];

        // Transfer bags from conveyor to flight
        for (j = 0; j < conveyor.baggageCount; j++) {
            if (canAddBagToFlight(conveyor.baggage[j], flights[i])) {
                addBagToFlight(conveyor.baggage[j], flights[i]);
                removeBagFromConveyor(conveyor.baggage[j], conveyor);
                j--;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    fillConveyors(); // Fill the conveyors with bags
    transferBags(); // Transfer bags from conveyors to flights
    printf("Total bags processed: %d\n", totalBaggageCount);
    printf("Number of bags lost: %d\n", lostBaggageCount);
    return 0;
}