//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_PASSENGERS 100
#define MAX_BAGGAGE 2

// Struct for passengers
typedef struct passenger {
    bool hasCheckedIn;
    int numOfBags;
} Passenger;

// Struct for the conveyour belt
typedef struct conveyorbelt {
    int numOfBags;
} ConveyorBelt;

// Enum for the stages of the baggage handling process
typedef enum {
    CHECK_IN,
    SECURITY_CHECK,
    BOARDING_GATE,
    COMPLETE
} Stage;

// Function to simulate the check-in process
void checkIn(Passenger *passenger) {
    printf("Passenger with %d bags has checked in.\n", passenger->numOfBags);
    passenger->hasCheckedIn = true;
}

// Function to simulate the security check process
void securityCheck(Passenger *passenger) {
    printf("Passenger with %d bags has passed security check.\n", passenger->numOfBags);
}

// Function to simulate the boarding gate process
void boardingGate(Passenger *passenger) {
    printf("Passenger with %d bags has boarded the flight.\n", passenger->numOfBags);
}

// Function to simulate the baggage handling process
void baggageHandling(Passenger passengers[], ConveyorBelt *conveyorBelt, Stage *stage) {
    switch(*stage) {
        case CHECK_IN:
            // Iterate through the passengers and check them in
            for(int i = 0; i < MAX_PASSENGERS; i++) {
                if(passengers[i].numOfBags > 0 && !passengers[i].hasCheckedIn) {
                    checkIn(&passengers[i]);
                    conveyorBelt->numOfBags += passengers[i].numOfBags;
                    passengers[i].numOfBags = 0;
                }
            }
            *stage = SECURITY_CHECK;
            break;
        case SECURITY_CHECK:
            // Iterate through the bags on the conveyour belt and pass them through security check
            for(int i = 0; i < conveyorBelt->numOfBags; i++) {
                securityCheck(&passengers[i]);
            }
            *stage = BOARDING_GATE;
            break;
        case BOARDING_GATE:
            // Iterate through the passengers and board them onto the flight
            for(int i = 0; i < MAX_PASSENGERS; i++) {
                if(!passengers[i].hasCheckedIn && passengers[i].numOfBags == 0) {
                    boardingGate(&passengers[i]);
                }
            }
            *stage = COMPLETE;
            break;
        case COMPLETE:
            // Exit the program
            exit(0);
            break;
    }
}

// Function to generate random number of bags for a passenger
int generateNumOfBags() {
    return rand() % (MAX_BAGGAGE + 1);
}

int main() {
    // Initialize the passengers
    Passenger passengers[MAX_PASSENGERS];
    for(int i = 0; i < MAX_PASSENGERS; i++) {
        passengers[i].hasCheckedIn = false;
        passengers[i].numOfBags = generateNumOfBags();
    }
    
    // Initialize the conveyour belt
    ConveyorBelt conveyorBelt;
    conveyorBelt.numOfBags = 0;
    
    // Initialize the stage
    Stage stage = CHECK_IN;
    
    // Loop through the stages of the baggage handling process
    while(true) {
        baggageHandling(passengers, &conveyorBelt, &stage);
        sleep(1); // Pause for 1 second to simulate real-time processing
    }
    
    return 0;
}