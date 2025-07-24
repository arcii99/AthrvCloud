//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define MAX_CAPACITY 30
#define MAX_BAGGAGE 5

// global variables
int conveyorBelt[MAX_CAPACITY];
int securityBelt[MAX_CAPACITY];
int boardingBelt[MAX_CAPACITY];
int conveyorFront = 0;
int securityFront = 0;
int boardingFront = 0;
int conveyorRear = 0;
int securityRear = 0;
int boardingRear = 0;

// functions declarations
void displayBelt(char belt[]);
void push(int item, char belt[]);
int pop(char belt[]);
int isFull(char belt[]);
int isEmpty(char belt[]);
void simulateBaggageHandling();

int main() {
    // seed random number generator
    srand(time(NULL));
    // start simulation
    simulateBaggageHandling();
    return 0;
}

void simulateBaggageHandling() {
    int newBaggage, lostBags = 0, totalBagsPassed = 0, totalBagsLost = 0;
    char nextBelt;
    for (int i = 0; i < 100; i++) {
        // generate new baggage
        newBaggage = (rand() % MAX_BAGGAGE) + 1;
        // check conveyor belt
        if (!isFull("conveyor")) {
            push(newBaggage, "conveyor");
            totalBagsPassed++;
            nextBelt = "security";
        } else {
            // conveyor belt full, check security belt
            if (!isFull("security")) {
                push(pop("conveyor"), "security");
                push(newBaggage, "conveyor");
                totalBagsPassed++;
                nextBelt = "boarding";
            } else {
                // both conveyor and security belts full, baggage lost
                lostBags++;
                totalBagsLost++;
                continue;
            }
        }
        // check security belt
        if (!isEmpty("security")) {
            push(pop("security"), nextBelt);
        }
        // check boarding belt
        if (!isEmpty("boarding")) {
            pop("boarding");
        }
        // display current state of belts
        printf("Iteration %d:\n", i+1);
        printf("Conveyor Belt:\n");
        displayBelt("conveyor");
        printf("Security Belt:\n");
        displayBelt("security");
        printf("Boarding Belt:\n");
        displayBelt("boarding");
    }
    // display final simulation results
    printf("Total Bags Passed: %d\n", totalBagsPassed);
    printf("Bags Lost: %d\n", lostBags);
    printf("Total Bags Lost: %d\n", totalBagsLost);
}

void displayBelt(char belt[]) {
    char *beltPtr;
    if (belt == "conveyor") {
        beltPtr = conveyorBelt;
    } else if (belt == "security") {
        beltPtr = securityBelt;
    } else {
        beltPtr = boardingBelt;
    }
    for (int i = 0; i < MAX_CAPACITY; i++) {
        printf("%d ", *(beltPtr+i));
    }
    printf("\n");
}

void push(int item, char belt[]) {
    if (isFull(belt)) {
        printf("Error: %s belt is full\n", belt);
        exit(-1);
    }
    char *beltPtr;
    int *frontPtr;
    int *rearPtr;
    if (belt == "conveyor") {
        beltPtr = conveyorBelt;
        frontPtr = &conveyorFront;
        rearPtr = &conveyorRear;
    } else if (belt == "security") {
        beltPtr = securityBelt;
        frontPtr = &securityFront;
        rearPtr = &securityRear;
    } else {
        beltPtr = boardingBelt;
        frontPtr = &boardingFront;
        rearPtr = &boardingRear;
    }
    *(beltPtr+*rearPtr) = item;
    (*rearPtr)++;
}

int pop(char belt[]) {
    if (isEmpty(belt)) {
        printf("Error: %s belt is empty\n", belt);
        exit(-1);
    }
    char *beltPtr;
    int *frontPtr;
    int *rearPtr;
    if (belt == "conveyor") {
        beltPtr = conveyorBelt;
        frontPtr = &conveyorFront;
        rearPtr = &conveyorRear;
    } else if (belt == "security") {
        beltPtr = securityBelt;
        frontPtr = &securityFront;
        rearPtr = &securityRear;
    } else {
        beltPtr = boardingBelt;
        frontPtr = &boardingFront;
        rearPtr = &boardingRear;
    }
    (*frontPtr)++;
    return *(beltPtr+(*frontPtr-1));
}

int isFull(char belt[]) {
    char *beltPtr;
    int *frontPtr;
    int *rearPtr;
    if (belt == "conveyor") {
        beltPtr = conveyorBelt;
        frontPtr = &conveyorFront;
        rearPtr = &conveyorRear;
    } else if (belt == "security") {
        beltPtr = securityBelt;
        frontPtr = &securityFront;
        rearPtr = &securityRear;
    } else {
        beltPtr = boardingBelt;
        frontPtr = &boardingFront;
        rearPtr = &boardingRear;
    }
    if ((*rearPtr-*frontPtr) >= MAX_CAPACITY) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(char belt[]) {
    char *beltPtr;
    int *frontPtr;
    int *rearPtr;
    if (belt == "conveyor") {
        beltPtr = conveyorBelt;
        frontPtr = &conveyorFront;
        rearPtr = &conveyorRear;
    } else if (belt == "security") {
        beltPtr = securityBelt;
        frontPtr = &securityFront;
        rearPtr = &securityRear;
    } else {
        beltPtr = boardingBelt;
        frontPtr = &boardingFront;
        rearPtr = &boardingRear;
    }
    if (*frontPtr == *rearPtr) {
        return 1;
    } else {
        return 0;
    }
}