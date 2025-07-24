//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10

struct Elevator {
    int currentFloor;   // The floor the elevator is currently on
    int direction;      // The direction the elevator is moving (1 = going up, -1 = going down, 0 = not moving)
    int targetFloor;    // The floor the elevator is currently heading towards
};

void moveElevator(struct Elevator *elevator);
void goToFloor(struct Elevator *elevator, int floor);
void printStatus(struct Elevator *elevator);

int main() {
    // Seed the random number generator so the elevator can start at a random floor and go to a random floor
    srand(time(NULL));
    
    // Initialize the elevator to start on a random floor between 1 and NUM_FLOORS
    struct Elevator elevator = {
        .currentFloor = rand() % NUM_FLOORS + 1,
        .direction = 0,
        .targetFloor = 0
    };
    
    // Print out the initial status of the elevator
    printStatus(&elevator);
    
    // Keep looping until the user quits the program
    int done = 0;
    while (!done) {
        // Get input from the user
        printf("Enter a floor to go to, or q to quit: ");
        char input[256];
        fgets(input, sizeof(input), stdin);
        
        // Check if the user wants to quit
        if (input[0] == 'q') {
            done = 1;
        } else {
            // Convert the user's input to a floor number
            int floor = atoi(input);
            if (floor < 1 || floor > NUM_FLOORS) {
                printf("Invalid floor number. Please enter a number between 1 and %d.\n", NUM_FLOORS);
            } else {
                // Tell the elevator to go to the specified floor
                goToFloor(&elevator, floor);
                
                // Keep moving the elevator until it reaches the target floor
                while (elevator.currentFloor != elevator.targetFloor) {
                    moveElevator(&elevator);
                    printStatus(&elevator);
                }
            }
        }
    }
    
    return 0;
}

void moveElevator(struct Elevator *elevator) {
    // If the elevator is already at the target floor, there's nothing to do
    if (elevator->currentFloor == elevator->targetFloor) {
        return;
    }
    
    // If the elevator is at the top or bottom of the building, it can only move down or up, respectively
    if (elevator->currentFloor == NUM_FLOORS) {
        elevator->direction = -1;
    } else if (elevator->currentFloor == 1) {
        elevator->direction = 1;
    }
    
    // Move the elevator in the appropriate direction
    elevator->currentFloor += elevator->direction;
}

void goToFloor(struct Elevator *elevator, int floor) {
    // Set the elevator's target floor to the specified floor
    elevator->targetFloor = floor;
    
    // Determine which direction the elevator needs to go
    if (elevator->targetFloor > elevator->currentFloor) {
        elevator->direction = 1;    // Going up
    } else if (elevator->targetFloor < elevator->currentFloor) {
        elevator->direction = -1;   // Going down
    } else {
        elevator->direction = 0;    // Already there
    }
}

void printStatus(struct Elevator *elevator) {
    // Print out the current status of the elevator
    printf("Current Floor: %d | Direction: ", elevator->currentFloor);
    if (elevator->direction == 1) {
        printf("Up | ");
    } else if (elevator->direction == -1) {
        printf("Down | ");
    } else {
        printf("Not Moving | ");
    }
    printf("Target Floor: %d\n", elevator->targetFloor);
}