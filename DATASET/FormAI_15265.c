//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Max number of bags that can be handled in a flight
#define MAX_BAGS 500

// Max number of conveyor belts in the airport
#define MAX_CONVEYORS 10

// Max number of flights that can be handled by the airport
#define MAX_FLIGHTS 100

// Structure to represent a bag
typedef struct baggage {
    int flightNo; // flight number of bag's destination
    int bagNo; // unique identification number of the bag
    int weight; // weight of the bag in kilograms
} baggage;

// Structure to represent a conveyor belt
typedef struct conveyor {
    int conveyorID; // unique identification number of the conveyor
    int capacity; // maximum weight that can be handled by the conveyor in a minute
    int currentLoad; // current weight on the conveyor
    baggage *bag[MAX_BAGS]; // array of pointers to bags currently on the conveyor
    int noOfBags; // number of bags currently on the conveyor
} conveyor;

// Structure to represent a flight
typedef struct flight {
    int flightNo; // unique identification number of the flight
    int noOfBags; // number of bags in the flight
    baggage *bag[MAX_BAGS]; // array of pointers to bags in the flight
    int conveyorIDs[MAX_CONVEYORS]; // array of conveyor IDs handling the flight's bags
} flight;

// Structure to represent the airport
typedef struct airport {
    int noOfConveyors; // number of available conveyor belts in the airport
    conveyor conveyors[MAX_CONVEYORS]; // array of available conveyor belts
    int noOfFlights; // number of flights currently handled by the airport
    flight flights[MAX_FLIGHTS]; // array of currently handled flights
} airport;

// Function to initialize a conveyor belt
void initConveyor(conveyor *c, int conveyorID, int capacity) {
    c->conveyorID = conveyorID;
    c->capacity = capacity;
    c->currentLoad = 0;
    c->noOfBags = 0;
}

// Function to add a bag to the conveyor
void addBag(conveyor *c, baggage *b) {
    c->bag[c->noOfBags] = b;
    c->currentLoad += b->weight;
    c->noOfBags++;
}

// Function to remove a bag from the conveyor
void removeBag(conveyor *c, int index) {
    baggage *b = c->bag[index];
    c->currentLoad -= b->weight;
    c->noOfBags--;
    for(int i = index; i < c->noOfBags; i++) {
        c->bag[i] = c->bag[i+1];
    }
    c->bag[c->noOfBags] = NULL;
}

// Function to initialize a flight
void initFlight(flight *f, int flightNo) {
    f->flightNo = flightNo;
    f->noOfBags = 0;
    for(int i = 0; i < MAX_CONVEYORS; i++) {
        f->conveyorIDs[i] = -1;
    }
}

// Function to add a bag to a flight
void addBagToFlight(flight *f, baggage *b) {
    f->bag[f->noOfBags] = b;
    f->noOfBags++;
}

// Function to generate random weight for a bag
int generateRandomWeight() {
    return (rand() % 30 + 1); // maximum weight of a bag is 30 kg
}

// Function to generate random flight number
int generateRandomFlightNo() {
    return (rand() % 1000 + 1); // maximum flight number is 1000
}

