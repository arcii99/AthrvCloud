//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define NUM_BAGGAGE_CONVEYOR_BELTS 4
#define MAX_BAGGAGE_CAPACITY 10
#define MAX_FLIGHTS_CAPACITY 10

// Function prototypes
void initializeConveyorBelts();
void displayConveyorBelts();
void displayFlights();
void addBaggageToConveyorBelt(int conveyorBeltIndex, int baggage);
void addFlightToQueue(int flightNumber);
void removeBaggageFromConveyorBelt(int conveyorBeltIndex, int baggage);

// Global variables
int conveyorBelts[NUM_BAGGAGE_CONVEYOR_BELTS][MAX_BAGGAGE_CAPACITY];
int conveyorBeltSizes[NUM_BAGGAGE_CONVEYOR_BELTS];
int flights[MAX_FLIGHTS_CAPACITY];
int flightQueueSize;

int main() {
    // Initialize variables
    initializeConveyorBelts();
    flightQueueSize = 0;

    // Main program loop
    while (true) {
        // Display the conveyor belts and flights
        displayConveyorBelts();
        displayFlights();

        // Get user input
        char input;
        printf("Enter command: ");
        scanf(" %c", &input);

        // Process user input
        switch (input) {
            case 'a': {
                // Add baggage to conveyor belt
                int conveyorBeltIndex, baggage;
                printf("Enter conveyor belt index (1-4): ");
                scanf("%d", &conveyorBeltIndex);
                printf("Enter baggage weight: ");
                scanf("%d", &baggage);
                addBaggageToConveyorBelt(conveyorBeltIndex - 1, baggage);
                break;
            }
            case 'f': {
                // Add flight to queue
                int flightNumber;
                printf("Enter flight number: ");
                scanf("%d", &flightNumber);
                addFlightToQueue(flightNumber);
                break;
            }
            case 'r': {
                // Remove baggage from conveyor belt
                int conveyorBeltIndex, baggage;
                printf("Enter conveyor belt index (1-4): ");
                scanf("%d", &conveyorBeltIndex);
                printf("Enter baggage weight: ");
                scanf("%d", &baggage);
                removeBaggageFromConveyorBelt(conveyorBeltIndex - 1, baggage);
                break;
            }
            case 'q': {
                // Quit the program
                printf("Exiting...\n");
                return 0;
            }
            default: {
                // Invalid command
                printf("Invalid command.\n");
                break;
            }
        }
    }
}

// Initializes the conveyor belts to be empty
void initializeConveyorBelts() {
    for (int i = 0; i < NUM_BAGGAGE_CONVEYOR_BELTS; i++) {
        for (int j = 0; j < MAX_BAGGAGE_CAPACITY; j++) {
            conveyorBelts[i][j] = 0;
        }
        conveyorBeltSizes[i] = 0;
    }
}

// Displays the current state of the conveyor belts
void displayConveyorBelts() {
    printf("\nConveyor Belts:\n");
    for (int i = 0; i < NUM_BAGGAGE_CONVEYOR_BELTS; i++) {
        printf("Conveyor Belt #%d: ", i + 1);
        for (int j = 0; j < conveyorBeltSizes[i]; j++) {
            printf("%d ", conveyorBelts[i][j]);
        }
        printf("\n");
    }
}

// Displays the current state of the flight queue
void displayFlights() {
    printf("\nFlights:\n");
    if (flightQueueSize == 0) {
        printf("No flights in queue.\n");
    } else {
        for (int i = 0; i < flightQueueSize; i++) {
            printf("Flight #%d\n", flights[i]);
        }
    }
}

// Adds baggage to the specified conveyor belt
void addBaggageToConveyorBelt(int conveyorBeltIndex, int baggage) {
    if (conveyorBeltSizes[conveyorBeltIndex] == MAX_BAGGAGE_CAPACITY) {
        printf("Conveyor belt is full.\n");
        return;
    }
    conveyorBelts[conveyorBeltIndex][conveyorBeltSizes[conveyorBeltIndex]] = baggage;
    conveyorBeltSizes[conveyorBeltIndex]++;
    printf("Baggage added to conveyor belt #%d.\n", conveyorBeltIndex + 1);
}

// Adds a flight to the end of the flight queue
void addFlightToQueue(int flightNumber) {
    if (flightQueueSize == MAX_FLIGHTS_CAPACITY) {
        printf("Flight queue is full.\n");
        return;
    }
    flights[flightQueueSize] = flightNumber;
    flightQueueSize++;
    printf("Flight #%d added to queue.\n", flightNumber);
}

// Removes baggage from the specified conveyor belt
void removeBaggageFromConveyorBelt(int conveyorBeltIndex, int baggage) {
    bool found = false;
    for (int i = 0; i < conveyorBeltSizes[conveyorBeltIndex]; i++) {
        if (conveyorBelts[conveyorBeltIndex][i] == baggage) {
            for (int j = i; j < conveyorBeltSizes[conveyorBeltIndex] - 1; j++) {
                conveyorBelts[conveyorBeltIndex][j] = conveyorBelts[conveyorBeltIndex][j + 1];
            }
            conveyorBeltSizes[conveyorBeltIndex]--;
            found = true;
            break;
        }
    }
    if (found) {
        printf("Baggage removed from conveyor belt #%d.\n", conveyorBeltIndex + 1);
    } else {
        printf("Baggage not found on conveyor belt #%d.\n", conveyorBeltIndex + 1);
    }
}