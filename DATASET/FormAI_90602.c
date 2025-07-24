//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define NUM_FLIGHTS 10
#define MAX_BAGS 4
#define MAX_CAPACITY 50
#define MIN_DELAY 3
#define MAX_DELAY 15

// define struct for flights
typedef struct Flight {
    int flightNumber;
    int numBags;
} Flight;

// function declarations
int randomInt(int min, int max);
void createFlights(Flight *flights, int size);
void initializeConveyorBelt(int *conveyorBelt, int size);
int checkConveyorBelt(int *conveyorBelt, int size, int bags);
void addBagsToConveyorBelt(int *conveyorBelt, int size, int bags);
int checkInFlight(Flight flight, int availableSpace);
int loadFlight(int *conveyorBelt, int size, Flight flight);

int main() {
    // seed the random function
    srand((unsigned) time(0));

    // create array of Flight structs
    Flight flights[NUM_FLIGHTS];

    // create the flights
    createFlights(flights, NUM_FLIGHTS);

    // initialize the conveyor belt
    int conveyorBelt[MAX_CAPACITY];
    initializeConveyorBelt(conveyorBelt, MAX_CAPACITY);

    // iterate through flights and add bags to conveyor belt
    for (int i = 0; i < NUM_FLIGHTS; i++) {
        int availableSpace = MAX_CAPACITY - checkConveyorBelt(conveyorBelt, MAX_CAPACITY, flights[i].numBags);

        // check if there is enough space on conveyor belt
        if (availableSpace >= flights[i].numBags) {
            // delay flight
            int delay = randomInt(MIN_DELAY, MAX_DELAY);
            printf("Flight %d has been delayed for %d minutes.\n", flights[i].flightNumber, delay);

            // wait for delay time
            for (int j = 1; j <= delay; j++) {
                printf("Waiting for %d minutes...\n", j);
            }

            printf("Flight %d is loading.\n", flights[i].flightNumber);

            // load the flight
            int loaded = loadFlight(conveyorBelt, MAX_CAPACITY, flights[i]);
            
            if (loaded) {
                printf("Flight %d has been loaded successfully.\n", flights[i].flightNumber);
            } else {
                printf("Flight %d has not been loaded. Not enough space in the cargo hold.\n", flights[i].flightNumber);
            }

        } else {
            printf("Flight %d has not been loaded. Not enough space on the conveyor belt.\n", flights[i].flightNumber);
        }
    }

    return 0;
}

// generate random integer between min and max
int randomInt(int min, int max) {
    return (rand() % (max + 1 - min)) + min;
}

// create the flights
void createFlights(Flight *flights, int size) {
    for (int i = 0; i < size; i++) {
        flights[i].flightNumber = i + 1;
        flights[i].numBags = randomInt(1, MAX_BAGS);
    }
}

// initialize the conveyor belt with 0s
void initializeConveyorBelt(int *conveyorBelt, int size) {
    for (int i = 0; i < size; i++) {
        conveyorBelt[i] = 0;
    }
}

// check if there is enough space on conveyor belt
int checkConveyorBelt(int *conveyorBelt, int size, int bags) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (conveyorBelt[i] == 0) {
            sum++;
        }
    }
    return sum - bags;
}

// add bags to conveyor belt
void addBagsToConveyorBelt(int *conveyorBelt, int size, int bags) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (conveyorBelt[i] == 0) {
            if (count < bags) {
                conveyorBelt[i] = 1;
                count++;
            } else {
                break;
            }
        }
    }
}

// check if flight can fit in cargo hold
int checkInFlight(Flight flight, int availableSpace) {
    if (flight.numBags <= availableSpace) {
        return 1;
    } else {
        return 0;
    }
}

// load the flight
int loadFlight(int *conveyorBelt, int size, Flight flight) {
    int availableSpace = size - flight.numBags;
    if (checkInFlight(flight, availableSpace)) {
        addBagsToConveyorBelt(conveyorBelt, size, flight.numBags);
        return 1;
    } else {
        return 0;
    }
}