// Function to simulate the airport baggage handling process
void simulateHandling(airport *a) {
    printf("Starting baggage handling simulation...\n");

    // Add bags to conveyors randomly
    for(int i = 0; i < a->noOfConveyors; i++) {
        conveyor *c = &(a->conveyors[i]);
        for(int j = 0; j < c->noOfBags; j++) {
            if(rand() % 2 == 0) {
                removeBag(c, j);
                j--;
            }
        }
        for(int j = 0; j < c->noOfBags; j++) {
            conveyor *nextConveyor = NULL;
            for(int k = 0; k < a->noOfConveyors; k++) {
                if(a->conveyors[k].conveyorID != c->conveyorID && a->conveyors[k].currentLoad + c->bag[j]->weight <= a->conveyors[k].capacity) {
                    nextConveyor = &(a->conveyors[k]);
                    break;
                }
            }
            if(nextConveyor != NULL) {
                removeBag(c, j);
                addBag(nextConveyor, a->flights[c->bag[j]->flightNo-1].bag[c->bag[j]->bagNo-1]);
                j--;
            }
        }
        if(c->noOfBags > 0) {
            int index = rand() % c->noOfBags;
            a->flights[c->bag[index]->flightNo-1].conveyorIDs[c->conveyorID-1] = -1;
            removeBag(c, index);
        }
    }

    // Add bags to flights randomly
    for(int i = 0; i < a->noOfFlights; i++) {
        flight *f = &(a->flights[i]);
        for(int j = 0; j < MAX_BAGS; j++) {
            if(f->bag[j] != NULL) {
                if(rand() % 2 == 0) {
                    f->conveyorIDs[j] = -1;
                    f->bag[j] = NULL;
                    f->noOfBags--;
                }
            }
        }
        for(int j = f->noOfBags; j < MAX_BAGS; j++) {
            if(rand() % 2 == 0) {
                baggage *b = (baggage *)malloc(sizeof(baggage));
                b->flightNo = f->flightNo;
                b->bagNo = j;
                b->weight = generateRandomWeight();
                f->bag[j] = b;
                f->noOfBags++;
            }
        }
    }

    printf("Baggage handling simulation complete.\n");
}

// Function to print the status of the conveyors
void printConveyorStatus(airport *a) {
    printf("Conveyor belt status:\n");
    for(int i = 0; i < a->noOfConveyors; i++) {
        conveyor *c = &(a->conveyors[i]);
        printf("Conveyor %d: %d kg/%d kg, ", c->conveyorID, c->currentLoad, c->capacity);
        printf("Bags: ");
        for(int j = 0; j < c->noOfBags; j++) {
            printf("%d ", c->bag[j]->bagNo+1);
        }
        printf("\n");
    }
}

// Function to print the status of the flights
void printFlightStatus(airport *a) {
    printf("Flight status:\n");
    for(int i = 0; i < a->noOfFlights; i++) {
        flight *f = &(a->flights[i]);
        printf("Flight %d: %d bags, ", f->flightNo, f->noOfBags);
        printf("Conveyors: ");
        for(int j = 0; j < MAX_CONVEYORS; j++) {
            if(f->conveyorIDs[j] != -1) {
                printf("%d ", f->conveyorIDs[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Initialize the airport
    airport a;
    a.noOfConveyors = 5;
    for(int i = 0; i < a.noOfConveyors; i++) {
        initConveyor(&(a.conveyors[i]), i+1, 20); // Max capacity of each conveyor is 20 kg
    }
    a.noOfFlights = 10;
    for(int i = 0; i < a.noOfFlights; i++) {
        initFlight(&(a.flights[i]), generateRandomFlightNo());
    }

    // Add bags to initial flights
    for(int i = 0; i < a.noOfFlights; i++) {
        flight *f = &(a.flights[i]);
        for(int j = 0; j < MAX_BAGS; j++) {
            if(rand() % 2 == 0) {
                baggage *b = (baggage *)malloc(sizeof(baggage));
                b->flightNo = i;
                b->bagNo = j;
                b->weight = generateRandomWeight();
                addBagToFlight(f, b);
            }
        }
    }

    // Assign conveyors to flights randomly
    for(int i = 0; i < a.noOfFlights; i++) {
        flight *f = &(a.flights[i]);
        for(int j = 0; j < MAX_CONVEYORS; j++) {
            if(rand() % 2 == 0) {
                int k = rand() % a.noOfConveyors;
                while(a.conveyors[k].currentLoad + f->noOfBags*generateRandomWeight() > a.conveyors[k].capacity) {
                    k = rand() % a.noOfConveyors;
                }
                f->conveyorIDs[j] = a.conveyors[k].conveyorID;
                for(int l = 0; l < f->noOfBags; l++) {
                    addBag(&(a.conveyors[k]), f->bag[l]);
                }
            }
        }
    }

    // Print initial status of the airport
    printf("Initial status:\n");
    printConveyorStatus(&a);
    printFlightStatus(&a);

    // Simulate baggage handling
    simulateHandling(&a);

    // Print final status of the airport
    printf("Final status:\n");
    printConveyorStatus(&a);
    printFlightStatus(&a);

    return 0;
}